//根据前序和中序遍历，重建二叉树
class Solution
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, 0, preorder.size()-1, inorder,0,inorder.size()-1);
    }
    TreeNode* solve(vector<int>& preorder, int preBegin,int preEnd,vector<int>& inorder,int inBegin, int inEnd)
    {
        if(preBegin > preEnd || inBegin > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preBegin]);

        int index=inBegin,leftPreEnd=0;
        for(;index<=inEnd&&preorder[preBegin]!=inorder[index]; ++index) ++leftPreEnd;

        root->left  = solve(preorder,preBegin+1,preBegin+leftPreEnd,inorder,inBegin,index-1);
        root->right = solve(preorder,preBegin+1+leftPreEnd,preEnd,inorder,index+1,inEnd);
        return root;
    }
};

//根据后序和中序遍历，重建二叉树
class Solution
{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder, 0, inorder.size()-1, postorder,0,postorder.size()-1);
    }
    TreeNode* solve(vector<int>&inorder, int inBegin,int inEnd,vector<int>&postorder,int postBegin, int postEnd)
    {
        if(inBegin>inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int leftPostEnd=0;//记录后序遍历左子树末尾
        int leftInEnd=inBegin;//记录中序遍历左子树末尾

        for(; leftInEnd<=inEnd&&inorder[leftInEnd]!=postorder[postEnd]; ++leftInEnd) ++leftPostEnd;
        root->left  = solve(inorder,inBegin,leftInEnd-1,postorder,postBegin,postBegin+leftPostEnd-1);
        root->right = solve(inorder,leftInEnd+1,inEnd,postorder,postBegin+leftPostEnd,postEnd-1);
        return root;
    }
};
