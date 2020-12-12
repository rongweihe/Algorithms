/*
Create By @herongwei 2019/08/10
【题目描述】
题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
【思路】
利用栈和 vector 容器
*/
//方法一
class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        std::stack<ListNode*>S;
        std::vector<int>V;
        ListNode* pNode = head;
        while(pNode!=nullptr)
        {
            S.push(pNode);
            pNode = pNode->next;
        }
        while(!S.empty())
        {
            V.push_back(S.top()->val);
            S.pop();
        }
        return V;
    }
};
//方法二，只利用 vector
class Solution2
{
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        std::vector<int>V;
        ListNode* pNode=head;
        while(pNode!=NULL)
        {
            V.push_back(pNode->val);
            pNode=pNode->next;
        }
        return  vector<int>(V.rbegin(),V.rend());
    }
};
