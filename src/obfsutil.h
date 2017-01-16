/*
 * obfsutil.h - Helper routines for obfuscation module
 */


#ifndef _OBFSUTIL_H
#define _OBFSUTIL_H

#include <stdint.h>

#define OBFS_HMAC_SHA1_LEN 10

int get_head_size(char *plaindata, int size, int def_size);
int rand_bytes(uint8_t *output, int len);
void init_shift128plus(void);
uint64_t xorshift128plus(void);

#endif // _OBFSUTIL_H
