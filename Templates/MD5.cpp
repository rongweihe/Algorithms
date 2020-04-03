/*************************************************************************
    > File Name: MD5.cpp
    > Author: herongwei
    > Mail: rongweihe1995@gmail.com
    > Created Time: Fri Apr  3 22:20:46 2020
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#define _GNU_SOURCE /* for getline API */
#include <stdio.h>
using namespace std;

/* OpenSSL md5 API 头文件, 编译时需要连接 crypto 库(-lcrypto) */
#include <openssl/md5.h>

/* ============ OpenSSL md5 API =================
 *① 独立API, 一次性输入要计算的数据,然后得到md5值
 *  unsigned char *MD5(const unsigned char *src, unsigned long src_len, unsigned char *dst);
 *
 *② 系列API, 可以要计算的数据分多次输入,然后得到md5值
 *  int MD5_Init(MD5_CTX *ctx);
 *  int MD5_Update(MD5_CTX *ctx, const void *src, unsigned long src_len);
 *  int MD5_Final(unsigned char *dst, MD5_CTX *ctx);
 *
 * Note : API输出md5值的长度为 MD5_DIGEST_LENGTH(16个字节), 
 *        通常我们看到的md5sum等工具计算的md5值是32个字节,
 *        这是因为 API输出的md5值是hex编码.
 *
 */

#define md5_calc_data MD5

/* 计算文件的md5 */
unsigned char* md5_calc_file(const char* path, unsigned char *dst) {
    FILE* fp = NULL;
  
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    MD5_CTX ctx;
    
    fp = fopen(path, "rb");
    if (NULL == fp) {
        return NULL;
    }
    
    MD5_Init(&ctx);
    
    while ((read = getline(&line, &len, fp)) != -1) {
        MD5_Update(&ctx, line, read);
    }
    free(line);
    MD5_Final(dst, &ctx);
    
    return dst;
}


/:* 将hex编码的MD5转换成字符串 */
char* md5_hex2str(unsigned char* in_md5_hex, char* out_md5_str) {
    int i = 0;

    for (i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        sprintf(out_md5_str + i * 2, "%.2x", in_md5_hex[i]);
    }
    out_md5_str[MD5_DIGEST_LENGTH * 2] = '\0';

    return out_md5_str;
}

int main(void) {
    char md5_hex[MD5_DIGEST_LENGTH]; /* len = 16 */
    char md5_str[MD5_DIGEST_LENGTH * 2 + 1]; /* len = 33 */

    md5_calc_data("hello world", sizeof("hello world")-1, md5_hex);
    md5_hex2str(md5_hex, md5_str);
    printf("[date md5]%s\n", md5_str);

    md5_calc_file("/etc/passwd", md5_hex);
    md5_hex2str(md5_hex, md5_str);
    printf("[file md5]%s\n", md5_str);

    return 0;
}
