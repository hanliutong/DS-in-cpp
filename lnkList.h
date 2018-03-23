//
// Created by Hanliutong on 2018/3/21.
//

#ifndef DS_LNKLIST_H
#define DS_LNKLIST_H

#include "Link.h"
template <class T>
//class lnkList: public List<T>{
class lnkList{
private:  Link<T> *head,*tail;//头指针和尾指针
    Link<T> *setPos(const int p); //找第p个结点
public: lnkList( );     //构造函数
    ~lnkList();     //析构函数
    bool  isEmpty( );   //判空
    void  clear( );     //清空
    int  length( );     //求表长
    bool  append(T value); //追加值为value的元素
    bool  Insert(const int p, const T value);   //插入
    bool  del(const int p);         //删除
    bool  getValue(int p, T& value);
    bool  getPos(int &p, T value);
    void  travel();
};

template <class T>
lnkList<T>:: lnkList( ){    //构造函数
    Link<T> *p;
    head = tail = new Link<T>(p);       }

template <class T>
lnkList<T>::~lnkList(){     //析构函数
    Link<T> *tmp;
    while (head != NULL){
        tmp = head;
        head = head->next;
        delete tmp; }           }

template<class T>
Link<T>* lnkList<T> :: setPos( int i ) {
    int count =0;
    if( i <= -1) return head; //返回头结点指针
    Link<T> *p = head->next;  //p指向第一个数据结点
    while( p!= NULL && count < i){      //T(n)=O(n)
        p = p->next;
        count++;            }
    return p;                   }//p所指结点/返空

template<class T>  // 插入新结点(值为value)为第i个结点
bool lnkList<T> :: Insert(const int i, const T value){
    Link<T> *p, *q;
    if ( (p = setPos( i -1 ) )==NULL){ //循环O(n)找第i-1个结点
        cout<<"非法插入点"<<endl;      return false; }
    q = new Link<T>(value, p->next);  //创建新结点q,链后继
    p->next  = q;       //第i-1个结点p的后继为q
    if ( p == tail )    tail = q;//若属于追加,q作新尾
    return true;                    }

template<class T>       //删除由参数i所指定的结点
bool lnkList<T> ::del(const int i){
    Link<T>     *p,     *q;
    if ((p= setPos(i-1) ) ==NULL|| p ==tail){ //定位O(n)
        cout<<"非法删除点"<<endl; //第[i-1]或第[i]个为空
        return false;   }
    q = p->next;        //q指向被删点; p指向q的前驱
    p->next = q->next;
    if ( q == tail ) tail = p;
    delete q;

    return true;                    }

template<class T>  //
bool lnkList<T> :: isEmpty(){
    if (head==tail)
    {
        return true;
    }
    return false;
}

template<class T>
void lnkList<T> :: clear(){
    tail = head;
}

template<class T>
int lnkList<T> :: length(){
    if (head == tail)
    {
        return 0;
    }
    int count = 0;
    Link<T> *p =head ->next;
    while(p != NULL){
        p = p->next;
        count++;
    }
    return count;
}
template<class T>
bool lnkList<T> :: append(T value){
    Link<T> * q;
    q = new Link<T>(value,NULL);
    tail->next = q;
    tail = q;

    return 1;
}

template<class T>
bool lnkList<T> :: getValue(int p, T& value){
    int count = 0;
    Link<T> *l =head ->next;
    while(l != NULL){
        l = l->next;
        count++;
    }
    if ( p < 0||p > (count-1) )
    {
        cout << "illgeal 'p':";
        return 0;
    }
    Link<T> *point = setPos( p );
    value = point -> data;

    return 1;

}
template<class T>
bool lnkList<T> ::  getPos(int &p, T value){
    Link<T> *current = head->next;
    int index = 0; // current的索引
    while (current && current->data != value)
    {
        current = current->next;
        ++index ;
    }
    if (current)
    {
        p = index ;
        return 1;
    }
    p = -1;
    return 0;
}

template <class T>
void lnkList<T> :: travel(){
    Link<T> *current = head ->next;
    while (current)
    {
        cout << current ->data <<"\t";
        current = current->next;
    }
    cout <<endl;
}


#endif //DS_LNKLIST_H
