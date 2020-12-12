/*
Author: github.com/rongweihe
Date  : 2019/05/04
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
思路：用另外一个辅助栈把每次的最小元素保存起来。
*/
class Solution
{
public:
    void push(int value)
    {
        m_data.push(value);
        if(m_min.size()==0 || value<m_min.top())
            m_min.push(value);
        else
            m_min.push(m_min.top());
    }
    void pop()
    {
        assert(m_data.size()>0 && m_min.size()>0);
        m_data.pop();
        m_min.pop();
    }
    int top()
    {
        assert(m_data.size()>0 && m_min.size()>0);
        return m_data.top();
    }
    int min()
    {
        assert(m_data.size()>0 && m_min.size()>0);
        return m_min.top();
    }
private:
    stack<int>m_data;
    stack<int>m_min;
};
