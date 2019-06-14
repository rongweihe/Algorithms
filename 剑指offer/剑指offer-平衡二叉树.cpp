/*
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/
//解法一：最直接的做法，遍历每个结点，借助一个获取树深度的递归函数，根据该结点的左右子树高度差判断是否平衡，然后递归地对左右子树进行判断。
class Solution
{
public:
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
        if(!pRoot) return true;
        return abs(maxDepth(pRoot->left) - maxDepth(pRoot->right))<=1 && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    int maxDepth(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};

//解法二：上面的这种做法有很明显的问题，在判断上层结点的时候，会多次重复遍历下层结点，增加了不必要的开销。如果改为从下往上遍历，如果子树是平衡二叉树，则返回子树的高度；
//如果发现子树不是平衡二叉树，则直接停止遍历，这样至多只对每个结点访问一次。
class Solution
{
public:
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
        return maxDepth(pRoot)!=-1;
    }
    int maxDepth(TreeNode* root)
    {
        if(!root) return 0;
        int left  = maxDepth(root->left);
        if(left==-1) return -1;
        int right = maxDepth(root->right);
        if(right==-1) return -1;
        return abs(left-right)>1?-1:1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

//参考 链接：https://www.nowcoder.com/questionTerminal/8b3b95850edb4115918ecebdf1b4d222
//来源：牛客网
