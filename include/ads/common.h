#ifndef COMMON_H
#define COMMON_H

#include <inttypes.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>

#if defined(__linux__)
#include <time.h>
#include <sched.h>
#include <sys/syscall.h>
#endif

#if defined(__APPLE__)
#include <mach/mach_time.h>
#endif



#define DCL_ALIGN __attribute__((aligned (2*CACHE_LINE_SIZE)))
#define CACHELINE  __attribute__((aligned (1*CACHE_LINE_SIZE)))

#define ATPAGESIZE   __attribute__((aligned (PAGESIZE)))

#define SQR(x) (x)*(x)

#define max(a,b)		 \
    ({ __typeof__ (a) _a = (a);	 \
       __typeof__ (b) _b = (b);	 \
       _a > _b ? _a : _b; })


#define min_linden(a,b)		 \
    ({ __typeof__ (a) _a = (a);	 \
       __typeof__ (b) _b = (b);	 \
       _a < _b ? _a : _b; })


typedef struct thread_args_s
{
    pthread_t thread;
    int id;
    unsigned short rng[3];
    int measure;
    int cycles;
    char pad[128];
} thread_args_t;








#define E(c)                                                                    \
    do {                                                                        \
        int _c = (c);                                                           \
	if (_c < 0) {                                                               \
	    fprintf(stderr, "E: %s: %d: %s\n",                                      \
                __FILE__, __LINE__, #c);                                        \
	}                                                                           \
    } while (0)

#define E_en(c)                                                                 \
    do {                                                                        \
        int _c = (c);                                                           \
	if (_c != 0) {                                                              \
	    fprintf(stderr, "%s", strerror(_c));                                    \
	}                                                                           \
    } while (0)

#define E_NULL(c)               \
    do {                        \
	if ((c) == NULL) {			\
	    perror("E_NULL");       \
	}                           \
    } while (0)


#if defined(__x86_64__)
/* accurate time measurements on late recent cpus */
static inline uint64_t __attribute__((always_inline))
read_tsc_p()
{
   uint64_t tsc;
   __asm__ __volatile__ ("rdtscp\n"
	 "shl $32, %%rdx\n"
	 "or %%rdx, %%rax"
	 : "=a"(tsc)
	 :
	 : "%rcx", "%rdx");
   return tsc;
}

/* compiler memory barrier */
#define CMB() __asm__ __volatile__ ("" : : : "memory")

#define IMB()    __asm__ __volatile__("mfence":::"memory")
#define IRMB()   __asm__ __volatile__("lfence":::"memory")
#define IWMB()   __asm__ __volatile__("sfence":::"memory")

#else
#error Unsupported architecture
#endif // __x86_64__


#if defined(__linux__)
extern pid_t gettid(void);
extern void  pin(pid_t t, int cpu);
#endif

void rng_init (unsigned short rng[3]);
extern void gettime(struct timespec *t);
extern struct timespec timediff(struct timespec, struct timespec);


#endif

