#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_LINES 1024
#define DEF_CHARS 256

#define okay(msg, ...) printf("[+] " msg "\n", ##__VA_ARGS__)
#define warn(msg, ...) printf("[!] " msg "\n", ##__VA_ARGS__)
#define info(msg, ...) printf("[?] " msg "\n", ##__VA_ARGS__)



