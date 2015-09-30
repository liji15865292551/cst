/* +FHDR-----------------------------------------------------------------------
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * Freescale Semiconductor Confidential Proprietary
 * ----------------------------------------------------------------------------
 * FILE NAME :  sha256.h
 * DEPARTMENT : Security Technology Center (STC), NCSG
 * AUTHOR :     Tom Tkacik (rp0624)
 * ----------------------------------------------------------------------------
 * REVIEW(S) :
 * ----------------------------------------------------------------------------
 * RELEASE HISTORY
 * VERSION   DATE         AUTHOR      DESCRIPTION
 * 0.0.1     2014-01-15   T. Tkacik   Initial version
 * 0.0.2     2014-01-28   T. Tkacik   Initial version
 * ----------------------------------------------------------------------------
 * KEYWORDS : hash, sha256
 * ----------------------------------------------------------------------------
 * PURPOSE: Provide an API to the sha256 hash function
 * ----------------------------------------------------------------------------
 * REUSE ISSUES
 *
 * -FHDR-----------------------------------------------------------------------
 */

#ifndef _SHA256_H_
#define _SHA256_H_

#include <stdint.h>

/*
 * The context for a SHA-256 hash function
 */
typedef struct {
    uint8_t  data[64];
    uint32_t datalen;
    uint64_t bitlen;
    uint32_t H[8];
} SHA256_CTX;

/*
 * SHA256 function declarations
 */
void sha256_init      (SHA256_CTX* context);
void sha256_transform (SHA256_CTX* context);
void sha256_update    (SHA256_CTX* context, const uint8_t* data, uint32_t length);
int  sha256_update_hex(SHA256_CTX* context, const char* hex,  uint32_t length);
void sha256_finalize  (SHA256_CTX* context, uint8_t* hash_bytes);

void sha256     (const uint8_t* data, uint32_t length, uint8_t* hash_bytes);
int  sha256_hex (const char* hex,  uint32_t length, char* hash_string);

/*
 * Self-test functions and declarations
 */
typedef struct sha_msg_test {
    uint32_t Bitlen;  /* Bit length of the test messasge */
    const char *Msg;  /* Test message as a hex string */
    const char *MD;   /* Resulting message digest, as a hex string */
} sha_msg_test;

extern const sha_msg_test sha_long[];
extern const int sha_long_count;

extern const sha_msg_test sha_short[];
extern const int sha_short_count;

extern const char* sha_monte_seed;
extern const char* sha_monte[];
extern const int sha_monte_count;

int  sha256_testMsg(const sha_msg_test* x, int count);
int  sha256_ShortMsg();
int  sha256_LongMsg();
int  sha256_Monte();

/*
 * Utility functions
 */
int  hex_to_bytes (const char* in, uint32_t inlen, uint8_t* out, uint32_t outlen);
int  bytes_to_hex (const uint8_t* in, uint32_t inlen, char* out, uint32_t outlen);

#endif  /* _SHA256_H_ */
