//Create By@herongwei 2019/08/14 类似归并排序
/*
合并两个排序的链表
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr ) return pHead2;
        if(pHead2 == nullptr ) return pHead1;
        ListNode* mergeHead = nullptr;
        if(pHead1->val < pHead2->val)
            mergeHead = pHead1,mergeHead->next = Merge(pHead1->next,pHead2);
        else {
            mergeHead = pHead2,mergeHead->next = Merge(pHead1,pHead2->next);
        }
        return mergeHead;
    }
};
