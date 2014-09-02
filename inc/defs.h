#ifndef _DEFS_H
#define _DEFS_H

#include <stdint.h>

// define function return value macro
#define R_ERROR -1
#undef R_OK
#define R_OK 0

// typedef some data type for global use
// use C99 <stdint.h>
/*
typedef signed char         int8_t;
typedef unsigned char       uint8_t;

typedef signed short        int16_t;
typedef unsigned short      uint16_t;

typedef signed int          int32_t;
typedef unsigned int        uint32_t;

typedef signed long long    int64_t;
typedef unsigned long long  uint64_t;
*/

#define  MAX(a,b)    (((a)>(b))?(a):(b))
#define  MIN(a,b)    (((a)<(b))?(a):(b))

#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

#define _perror() printf("%s : args error.\n", __func__)
#define dprintf(msg...) do{printf("%s[%d] : ", __func__, __LINE__);printf(msg);}while(0)

#define LOG(level, format, ...) \
    do { \
        fprintf(stderr, "[%s|%s@%s,%d] " format "\n", \
            level, __func__, __FILE__, __LINE__, ##__VA_ARGS__ ); \
    } while (0)


#endif
