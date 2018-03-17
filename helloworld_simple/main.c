/**
编译链接、内存布局演示代码(简单版本)。
测试：ubuntu 16.04 64bit (gcc 5.4.0)
(注：64bit系统上，指针长度为8字节)
*/
#include <stdio.h>
#include "foobar.h"

int main(int argc, char* argv[])
{
    foobar(42);
    
    return 0;
}