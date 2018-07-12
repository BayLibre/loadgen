#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "syscalls.h"

const char *file_name = "/dev/null";

int do_syscalls(int count)
{
	int fd;
	int ret;
	int buf[1];

	fd = open(file_name, O_RDWR | O_NONBLOCK);
	if (fd < 0) {
		fprintf(stderr, "open %s failed, %s\n", strerror(errno), file_name);
		return -errno;
	}
	while (count--) {
		ret = read(fd, buf, sizeof(buf));
		if (ret < 0) {
			fprintf(stderr, "read %s failed, %s\n", strerror(errno), file_name);
			break;
		}

		buf[0] = syscall(SYS_gettid);

		ret = write(fd, buf, sizeof(buf));
		if (ret < 0) {
			fprintf(stderr, "write %s failed, %s\n", strerror(errno), file_name);
			break;
		}
	}
	close(fd);
	return ret;
}
