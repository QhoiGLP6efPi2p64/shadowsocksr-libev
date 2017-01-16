/*
 * obfs.h - Define shadowsocksR server's buffers and callbacks
 *
 * Copyright (C) 2015 - 2016, Break Wa11 <mmgac001@gmail.com>
 */

#ifndef _OBFS_H
#define _OBFS_H

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

typedef struct server_info {
    char host[64];
    uint16_t port;
    char *param;
    void *g_data;
    uint8_t *iv;
    size_t iv_len;
    uint8_t *recv_iv;
    size_t recv_iv_len;
    uint8_t *key;
    size_t key_len;
    int head_len;
    size_t tcp_mss;
} server_info_t;

typedef struct obfs {
    server_info_t server;
    void *l_data;
} obfs_t;

typedef struct obfs_class {
    void * (*init_data)();
    obfs_t * (*new_obfs)();
    void (*get_server_info)(obfs_t *self, server_info_t *server);
    void (*set_server_info)(obfs_t *self, server_info_t *server);
    void (*dispose)(obfs_t *self);

    int (*client_pre_encrypt)(obfs_t *self,
            char **pplaindata,
            int datalength,
            size_t* capacity);
    int (*client_encode)(obfs_t *self,
            char **pencryptdata,
            int datalength,
            size_t* capacity);
    int (*client_decode)(obfs_t *self,
            char **pencryptdata,
            int datalength,
            size_t* capacity,
            int *needsendback);
    int (*client_post_decrypt)(obfs_t *self,
            char **pplaindata,
            int datalength,
            size_t* capacity);
    int (*client_udp_pre_encrypt)(obfs_t *self,
            char **pplaindata,
            int datalength,
            size_t* capacity);
    int (*client_udp_post_decrypt)(obfs_t *self,
            char **pplaindata,
            int datalength,
            size_t* capacity);
} obfs_class_t;

obfs_class_t * new_obfs_class(char *plugin_name);
void free_obfs_class(obfs_class_t *plugin);

void set_server_info(obfs_t *self, server_info_t *server);
void get_server_info(obfs_t *self, server_info_t *server);
obfs_t * new_obfs();
void dispose_obfs(obfs_t *self);

#endif // _OBFS_H
