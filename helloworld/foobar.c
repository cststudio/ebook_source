#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foobar.h"

int g_foo = 100; // 全局初始化变量
int g_foo_bss;   // 全局未初始化变量
static int g_foo_static; // 全局静态变量

int foobar(void)
{
    int l_foo = 250; // 局部初始化变量
    int l_foo_bss;   // 局部未初始化变量
    static int l_foo_static; // 局部静态变量
    char bar_buf[32]; // 栈内存
    char* bar_ptr; // char型指针
    char* hello="hello world"; // 字符串常量
    bar_ptr = (char*)malloc(strlen(hello) + 1); // 分配堆内存指针
    if (bar_ptr == NULL)
        return -1;
        
    strcpy(bar_ptr, hello);
    strcpy(bar_buf, hello);

    printf("foobar ptr: %p &foobar ptr: %p\n", foobar, &foobar);
    printf("g_foo ptr: %p g_foo_bss ptr: %p g_foo_static ptr: %p\n",
            &g_foo, &g_foo_bss, &g_foo_static);
    printf("l_foo ptr: %p l_foo_bss ptr: %p l_foo_static ptr: %p\n",
            &l_foo, &l_foo_bss, &l_foo_static);
    
    printf("bar_buf ptr: %p bar_buf: %s\n", bar_buf, bar_buf);
    printf("hello ptr: %p bar ptr: %p bar: %s\n", hello, &bar_ptr, bar_ptr);
    
    
    free(bar_ptr);
    
    return 0;
}