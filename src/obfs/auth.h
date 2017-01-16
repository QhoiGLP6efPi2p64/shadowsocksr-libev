/*
 * auth.h - Define shadowsocksR server's buffers and callbacks
 */

#ifndef _AUTH_H
#define _AUTH_H

void * auth_simple_init_data();

obfs_t * auth_simple_new_obfs();
obfs_t * auth_aes128_md5_new_obfs();
obfs_t * auth_aes128_sha1_new_obfs();

void auth_simple_dispose(obfs_t *self);

int auth_simple_client_pre_encrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);
int auth_sha1_client_pre_encrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);
int auth_sha1_v2_client_pre_encrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);
int auth_sha1_v4_client_pre_encrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);
int auth_aes128_sha1_client_pre_encrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);
int auth_aes128_sha1_client_udp_pre_encrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);

int auth_simple_client_post_decrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);
int auth_sha1_client_post_decrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);
int auth_sha1_v2_client_post_decrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);
int auth_sha1_v4_client_post_decrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);
int auth_aes128_sha1_client_post_decrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);
int auth_aes128_sha1_client_udp_post_decrypt(obfs_t *self, char **pplaindata, int datalength, size_t *capacity);


#endif // _AUTH_H
