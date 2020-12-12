/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Create By @herongwei 2019/08/10
【题目描述】
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。
【思路】
1、合法性判断;
2、分别储存前序中序的两个端点
3、创建根节点，根节点肯定是前序遍历的第一个数
4、找到中序遍历根节点所在位置
5、对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
   利用上述这点，对二叉树节点进行归并
6、递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
*/
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        //合法性判断
        int len = vin.size();
        if(len==0) return nullptr;

        //分别储存前序中序的两个端点
        std::vector<int> startPre,endPre,startIn,endIn;

        //创建根节点，根节点肯定是前序遍历的第一个数
        TreeNode* root = new TreeNode(pre[0]);

        //找到中序遍历根节点所在位置
        int rootIndex = 0;
        for(int i=0; i<len; ++i)
        {
            if(vin[i]==pre[0])
            {
                rootIndex = i;
                break;
            }
        }

        //对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
        //利用上述这点，对二叉树节点进行归并
        for(int i=0; i<rootIndex; ++i)
        {
            startPre.push_back(pre[i+1]);
            startIn.push_back(vin[i]);
        }
        for(int i=rootIndex+1; i<len; ++i)
        {
            endPre.push_back(pre[i]);
            endIn.push_back(vin[i]);
        }
        //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
        root->left  = reConstructBinaryTree(startPre,startIn);
        root->right = reConstructBinaryTree(endPre,endIn);
        return root;
    }
};
