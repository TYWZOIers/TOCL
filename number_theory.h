/*TYWZ OIer's Code Library
* Copyright(C) 2015
* Written by Taiyuan No. 5 Junior/Senior High School Students
* >>> number_theory.h <<<
* including useful algorithm of number theory
* 包括数论相关的算法
*/

#pragma once
#include <cmath>

namespace TOCL {

/*>>>函数声明<<<*/ 
int gcd (int, int);
/*最大公约数*/
void extend_gcd(int, int, int&, int&);
/*扩展欧几里德*/
bool is_prime (int);
/*判断是否为素数*/
int get_prime (int, int[]);
/*筛法求素数*/

/*>>>函数定义<<<*/


/*
* 函数名 gcd(求最大公约数)
* O(logn)
* 作用 返回a, b的最大公约数
* 参数说明 a,b操作数
*/
int gcd (int a, int b) 
{
        /*根据朴素欧几里德算法gcd(a,b) = gcd (b, a mod b)*/
        return b == 0 ? a : gcd (b, a%b);
}

/*
* 函数名 extend_gcd(扩展欧几里得算法)
* O(logn)
* 作用 将传入的x, y写为 ax + by = c ( c ≡ 0 (mod gcd(a,b)) 且 a > b) 的特殊解
* 参数说明 a,b操作数,x,y接受结果
*/
void extend_gcd(int a, int b, int& x, int& y) 
{
        if (b == 0) {
		        /*若b=0,必有x=1,y=0*/
		        x = 1;
                y = 0;
                return;
		}
        extend_gcd (b, a%b, x, y);
		/*相当于朴素欧几里德算法*/
		int t = x;
		x = y;
		y = t - a/b*y;
}

/*
* 函数名 is_prime(判断是否为素数)
* O(sqrt(n))
* 若a为素数, 返回true, 否则返回false
* 参数说明 a操作数
*/
bool is_prime (int a) 
{
        if (a <= 1)
                return false;
        /*1不是素数*/
        for (int i = 2; i <= sqrt (a); i++)
                if (a % i == 0)
                        return false;
                        /*试除法*/
        return true;
        /*否则一定为素数*/
}

/*
* 函数名 get_prime(筛法求素数)
* O(n loglog n)
* 将 <= n 的素数存入数组get, 返回素数个数(n >= 2)
*/
int get_prime (int n, int get[]) 
{
        int *temp = new int[n+1];
        int k = 0;
        for (int i = 1; i <= n; i++)
                temp[i] = i + 1;
        /*1不是素数，不必存入*/
        for (int i = 1; i <= n; i++){
                if (temp[i] != 0){
                        /*不为0则是素数*/
                        get[k++] = temp[i];
                        for (int j = i+1; j <= n; j++) 
                                if (temp[j] % temp[i] == 0)
                                        temp[j] = 0;
                                        /*筛除所有倍数*/
                }
        }
        return k-1;
}

}
