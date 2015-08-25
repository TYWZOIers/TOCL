/*TYWZ OIer's Code Library
* Copyright(C) 2015
* Written by Taiyuan No. 5 Junior/Senior High School Students
* >>> heap.h <<<
* including algorithm about binary-heap
* 包括二叉堆和二叉堆的相关算法
*/

#pragma once
#include "basic.h"


namespace TOCL{

/*类名 heap (小根堆)
* 函数 push(T), pop(), top()
* 可以重载 "<" 使其成为大根堆或实现自定义数据类型
*/

template <typename T>
class heap {
        private:
        T *h;
        int heap_size;
        int topp;
        /*堆顶指针*/
        public:
		/*构造/析构函数*/
        heap(int size){
                /*必须指定堆的大小*/
                heap_size = size;
                topp = 0;
                h = new T[size+1];
        }
        ~heap() {
                delete[] h;
                /*删除堆*/
        }
        /*成员函数*/
        /*
        * 函数名 heap::push(插入堆)
        * O(logn)
        * 将 data 插入小根堆
        */
        void push (T data) 
        {
                h[++topp] = data;
                int now = topp;
                /*当前元素指针*/
                int next = half(now);
                /*当前元素的父节点*/
                while (now > 1) {
                        next = half (now);
                        /*定理 堆中节点i的左右孩子编号为2i,2i+1, 父节点编号为i/2*/
                        if (h[now] < h[next]) {
                                swap (h[now], h[next]);
                                now = next;
                        /*交换*/
                        } else {
                                return;
                        /*否则插入完成，结束*/
                        }
                }
        }
        
        /*
        * 函数名 heap::pop(返回堆顶元素并删除)
        * O(logn)
        */
        T pop () 
        {
                T res = h[1];
                h[1] = h[topp--];
                int now = 1;
                /*当前元素指针*/
                int next = twice(now);
                /*当前元素的左孩子节点*/
                while (twice(now) <= topp) {
                        next = twice (now);
                        /*见push解释*/
                        if (next < topp && h[next+1] < h[next]) 
                                next ++;
                        /*选择较小的孩子*/
                        if (h[now] < h[next] || h[now] == h[next])
                                return res;
                        swap (h[now], h[next]);
                        /*交换*/
                        now = next;
                }
                return res;
        }
        
        /*
        * 函数名 heap::top(返回堆顶元素)
        * O(1)
        */
        T top () 
        {
                return h[1];
        }

};

/*以上为类heap的定义部分*/


/*函数声明*/
template <typename T> void heap_sort (T[], int, int);
/*堆排序*/

/*函数定义*/

/*
* 函数名 heap_sort(堆排序)
* O(nlog2n)
* 参数说明 array:待排序数组, begin:排序起点, end:排序终点
* 请重载"<"以自定义数据类型排序或降序排序
* 详见冒泡排序前的注释
*/
template <typename T> 
void heap_sort (T array[], int begin, int end)
{
        heap<T> h (end - begin + 1);
        /*建立一个堆*/
        for (int i = begin; i <= end; i++)
                h.push (array[i]);
        /*通过push建小根堆*/
        for (int i = begin; i <= end; i++) 
                array[i] = h.pop();
                /*逐个取出*/
}

}
