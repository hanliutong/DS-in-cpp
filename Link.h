//
// Created by Hanliutong on 2018/3/21.
//

#ifndef DS_LINK_H
#define DS_LINK_H
#include <iostream>
using namespace std;

template <class T>      //结点定义、2个构造函数
class Link{             //结点Link
public: T   data;   //数据域
    Link<T> *next;  //指针域，自引用型类型

    Link( T info,  Link<T> *nextValue = NULL) {
        data = info;
        next = nextValue;           }

    Link(Link<T> *nextValue) {
        next = nextValue;           }
    Link(){
        T *next;
    };
};
#endif //DS_LINK_H
