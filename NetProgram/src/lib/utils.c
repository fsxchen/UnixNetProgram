#include "unp.h"
#include <stdio.h>
#include <string.h> 
#include <stdarg.h>
  
/* ANSI标准形式的声明方式，括号内的省略号表示可选参数 */    
  
/* ANSI标准形式的声明方式，括号内的省略号表示可选参数 */    
  
void err_quit(const char *fmt, ... )    
{    
	va_list args;         //定义一个va_list类型的变量，用来储存单个参数
    va_start(args, fmt);  //使args指向可变参数的第一个参数

    printf(fmt, *args);   //直接传递给printf

    va_end(args);         //结束可变参数的获取
	exit(2);
}  

  
