/*TYWZ OIer's Code Library
* Copyright(C) 2015
* Written by Taiyuan No. 5 Junior/Senior High School Students
* >>> map.h <<<
* a easy way to deal with mapping table
* 实现映射表的简单方法
*/

#pragma once
#include "tree.h"

namespace TOCL {


/*类名 pair (映射组)*/
template <typename K, typename D>
class pair {
        public:
        K key;
        D data;
        friend bool operator < (pair a, pair b) 
        {
                return a.key < b.key;
        }
        friend bool operator == (pair a, pair b) 
        {
                return a.key == b.key;
        }
        /*二叉平衡树要求重载< ==*/
};


/*使用二叉查找树的实现*/
template <typename K, typename D>
class map {
        private:
        binary_search_tree < pair<K,D> > bst;
        public:
        /*成员函数*/
        /*
        * 函数名 empty(判断是否为空表)
        * O(1)
        */
        bool empty ()
        {
                return bst.empty ();
        }
        
        /*
        * 函数名 clear(清空)
        * O(n)
        */
        void clear ()
        {
               bst.clear ();
        }
        
        /*运算符重载*/
        /*返回键值key的映射的引用*/
        D& operator [] (K key)
        {
                pair<K, D> pai;
                pai.key = key;
                bst.insert (pai);
                /*插入*/
                return bst.find(pai)->data.data;
                /*返回数值*/
        }
};


}
