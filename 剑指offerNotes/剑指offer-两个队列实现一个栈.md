Create By @herongwei 2019/08/10

### **问题描述**

用两个队列实现一个栈

由于栈的性质是“后进先出”的，用两个队列模拟实现栈的时候就需要两个队列的元素“互捣”，实现尾插和头删，从而实现栈的这一特性，具体的做法，我们还是用一张图来看一看

![img](https://i.loli.net/2018/09/09/5b94db36f15ee.png)

### **分析**

1. 图（1）：当栈里面插入元素“abcd”的时候，元素a在栈底（最后出去），d在栈顶（最先出去）。
2. 图（2）：将元素“abc”从q1中头删，然后再q2中尾插进来之后，头删q1中的元素“d”，就相当于实现了栈顶元素的出栈。
3. 图（3）：同理，将元素“ab”从q2中头删，然后尾插到q1中，然后再头删q2中的元素“c”。
4. 图（4）：同理，删除元素“b”。
5. 图（5）：当栈又插入一个元素“e”时，此时元素“a”不能从队列中删除，而是将元素“a”插入q2中，再删除q1中的元素“e”,最后再删除元素“a”。
6. 说明：其中红色框代表该队列中的元素出队列，该队列为空。

### 实现

```c++
class Solution
{
public:
    void push(int node)
    {
        if(!q1.empty())
        {
            q1.push(node);
        }
        else
        {
            q2.push(node);
        }
    }
    int pop()
    {
        int num=0,cap=0;
        if(!q1.empty())
        {
            cap = q1.size();
            while(cap>1)
            {
                q2.push(q1.front());
                q1.pop();
                --cap;
            }
            num = q1.front();
            q1.pop();
        }
        else
        {
            cap = q2.size();
            while(cap>1)
            {
                q1.push(q2.front());
                q2.pop();
                --cap;
            }
            num = q2.front();
            q2.pop();
        }
        return num;
    }
private:
    std::queue<int> q1;
    std::queue<int> q2;
};
```

