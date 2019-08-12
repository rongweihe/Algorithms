/*******************************************************************
Copyright(c) 2019, herongwei

情况一、普通的树，调用函数
【思路】
代码中 getNodePath 用来得到从根节点 pRoot 开始到达节点 pNode 的路径,这条路径保存在 path 中。
函数getLastCommonNode 用来得到两条路径 path1 和 path2 的最后一个公共节点。
函数 getLastCommonParent 先调用getNodePath 得到 pRoot 到达 pNodel 的路径 path1,
再得到 pRoot 到达 pNode2 的路径path2,接着调用 getLastCommonParent 得到 path1 和 path2 的最后一个公共节点,
即我们要找的最低公共祖先。

情况二：二叉树中两个节点的最近公共父节点，节点只有左、右指针，没有 parent 指针，root 已知
【思路】递归调用左右子树判断即可
有两种情况：
一是要找的这两个节点（left, right），在要遍历的节点（root）的两侧，那么这个节点就是这两个节点的最近公共父节点；
二是两个节点在同一侧，则 root->left 或者 root->right 为 NULL，另一边返回 left 或 right 。
那么另一边返回的就是他们的最小公共父节点。

情况三：二叉树是二叉搜索树
【思路】
1、二叉搜索树第排序过的，位于左子树的节点都比父节点小，而位于右子树的节点都比父节点大
    从根节点开始和输入的两个节点比较，如果当前的节点值比两个节点值都大，那么最近的公共父节点
    一定在当前节点的左子树中，于是下一步遍历当前节点的左子树，否则遍历右子树
*******************************************************************/

//情况一
struct TreeNode
{
    int                       val;
    std::vector<TreeNode*>    child;
};
bool getNodePath(const TreeNode* pRoot, const TreeNode* pNode, list<const TreeNode*>& path)
{
    if(pRoot == pNode)
        return true;
 
    path.push_back(pRoot);
 
    bool found = false;

    vector<TreeNode*>::const_iterator i = pRoot->child.begin();
    while(!found && i < pRoot->child.end())
    {
        found = getNodePath(*i, pNode, path);
        ++i;
    }
 
    if(!found)
        path.pop_back();
 
    return found;
}

const TreeNode* getLastCommonNode
(
    const list<const TreeNode*>& path1, 
    const list<const TreeNode*>& path2
)
{
    list<const TreeNode*>::const_iterator iterator1 = path1.begin();
    list<const TreeNode*>::const_iterator iterator2 = path2.begin();
    
    const TreeNode* pLast = nullptr;
 
    while(iterator1 != path1.end() && iterator2 != path2.end())
    {
        if(*iterator1 == *iterator2)
            pLast = *iterator1;
 
        iterator1++;
        iterator2++;
    }
 
    return pLast;
}

const TreeNode* getLastCommonAncestor(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2)
{
    if(pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
        return nullptr;
 
    list<const TreeNode*> path1;
    getNodePath(pRoot, pNode1, path1);
 
    list<const TreeNode*> path2;
    getNodePath(pRoot, pNode2, path2);
 
    return getLastCommonNode(path1, path2);
}


struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {
    }
};
 //情况二
TreeNode* getLastCommonAncestor(TreeNode* root, TreeNode* pNode1, TreeNode*pNode2)
{
     if(root == nullptr) return nullptr;
     if(root == pNode1 || root == pNode2) return root;
     TreeNode* leftNode  = getLastCommonAncestor(root->left, pNode1,pNode2);
     TreeNode* rightNode = getLastCommonAncestor(root->right, pNode1,pNode2);
     if(leftNode && rightNode) return root;
     return leftNode ? leftNode: rightNode;
}

//情况三
TreeNode* getLastCommonAncestor(TreeNode* root, TreeNode* pNode1, TreeNode*pNode2)
 {
        int minVal = min(pNode1->val,pNode2->val);
        int maxVal = max(pNode1->val,pNode2->val);
        while(root)
        {
            if(root->val >= minVal && root->val <= maxVal)
                return root;
            else if(root->val >= minVal && root->val >= maxVal)
                 root = root->left;
            else root = root->right;
        }
        return nullptr;
    }
