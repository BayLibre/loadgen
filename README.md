# loadgen: generate different cpu loads and calculate # iterations
Usage: ./loadgen
  -i iterations (default 10000)
  -l loops (default 1)
  -s sleep in ms between loops (default 0)
  -m multithreads (default 1)
  -t tests bitmask (crc32 1, nqueens 2, md5 4, blowfish 8, dhrystone 16, linpack 32, syscall 64)
  -h help
