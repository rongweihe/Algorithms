给定一个二叉树和其中一个节点，请找出中序遍历的下一个节点，并且返回

此处分为两种情况： 

![这里写图片描述](https://img-blog.csdn.net/20180813234607694?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x4ODIxMTY2Nzg0Njk0Nw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

![这里写图片描述](https://img-blog.csdn.net/20180813234622458?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2x4ODIxMTY2Nzg0Njk0Nw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

参考代码

```c++
/*
Create By @herongwei 2019/08/10 猿辅导一面手写代码题目
【题目描述】
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
【思路】
1、如果 pNode 的右子树存在，那么找到右子树最左边的节点就是中序遍历的下一个结点
2、如果 pNode 的右子树不存在：
   2.1、如果 pNode 是其父亲节点的左孩子，那么下一个节点就是其父亲节点。
   2.2、如果 pNode 是父亲节点的右孩子，那么需要一直向它的根往上找
        2.2.1、如果找到 pNode 是哪个节点的左子树，那么那个节点就是中序遍历的下一个节点
        2.2.2、如果找不到，说明是中序遍历的最后一个节点
*/
/*
struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {}
};
*/
class Solution
{
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) 
    {
        if(pNode==nullptr)
            return nullptr;

        TreeLinkNode* rNode = nullptr;
        TreeLinkNode* nextNode = nullptr;

        //1
        if(pNode->right)
        {
            rNode = pNode->right;
            while(rNode->left)
                rNode=rNode->left;
            nextNode = rNode;
        }

        //2
        else if(pNode->next)
        {
            TreeLinkNode* faNode = pNode->next;
            TreeLinkNode* pCur   = pNode;
            nextNode = pNode;
            //2.2.1
            while(faNode&&pCur == faNode->right)
            {
                pCur = faNode;
                faNode = pCur->next;
            }
            nextNode = faNode;
        }
        return nextNode;
    }
};
```

