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

template <class T>
//class lnkList: public List<T>{
class lnkList{
private:  Link<T> *head,*tail;//头节点和尾节点的指针
    Link<T> *setPos(const int p); //找第p个结点
public: lnkList( );     //构造函数
    ~lnkList();     //析构函数
    bool  isEmpty( );   //判空
    void  clear( );     //清空
    int  length( );     //求表长
    bool  append(T value); //追加值为value的元素
    bool  Insert(const int p, const T value);   //插入
    bool  del(const int p);         //删除
    //bool  getValue(int p, T& value) const;
    T  getValue(int p) ;    //取位置p值
    int  getPos( T value); //找值为value结点
    void travel();//遍历整个表（输出）
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
    if( i <= -1) return head; //位置有误:返回头结点指针
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
T lnkList<T> :: getValue(int p){
/*
        if (p < 1) return false;
        Link<T> *current = head;
        int index = 1; // current的索引
        while (index < p && current) {
            current = current->next;
            index++; }
        if (current) {value = current->data; return true;}
        return false; // 不存在第k个元素

    Link<T> *current = head;
    int index = 1; // current的索引
    while (index < p && current) {
        current = current->next;
        index++; }
    return current->data;
*/
    int count = 0;
    Link<T> *l =head ->next;
    while(l != NULL){
        l = l->next;
        count++;
    }
    if ( p < 0||p > (count-1) )
    {
        cout << "illgeal 'p':";
        return -1;
    }
    Link<T> *point = setPos( p );//这个必须是有效位置。否则会崩溃

    return point -> data;

}
template<class T>
int lnkList<T> ::  getPos( T value){
    Link<T> *current = head;
    int index = 0; // current的索引
    while (current && current->data != value) {
        current = current->next; index++ ; }
    if (current) return index-1;
    return -1;
}

template<class T>
void lnkList<T> :: travel(){
    if (head == tail)
    {cout << "this LinkList is empty" <<endl;}
    else{
    Link<T> *p =head ->next;
    while(p != NULL){
        cout << p -> data << " ";
        p = p->next; 
        }
    }
    cout << endl;
}


int main()
{   
    lnkList<int> lnk_A;
    lnkList<int> lnk_B;
    lnkList<int> lnk_C;
    lnk_A.append(1);lnk_A.append(2);lnk_A.append(3);lnk_A.append(4);lnk_A.append(7);lnk_A.append(19);
    lnk_B.append(2);lnk_B.append(4);lnk_B.append(5);lnk_B.append(6);lnk_B.append(7);
    lnk_A.travel();lnk_B.travel();
    //算法P45_9
    int pos_A = 0, pos_B = 0, len_A = lnk_A.length(), len_B = lnk_B.length();
    
    
        while (pos_A < len_A && pos_B < len_B){
            if ( lnk_A.getValue(pos_A) < lnk_B.getValue(pos_B))
             {  cout << " A < B : " << endl;
                 pos_A++;
             } else if(lnk_A.getValue(pos_A) == lnk_B.getValue(pos_B) ){
                cout << " A = B : " << endl;
                lnk_C.append(lnk_A.getValue(pos_A));
                pos_A++;
                pos_B++;
             } else{
                cout << " A > B : " << endl;
                pos_B++;

             }          
        }
    lnk_C.travel();
    return 0;
    }



