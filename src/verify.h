/*
 * verify.h - Define shadowsocksR server's buffers and callbacks
 *
 * Copyright (C) 2015 - 2016, Break Wa11 <mmgac001@gmail.com>
 */

#ifndef _VERIFY_H
#define _VERIFY_H

obfs_t * verify_simple_new_obfs();
void verify_simple_dispose(obfs_t *self);

int verify_simple_client_pre_encrypt(obfs_t *self, char **pplaindata, int datalength, size_t* capacity);
int verify_simple_client_post_decrypt(obfs_t *self, char **pplaindata, int datalength, size_t* capacity);

#endif // _VERIFY_H
