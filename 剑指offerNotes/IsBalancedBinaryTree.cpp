/*
题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。例如下图中的二叉树就是一棵平衡二叉树：

 程序员面试题精选100题(60)-判断二叉树是不是平衡的 - 何海涛 - 微软、Google等面试题

在本系列博客的第27题，我们曾介绍过如何求二叉树的深度。有了求二叉树的深度的经验之后再解决这个问题，我们很容易就能想到一个思路：在遍历树的每个结点的时候，调用函数TreeDepth得到它的左右子树的深度。如果每个结点的左右子树的深度相差都不超过1，按照定义它就是一棵平衡的二叉树。这种思路对应的代码如下：
 

上面的代码固然简洁，但我们也要注意到由于一个节点会被重复遍历多次，这种思路的时间效率不高。例如在函数IsBalance中输入上图中的二叉树，首先判断根结点（值为1的结点）的左右子树是不是平衡结点。此时我们将往函数TreeDepth输入左子树根结点（值为2的结点），需要遍历结点4、5、7。接下来判断以值为2的结点为根结点的子树是不是平衡树的时候，仍然会遍历结点4、5、7。毫无疑问，重复遍历同一个结点会影响性能。接下来我们寻找不需要重复遍历的算法。

如果我们用后序遍历的方式遍历二叉树的每一个结点，在遍历到一个结点之前我们已经遍历了它的左右子树。只要在遍历每个结点的时候记录它的深度（某一结点的深度等于它到叶节点的路径的长度），我们就可以一边遍历一边判断每个结点是不是平衡的。下面是这种思路的参考代码：
 

我们只需要给上面的函数传入二叉树的根结点以及一个表示结点深度的整形变量就可以了：

bool IsBalanced(BinaryTreeNode* pRoot)

{

    int depth = 0;

    return IsBalanced(pRoot, &depth);

}

在上面的代码中，我们用后序遍历的方式遍历整棵二叉树。在遍历某结点的左右子结点之后，我们可以根据它的左右子结点的深度判断它是不是平衡的，并得到当前结点的深度。当最后遍历到树的根结点的时候，也就判断了整棵二叉树是不是平衡二叉树了。

*/

#include <iostream>
#include <bits/stdc++.h>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* lefetree;
    BinaryTreeNode* righttree;
};
bool IsBalanced(BinaryTreeNode* pRoot)
{
    if(pRoot == NULL) return false;
    int left = TreeDepth(pRoot->lefetree);
    int right = TreeDepth(pRoot->righttree);
    int diff = abs(left-right);
    if(diff <= 1) return true;
    return IsBalanced( (pRoot->lefetree)&& (pRoot->righttree) );
}

bool IsBalanced(BinaryTreeNode* pRoot, int* depth)
{
    if(pRoot == NULL)
    {
        *depth = 0;
        return true;
    }

    int left,right;
    if( IsBalanced(pRoot->lefetree,&left) &&
        IsBalanced(pRoot->righttree,&right)
       )
    {
        int diff = left-right;
        if(abs(diff)<=1)
        {
            *diff = 1+ (left>right)?left:right;
            return true;
        }
    }
    return false;
}

bool IsBalanced(BinaryTreeNode* pRoot)
{
    depth = 0;
    return IsBalanced(pRoot,&depth);
}
