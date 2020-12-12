/*
题目描述
输入一个链表，反转链表后，输出新链表的表头。
Create By@herongwei 2019/08/14 
当前节点是 cur，pre 为当前节点的前一节点，next 为当前节点的下一节点
需要 pre 和 next 的目的是让当前节点从 pre->cur->next1->next2 变成 pre<-cur next1->next2
即 pre 让节点可以反转所指方向，但反转之后如果不用 next 节点保存 next1 节点的话，此单链表就此断开了
所以需要用到 pre 和 next 两个节点
1->2->3->4->5
1<-2<-3 4->5

1.做循环，如果当前节点不为空的话，始终执行此循环，此循环的目的就是让当前节点从指向 next 到指向 pre
如此就可以做到反转链表的效果
先用 next 保存 cur 的下一个节点的信息，保证单链表不会因为失去 cur 节点的原 next 节点而就此断裂
2.保存完 next，就可以让 cur 从指向 next 变成指向 pre 了
3.cur 指向 pre 后，就继续依次反转下一个节点
4.让 pre，cur，next 依次向后移动一个节点，继续下一次的指针反转
*/

class Solution
{
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        ListNode* pReversedHead = nullptr;
        ListNode* pCur = pHead;
        ListNode* pPre = nullptr;
        while(pCur != nullptr)
        {
            ListNode* pNext = pCur->next;//链断开之前一定要保存断开位置后边的结点
            if(pNext == nullptr) //当next为空时，说明当前结点为尾节点
                pReversedHead = pCur;
            pCur->next = pPre;
            pPre = pCur;
            pCur = pNext;
        }
        return pReversedHead;
    }
};
