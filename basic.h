/*TYWZ OIer's Code Library
* Copyright(C) 2015
* Written by Taiyuan No. 5 Junior/Senior High School Students
* >>> sort.h <<<
* including basic defines and functions
* 包括基本
*/

/*宏
* half(x)，返回x/2
* twice(x)，返回2*x
*/

#pragma once

#define half(X) (X>>1)
#define twice(X) (X<<1)

/*>>>函数声明<<<*/
template <typename T> void swap (T&, T&);
/*交换*/

/*>>>函数定义<<<*/

/*
* 函数名 swap(交换)
* O(1)
* 参数说明 a,b 交换的数
*/
template <typename T>
void swap (T& a, T& b)
{
        T temp = a;
        a = b;
        b = temp;
}

