
/*
二叉树前序中序后序遍历递归和非递归 C++实现
*/
#include <bits/stdc++.h>
using namespace std;
struct BinaryNode
{
    int m_data;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(int data):m_data(data),left(NULL),right(NULL) {}
};

//递归构造二叉平衡树
void insertNode(BinaryNode* root,int data)
{
    if(data<=root->m_data)
    {
        if(!root->left)
        {
            root->left = new BinaryNode(data);
        }
        else
        {
            insertNode(root->left,data);
        }
    }
    else
    {
        if(!root->right)
        {
            root->right = new BinaryNode(data);
        }
        else
        {
            insertNode(root->right,data);
        }
    }
}
//非递归构造平衡二叉树
void dgInsertNode(BinaryNode* root,int data)
{
    cout<<"without recursion creat BinaryNode"<<endl;
    BinaryNode* curNode;
    BinaryNode* faNode;
    BinaryNode* newNode;

    newNode = new BinaryNode(data);

    if(root == NULL)
    {
        root = newNode;
    }
    else
    {
        curNode = root;
        while(curNode!=NULL)
        {
            //判断新插入结点插在左节点还是右节点
            if(newNode->m_data<=curNode->m_data)
            {
                if(curNode!=NULL)
                {
                    faNode = curNode;
                    curNode = curNode->left;
                }
                else
                    faNode = curNode;
            }
            else
            {
                if(curNode!=NULL)
                {
                    faNode = curNode;
                    curNode = curNode->right;
                }
                else
                    faNode = curNode;
            }
        }
        //找到当前插入的位置后插入数据
        if(data<=faNode->m_data)
            faNode->left = newNode;
        else
            faNode->right= newNode;
    }
}


//递归实现
//前序遍历：根节点-》左节点-》右节点
void preOrder(BinaryNode* root)
{
    if(root==NULL)
        return ;
    else
    {
        cout<<"root->m_data"<<root->m_data<<endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

//中序遍历：左节点-》根节点-》右节点
void inOrder(BinaryNode* root)
{
    if(root==NULL)
        return ;
    else
    {
        inOrder(root->left);
        cout<<"root->m_data"<<root->m_data<<endl;
        inOrder(root->right);
    }
}

//后序遍历：左节点-》右节点-》根节点
void postOrder(BinaryNode* root)
{
    if(root==NULL)
        return ;
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<"root->m_data"<<root->m_data<<endl;
    }
}

//非递归实现
/*
前序遍历，利用栈的先进后出
[1]先让根进栈，只要栈不为空，就可以做弹出操作
[2]每次弹出一个结点，把它的左右结点都进栈
[3]若当前右孩子结点不为空，入栈;(右子树先进栈，这样可以保证右子树在栈中总处于左子树的下面)
[4]若当前左孩子结点不为空，入栈
*/
void dgPreOrder(BinaryNode* root)
{
    if(root==NULL)
        return;
    std::stack<BinaryNode*>s;
    BinaryNode* p = root;
    s.push(p);
    while(!s.empty())
    {
        BinaryNode* t = s.top();
        cout<<"root->m_data"<<t->m_data<<endl;
        s.pop();
        if(t->right)
            s.push(t->right);
        if(t->left)
            s.push(t->left);
    }
}
//非递归中序遍历
void dgInOrder(BinaryNode* root)
{
    if(root==NULL)
        return;
    std::stack<BinaryNode*>s;
    BinaryNode* p = root;// 指向当前要检查的节点
    while(NULL!=p || !s.empty())
    {
        while(NULL!=p)   // 一直向左走
        {
            s.push(p);
            p=p->left;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            cout<<"root->m_data"<<p->m_data<<endl;
            p=p->right;
        }
    }
}
//双栈法，非递归后续遍历
/*
栈s1入栈顺序：根节点-》左节点-》右节点
栈s2入栈顺序：右节点-》左节点-》根节点
出栈顺序：根节点-》左节点-》右节点
*/
void dgPostOrder(BinaryNode* root)
{
    if(root==NULL)
        return;
    std::stack<BinaryNode*>s1,s2;
    BinaryNode* p;// 指向当前要检查的节点
    s1.push(root);
    while(!s1.empty())
    {
        p = s1.top();
        s1.pop();
        s2.push(p);
        if(p->left)
            s1.push(p->left);
        if(p->right)
            s1.push(p->right);
    }
    while(!s2.empty())
    {
        cout<<"root->m_data"<<s2.top()->m_data<<endl;
        s2.pop();
    }
}
//非递归广度优先搜索-层次遍历
void leverOrder(BinaryNode* root)
{
    if(root==NULL)
        return;
    BinaryNode* p = root;// 指向当前要检查的节点
    std::queue<BinaryNode*> Q;
    Q.push(p);
    while(!Q.empty())
    {
        BinaryNode* t = Q.front();
        Q.pop();
        cout<<"root->m_data"<<t->m_data<<endl;
        if(t->left)
            Q.push(t->left);
        if(t->right)
            Q.push(t->right);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    cout<<"input"<<endl;
    int T;
    cin>>T;
    while(T--)
    {
        cout<<"root"<<endl;
        int root_data;
        cin>>root_data;
        BinaryNode root(root_data);
        cout<<"num of child"<<endl;
        int n;
        cin>>n;
        cout<<"child"<<endl;
        int num[256];
        int len=0;
        for(int i=0; i<n; ++i)
        {
            int val;
            cin>>val;
            //num[len++]=val;
            //insertNode(&root,val);
            dgInsertNode(&root,val);
        }
        /*
          2
         /\
        1  3
        */
        // 2 1 3
        std::cout<<"preOrder is:"<<endl;
        preOrder(&root);
        std::cout<<std::endl;

        //1 2 3
        std::cout<<"inOrder is:"<<endl;
        inOrder(&root);
        std::cout<<std::endl;

        //1 3 2
        std::cout<<"PosOrder is:"<<endl;
        postOrder(&root);
        std::cout<<std::endl;

        //2 1 3
        std::cout<<"PreOrder without recursion is:"<<endl;
        dgPreOrder(&root);
        std::cout<<std::endl;

        //1 2 3
        std::cout<<"inOrder without recursion is:"<<endl;
        dgInOrder(&root);
        std::cout<<std::endl;

        //1 3 2
        std::cout<<"PosOrder without recursion is:"<<endl;
        dgPostOrder(&root);
        std::cout<<std::endl;

        //2 1 3
        std::cout<<"BroadOrder is:"<<endl;
        leverOrder(&root);
    }
    return 0;
}
