/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。
【思路】快慢指针，快指针先走k步，然后一块走，当快指针走到尾，慢指针此时指向的就是所求
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};*/
//Create By@herongwei 2019/08/14 
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if( k<=0 || pListHead == nullptr ) return nullptr;
        ListNode* pre;
        ListNode* back;
        pre=back=pListHead;
        for(unsigned int i=0; i<k-1; ++i)
        {
            if(pre->next!= nullptr ) pre=pre->next;
            else return nullptr;
        }
        while(pre->next!=nullptr)
        {
            pre=pre->next;
            back=back->next;
        }
        return back;
    }
};
