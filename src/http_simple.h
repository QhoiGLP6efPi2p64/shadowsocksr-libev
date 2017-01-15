/*
 * http_simple.h - Define shadowsocksR server's buffers and callbacks
 *
 * Copyright (C) 2015 - 2016, Break Wa11 <mmgac001@gmail.com>
 */

#ifndef _HTTP_SIMPLE_H
#define _HTTP_SIMPLE_H

obfs_t * http_simple_new_obfs();
void http_simple_dispose(obfs_t *self);

int http_simple_client_encode(obfs_t *self, char **pencryptdata, int datalength, size_t* capacity);
int http_simple_client_decode(obfs_t *self, char **pencryptdata, int datalength, size_t* capacity, int *needsendback);

int http_post_client_encode(obfs_t *self, char **pencryptdata, int datalength, size_t* capacity);

#endif // _HTTP_SIMPLE_H
