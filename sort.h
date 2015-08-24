/*TYWZ OIer's Code Library
* Copyright(C) 2015
* Written by Taiyuan No. 5 Junior/Senior High School Students
* >>> sort.h <<<
* including proper sort algorithm
* 包括常用排序和排序相关的算法
*/


namespace TOCL {

/*>>>函数声明<<<*/
template <typename T> void swap (T&, T&);
/*交换*/
template <typename T> void quick_sort (T[], int, int);
/*快排*/
template <typename T> void binary_merge (T[], int,  int, int);
/*二路归并*/
template <typename T> int merge_sort (T[], int, int);

/*二路归并排序*/
void bucket_sort(unsigned int[], int, int);
/*桶排序*/

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

/*
* 函数名 quick_sort(快速排序)
* O(nlogn)
* 参数说明 array:待排序数组, begin:排序起点, end:排序终点
* 请重载"<"以自定义数据类型排序或降序排序
* 例如
* struct data {
*         int d;
*         friend bool operator < (data a, data b) {
*                 return a.d > b.d;
*                 //降序排序
*         }
* }
*/

template <typename T>
void quick_sort (T array[], int begin, int end) 
{
        int mid = array[(begin >> 1) + (end >> 1)];
        /*取中点*/
        int i = begin, j = end;
        /*i为左侧指针,j为右侧指针*/
        while (i <= j) {
                while (array[i] < mid)
                        i++;
                /*左边找比中点大的*/
                while (mid < array[j])
                        j--;
                /*右边找比中点小的*/
                if (i <= j) {
                        swap (array[i], array[j]);
                        i++, j--;
                }
                /*交换*/
        }
        if (i < end) 
                quick_sort (array, i, end);
        if (j > begin)
                quick_sort (array, begin, j);
        /*递归排序左右边界*/
}

/*
* 函数名 binary_merge(有序表二路归并)
* O(n)
* 作用 将有序表array[begin,mid],array[mid+1,end]合并,使其有序
* 参数说明 array:待合并数组, begin:合并左序列起点, mid:合并中点, end:合并右序列终点
* 请重载"<"以自定义数据合并或降序数列合并
*/

template <typename T>
void binary_merge (T array[], int begin,  int mid, int end) 
{
        T *temp = new T[end - begin + 1]; /*临时数组*/
        int k = 0; /*临时数组指针*/
        int i = begin, j = mid + 1; /*i, j 为左右区间指针*/
        while (i <= mid && j <= end) {
                if (array[i] == array[j])
                        temp[k++] = array[i++];
                if (array[i] < array[j]) 
                        temp[k++] = array[i++];
                else {
                        temp[k++] = array[j++];
                }
                /*放入临时数组*/
        }
        while (i <= mid) 
                temp[k++] = array[i++];
        /*复制左区间剩余*/
        while (j <= end)
                temp[k++] = array[j++];
        /*复制右区间剩余*/
        for (int i = begin, j = 0; i <= end; i++) 
                array[i] = temp[j++];
        /*放回原数组*/
        delete[] temp;
}

/*
* 函数名 merge_sort(二路归并排序并求逆序对)
* 作用 二路归并排序无序数列
* O(nlogn)
* 参数说明 array:待排序数组, begin:排序起点, end:排序终点
* 请重载"<"以自定义数据类型排序或降序排序
* 返回逆序对个数
*/

template <typename T>
int merge_sort (T array[], int begin, int end) 
{
        int inversions = 0; 
        /*返回逆序对个数*/
        /*只有一个元素不必排序*/
        if (begin == end) 
                return 0;
        int mid = ((begin >> 1) + (end >> 1));
        /*中点*/
        inversions += merge_sort (array, begin, mid);
        inversions += merge_sort (array, mid + 1, end);
        /*递归排序左右区间*/
        T *temp = new T[end - begin + 1]; /*临时数组*/
        int k = 0; /*临时数组指针*/
        int i = begin, j = mid + 1; /*i, j 为左右区间指针*/
        while (i <= mid && j <= end) {
                if (array[i] == array[j])
                        temp[k++] = array[i++];
                if (array[i] < array[j]) 
                        temp[k++] = array[i++];
                else {
                        temp[k++] = array[j++];
                        inversions += mid - i + 1;
                        /* 求逆序对 */
                }
                /*放入临时数组*/
        }
        while (i <= mid) 
                temp[k++] = array[i++];
        /*复制左区间剩余*/
        while (j <= end)
                temp[k++] = array[j++];
        /*复制右区间剩余*/
        for (int i = begin, j = 0; i <= end; i++) 
                array[i] = temp[j++];
        /*放回原数组*/
        delete[] temp;
        /*归并左右区间*/
        return inversions;
}

/*
* 函数名 bucket_sort(桶排序)
* 作用 将给定的 无符号整数！ 数组排序
* O(n)
* 参数说明 array:待排序数组, begin:排序起点, end:排序终点
* 请重载"<"以自定义数据类型排序或降序排序
*/
void bucket_sort(unsigned int array[], int begin, int end)
{
        unsigned int maxx = 0; 
        for (int i = begin; i <= end; i++)
                maxx = (array[i] > maxx) ? array[i] : maxx;
        /*找到最大数*/
        unsigned int *bucket = new unsigned int[maxx+1];
        /*注意 最大数过大可能 mle */
        for (int i = 0; i <= maxx; i++)
                bucket[i] = 0;
        int k = begin;
        /*存入数组指针*/
        for (int i = begin; i <= end; i++)
                bucket[array[i]]++;
        /*放入桶*/
        for (int i = 0; i <= maxx; i++)
                for (int j = 1; j <= bucket[i]; j++)
                        array[k++] = i;
        /*放回数据*/
        delete[] bucket;
}

}
/*如何使用:
* 将头文件放在源文件同目录下，include即可
* 例如：
* #include <iostream>
* #include "sort.h" 
* using namespace std;
* using namespace TOCL; //使用命名空间TOCL
*
* int main() {
*        int array[] = {3,1,2,4,5,6,4,5,5,3};
*        quick_sort (array, 0, 9);
*        //调用快排
*        for (int i = 0; i < 10; i++)
*                 cout << array[i] << " ";
*        return 0;
* }
*/
