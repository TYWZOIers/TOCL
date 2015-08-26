/*TYWZ OIer's Code Library
* Copyright(C) 2015
* Written by Taiyuan No. 5 Junior/Senior High School Students
* >>> tree.h <<<
* including algorithm of tree
* 包括树相关的算法
*/

/*对于自定义数据，你必须重载'=='和'<' */

#pragma once

namespace TOCL {

/*类名 node (节点)*/
template <typename T>
class node {
        public:
        T data;
        node *left_child, *right_child;
};


/*类名 binary_search_tree (二叉搜索树)
* 函数 insert(T), find(T), empty()
* 以上操作期望复杂的O(log2n), 最坏复杂度O(n)
* 自定义数据必须重载 '<' 和 '=='
*/

template <typename T>
class binary_search_tree {
        private:
        node<T> *root;
        /*私有成员函数*/
        /*insert的私有实现*/
        void put (node<T>* &n, T data)
        {
                /*节点为空，新建并插入数据*/
                if (!n) {
                        n = new node<T>;
                        n->data = data;
                        n->left_child = n->right_child = 0;
                        return;
                }
                /*否则左右查找*/
                if (data == n->data)
                        return;
                else if (data < n->data) 
                        put (n->left_child, data);
                else 
                        put (n->right_child, data);
        }
        
        /*find的私有实现*/
        node<T>* get (node<T>* n, T data)
        {
                if (!n)
                        return 0;
                /*找不到*/
                if (n->data == data)
                        return n;
                else if (data < n->data)
                        return get(n->left_child, data);
                else
                        return get(n->right_child, data);
                /*左右查找*/
        }
        
        /*析构函数私有实现*/
        void del (node<T> *n)
        {
                if (n) {
                        /*删除左右节点*/
                        del (n->left_child);
                        del (n->right_child);
                        delete n;
                        /*释放父节点*/
                }
        }
        
        public:
        binary_search_tree () 
        {
                root = 0;
        }
        
        ~binary_search_tree()
        {
               del (root); 
               /*删除树*/
        }
        
        /*成员函数*/
        
        /*
        * 函数名 insert(冒泡排序)
        * O(log2n) -> O(n)
        * 参数说明 data:插入的数据
        * 请重载"<"以自定义数据类型或降序(默认升序)
        * 例如
        * struct data {
        *         int d;
        *         friend bool operator < (data a, data b) {
        *                 return a.d > b.d;
        *                 //降序
        *         }
        * }
        */
        
        void insert (T data)
        {
                put (root, data);
                /*调用私有成员函数*/
        }
        
        /*
        * 函数名 find(查找数据)
        * O(log2n) -> O(n)
        * 参数说明 data:查找的数据
        * 请重载"<"以自定义数据类型或降序(默认升序)
        */
        node<T>* find (T data)
        {
                return get (root, data);
        }
        
        /*
        * 函数名 empty(判断是否为空树)
        * O(1)
        */
        bool empty()
        {
                return (root == 0);
        }
        
        /*
        * 函数名 clear(清空)
        * O(n)
        */
        void clear ()
        {
                del (root);
        }
        
        /*以下仅供测试.........*/
        void dfs (node<T>* n)
        {
               if (n) {
                       std::cout << n->data << ' ';
                       dfs(n->left_child);
                       dfs(n->right_child);
               }         
        }
        
        void go()
        {
                dfs (root);
        }
        /*....................*/
};

/*以上为二叉搜索树定义部分*/

}
