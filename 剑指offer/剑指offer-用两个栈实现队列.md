Create By @herongwei 2019/08/10

### **问题描述**

用两个栈实现队列

看到这个题，我们就要想到栈和队列的不同，所谓用两个栈实现一个队列是指，我们要实现队列的“尾插”和“头删”操作。

首先，假如我们要插入一些数据“abcd”，我们知道按照这个顺序队列出现的结果也是“abcd”，而栈会出现“dcba”，刚好相反，因此将该栈的到的数据在插入另外一个栈中就会出现我们想要的结果。因此，我们定义两个栈为“stack1”和“stack2”，栈1只用来插入数据，栈2用来删除数据栈1插入进来的数据。

通过下面的图，我们来分析一下这个模拟的场景

![img](https://i.loli.net/2018/09/09/5b94daba37d1e.png)

### **分析**

【思路】

1. 图（1）：将队列中的元素“abcd”压入stack1中，此时stack2为空。
2. 图（2）：将stack1中的元素pop进stack2中，此时pop一下stack2中的元素，就可以达到和队列删除数据一样的顺序了。
3. 图（3）：图3，当stack2只pop了一个元素a时，satck1中可能还会插入元素e,这时如果将stack1中的元素e插入stack2中，在a之后出栈的元素就是e了，因此我们必须规定当stack2中的元素pop完之后，也就是satck2为空时，再插入stack1中的元素。


参考代码

```c++
class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }
    int pop()
    {
        int tmp;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                tmp = stack1.top();
                stack2.push(tmp);
                stack1.pop();
            }
        }
        tmp = stack2.top();
        stack2.pop();
        return tmp;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
```

