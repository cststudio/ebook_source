/**
编译链接、内存布局演示代码。
测试：ubuntu 16.04 64bit (gcc 5.4.0)
(注：64bit系统上，指针长度为8字节)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foobar.h"

int g_main = 100; // 全局初始化变量
int g_main_bss;   // 全局未初始化变量
static int g_main_static; // 全局静态变量
static int g_main_static1;

int main(int argc, char* argv[])
{
    int i = 0;
    for (i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s ptr: %p\n", i, argv[i], argv[i]);
    }
    
    int l_main = 250; // 局部初始化变量
	int l_main1 = 251; // 在内存分布上，l_main1紧挨l_main
    int l_main_bss;   // 局部未初始化变量
    static int l_main_static; // 局部静态变量
	static int l_main_static1;
    char bar_buf[32]; // 栈内存
    char* bar_ptr; // char型指针
    char* hello="hello world"; // 字符串常量
    bar_ptr = (char*)malloc(strlen(hello) + 1); // 分配堆内存指针
    if (bar_ptr == NULL)
        return -1;
        
    strcpy(bar_ptr, hello);
    strcpy(bar_buf, hello); printf("sizeof(int): %d sizeof(char*): %d\n", sizeof(int), sizeof(char*));
    printf("main() ptr: %p &main() ptr: %p\n", main, &main);
    printf("g_main ptr: %p g_main_bss ptr: %p g_main_static ptr: %p g_main_static1 ptr: %p\n",
            &g_main, &g_main_bss, &g_main_static, &g_main_static1);
    printf("l_main ptr: %p l_main1 ptr: %p l_main_bss ptr: %p l_main_static ptr: %p l_main_static1 ptr: %p\n",
            &l_main, &l_main1, &l_main_bss, &l_main_static, &l_main_static1);
    printf("bar_buf ptr: %p bar_buf: %s\n", bar_buf, bar_buf);
    printf("hello ptr: %p bar ptr: %p bar: %s\n", hello, &bar_ptr, bar_ptr);
    free(bar_ptr);
    
    printf("=====================================\n");
    foobar();
    
    return 0;
}