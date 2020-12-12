
/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

//递归版
//github.com/rongweihe
class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if(sequence.empty()) return false;
        int root = sequence[sequence.size()-1];//找到根结点

        // 在二叉搜索树中左子树的结点小于根节点
        vector<int> leftS;
        int i=0;
        for(i=0; i<sequence.size()-1; ++i)
        {
            if(sequence[i]<root) leftS.push_back(sequence[i]);
            else break;
        }

        // 在二叉搜索树中右子树的结点大于根节点
        vector<int> rightS;
        int j=0;
        for(j=i; j<sequence.size()-1; ++j)
        {
            if(sequence[j]>root) rightS.push_back(sequence[j]);
            else return false;
        }

        // 如果左子树不为空，则判断左子树是否满足
        bool vaildLeft = true;
        if(!leftS.empty()) vaildLeft = VerifySquenceOfBST(leftS);

        // 如果右子树不为空，则判断右子树是否满足
        bool vaildRight= true;
        if(!rightS.empty()) vaildRight = VerifySquenceOfBST(rightS);

        return (vaildLeft&&vaildRight);
    }
};
