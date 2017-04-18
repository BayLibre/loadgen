#include <stdint.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define __USE_GNU
#include <pthread.h>

#include "crc32.h"
#include "nqueens.h"
#include "md5.h"
#include "blowfish.h"
#include "dhrystone.h"
#include "linpack.h"

#define CRC32_TEST	(1<<0)
#define NQUEENS_TEST	(1<<1)
#define MD5_TEST	(1<<2)
#define BLOWFISH_TEST	(1<<3)
#define DHRYSTONE_TEST	(1<<4)
#define LINPACK_TEST	(1<<5)

static double diff_time(struct timespec *start, struct timespec *end)
{
	return (end->tv_sec-start->tv_sec) + (end->tv_nsec-start->tv_nsec)/1000000000.0;
}

struct context {
	pthread_t tid;
	/* parameters */
	int iterations;
	int loops;
	int sleep_in_ms;
	int tests;
	
	union {
		/* random data */
		unsigned char data[8192];
		int board[8];
		void *mempool[ARSIZE*ARSIZE*sizeof(REAL) + ARSIZE*sizeof(REAL) + ARSIZE*sizeof(int)];
	} u;
	
	/* results */
	unsigned int crc;
	unsigned char checksum[16];
};

static void inline md5_step(unsigned char *data, int srclen, unsigned char *checksum)
{
    struct MD5Context ctx;
    
    MD5Init(&ctx);
    MD5Update(&ctx, data, srclen);
    MD5Final(checksum, &ctx);
}

static inline void blowfish(unsigned char *data, int srclen)
{
	BLOWFISH_CTX ctx;
	unsigned long L, R;

	L = 0xBEBACAFE;
	R = 0xDEADBEEF;

	Blowfish_Init(&ctx, data, srclen);
	Blowfish_Encrypt(&ctx, &L, &R);
	Blowfish_Decrypt(&ctx, &L, &R);
}
    
static void *iterate(void *arg) 
{
	struct context *context = arg;
	int i, j;
	unsigned int crc;

	for (i=0; i < context->loops; i++) {
		if (context->sleep_in_ms) {
			__useconds_t usec = context->sleep_in_ms * 1000;
			usec = random() % usec;
			usleep(usec*2);
		} else {
			usleep(0);
		}
		for (j=0; j < context->iterations; j++) {
			if (context->tests & CRC32_TEST)
				context->crc = crc32(context->u.data, 1200);
			if (context->tests & NQUEENS_TEST)
				nqueens(0, 6, context->u.board);
			if (context->tests & MD5_TEST)
				md5_step(context->u.data, 5000, context->checksum);
			if (context->tests & BLOWFISH_TEST)
				blowfish(context->u.data, 16);
			if (context->tests & DHRYSTONE_TEST)
				dhryStone(800);
			if (context->tests & LINPACK_TEST)
				linpack(1, ARSIZE, context->u.mempool);
		}
	}
	return NULL;
}

static void start_load(struct context *context, const char *name) 
{
	pthread_create(&context->tid, NULL, iterate,(void *)context);
	pthread_setname_np(context->tid, name);
}

static void stop_load(struct context *context) 
{
	void *retval;

	pthread_join(context->tid, &retval);
}

struct context contexts[MULTITHREAD];

int main (int argc, char **argv)
{
	int c;
	int iterations=10000;
	int loops=1;
	int sleep_in_ms=0;
	int multithread=1;
	int i,j;
	char buf[16];
	struct timespec start, end;
	double elapsed;
	int tests = 0xFF;

	opterr = 0;
	while ((c = getopt (argc, argv, "i:m:l:s:t:")) != -1) {
		switch (c) {
		case 'i':
			iterations = atoi(optarg);
			break;	
		case 'm':
			multithread = atoi(optarg);
			if (multithread > MULTITHREAD)
				multithread = MULTITHREAD;
			break;	
		case 'l':
			loops = atoi(optarg);
			break;	
		case 's':
			sleep_in_ms = atoi(optarg);
			break;	
		case 't':
			tests = atoi(optarg);
			break;	
		}
	}

	printf("iterations %d, threads %d, loops %d, sleep %dms\n", 
	       iterations, multithread, loops, sleep_in_ms);
	printf("%s%s%s%s%s%s\n",
	     tests & CRC32_TEST ? "crc32 " : "",   
	     tests & NQUEENS_TEST ? "nqueens " : "",   
	     tests & MD5_TEST ? "md5 " : "",   
	     tests & BLOWFISH_TEST ? "blowfish " : "",  
	     tests & DHRYSTONE_TEST ? "dhrystone " : "",   
	     tests & LINPACK_TEST ? "linpack " : "");   
	
	srandom(time(NULL));

	clock_gettime(CLOCK_REALTIME, &start);

	for (i=0 ; i < multithread; i++) {
		contexts[i].iterations = iterations;
		contexts[i].loops = loops;
		contexts[i].sleep_in_ms = sleep_in_ms;
		contexts[i].tests = tests;
		for (j=0; j < sizeof(contexts[i].u.data); j++)
			contexts[i].u.data[j] = random();
	}
	if (multithread > 1) {
		for (i=0 ; i < multithread; i++) {
			snprintf(buf, sizeof(buf)-1, "%s-%d", argv[0], i);
			start_load(&contexts[i], buf);
		}
		for (i=0 ; i < multithread; i++) {
			stop_load(&contexts[i]);
		}
	} else {
		iterate(&contexts[0]);
	}
	clock_gettime(CLOCK_REALTIME, &end);
	elapsed = diff_time(&start, &end);

	printf("elapsed (secs): %10.3f\n",elapsed);
	if (elapsed > 0)
		printf("iterations/sec: %12.1f\n",(multithread*iterations*loops) / elapsed);

	return 0;
}