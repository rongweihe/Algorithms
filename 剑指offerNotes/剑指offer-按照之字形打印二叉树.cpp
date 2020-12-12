/*
Problem:
题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
//github.com/rongweihe
class Solution
{
public:
    vector<vector<int> > Print(TreeNode* pRoot)
    {
        vector<vector<int> > ret;
        //利用栈的先进后出，打印一个节点值的时候，同时压入该节点的左右子节点
        stack<TreeNode*>s1,s2;
        bool odd = true;
        if(pRoot==NULL) return ret;
        s1.push(pRoot);
        while(!s1.empty() || !s2.empty())
        {
            vector<int> data;
            if(!s1.empty())
            {
                while(!s1.empty())
                {
                    TreeNode* node = s1.top();s1.pop();
                    data.push_back(node->val);
                    if(node->left!=NULL) s2.push(node->left);
                    if(node->right!=NULL) s2.push(node->right);
                }
                ret.push_back(data);
            }
            else if(!s2.empty())
            {
                while(!s2.empty())
                {
                    TreeNode* node = s2.top();s2.pop();
                    data.push_back(node->val);
                    if(node->right!=NULL) s1.push(node->right);
                    if(node->left!=NULL) s1.push(node->left);
                }
                ret.push_back(data);
            }
        }
        return ret;
    }
};
