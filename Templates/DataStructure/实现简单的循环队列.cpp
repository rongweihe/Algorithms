/*
【实现简单的循环队列】
【Author】herongwei
【Time】2019/08/24
【思路】：
1、判断队空的方法是判断front==rear
2、队满的方法是判断front=（rear+1）%maxSize
3、入队，插入一个元素
 3.1、如果队满，返回错误
 3.2、否则链表队尾插入元素，更新队尾
4、出队，队头删除一个元素
 4.1、如果队空，返回错误
 4.2、否则链表队头插入元素，更新队头
5、用单链表表示的链式队列特别适合于数据元素变动较大的情形，而且不存在溢出的情况。
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 233;
int n,m,T,a[maxn],b[maxn];

template<class T>
class CirQueue
{
private:
    T* e;
    int front_,rear_;
    int max_size_;
public:
    CirQueue(int sz=10)
    {
        front_ = rear_ = 0;
        max_size_ = sz;
        e = new T[max_size_];
    }
    ~CirQueue()
    {
        delete[] e;
    }
    bool isQueueFull() const   //队列是否为满
    {
        return ((rear_+1)%max_size_ == front_ )?true:false;
    }
    bool isQueueEmpty() const   //判断队列是否为空
    {
        return (front_ == rear_)?true:false;
    }
    bool enQueue(const T& x)   //入队
    {
        if(isQueueFull())
            return false;
        e[rear_] = x;
        rear_ = (rear_+1)%max_size_;
        return true;
    }
    bool deQueue(T& x)  //出队
    {
        if(isQueueEmpty())
            return false;
        x = e[front_];
        front_ = (front_+1)%max_size_;
        return true;
    }
    bool getFront(T& x)   //获取队首元素
    {
        if(isQueueEmpty())
            return false;
        x = e[front_];
        return true;
    }
    void clearQueue()
    {
        front_ = rear_ = 0;
    }
    int getQueueSize()
    {
        return (rear_ - front_ + max_size_) %max_size_;
    }
};

void menu()
{
    cout<<"1.入队"<<endl;
    cout<<"2.获取队首元素"<<endl;
    cout<<"3.出队"<<endl;
    cout<<"4.队列置空"<<endl;
    cout<<"5.获取队中元素数量"<<endl;
    cout<<"6.退出"<<endl;
}

void test(int num,CirQueue<int> *cq)
{
    switch(num)
    {
        int x;
    case 1:
        cin>>x;
        cq->enQueue(x);
        break;
    case 2:
        cq->getFront(x);
        cout<<x<<endl;
        break;
    case 3:
        cq->deQueue(x);
        break;
    case 4:
        cq->clearQueue();
        break;
    case 5:
        x=cq->getQueueSize();
        cout<<x<<endl;
        break;
    default:
        exit(1);
    }
}
int main(int argc, char** argv)
{
    // freopen("in.txt","r",stdin);
    CirQueue<int> *cq=new CirQueue<int>;
    int num;
    while(true)
    {
        menu();
        cin>>num;
        test(num,cq);
    }
    delete cq;
    return 0;
}
