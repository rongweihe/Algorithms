
//字典树Trie模板
//Author:github.com/rongweihe
//Date:2019/05/14
#include <bits/stdc++.h>
using namespace std;

//链表法，客观易懂
struct TrieNode
{
    //每个字母的次数
    //小写字母 26 大写字母 52
    int cnt;
    struct TrieNode* next[26];
    TrieNode()
    {
        cnt=0;
        memset(next,NULL,sizeof(next));
    }
};

TrieNode *root = NULL;

void buildTrie(string &str)
{
    int len = str.size();
    TrieNode *p = root;
    TrieNode *tmp = NULL;
    for(int i=0; i<len; ++i)
    {
        //该前缀没出现过，新建一个节点保存该前缀
        if(p->next[str[i]-'a'] == NULL)
        {
            tmp = new TrieNode();
            p->next[str[i]-'a'] = tmp;
        }
        p = p->next[str[i]-'a'];
        p->cnt++;
    }
}
int findTrie(string &str)
{
    int len = str.size();
    TrieNode *p = root;
    for(int i=0; i<len; ++i)
    {
        //如果匹配不到返回0
        if(p->next[str[i]-'a'] == NULL)
        {
            return 0;
        }
        p = p->next[str[i]-'a'];
    }
    //返回匹配的次数
    return p->cnt;
}

//数组法。效率快
const int maxn = 1e5+233;
struct Trie
{
    //word[i][j]表示第i层转换为ASSII码下标为j的字符出现的次数
    int word[maxn][26];
    int sz;
    int sum[maxn];//从根节点到i层的前缀字符串在trie树匹配的次数
    Trie()
    {
        sz=1;
        memset(word,0,sizeof(word));
        memset(sum,0,sizeof(sum));
    }
    void insertTrie(string &str)
    {
        int u=0,c,len=str.size();
        cout<<"str="<<str<<endl;
        for(int i=0; i<len; ++i)
        {
            c=str[i]-'a';
            if(!word[u][c])
            {
                word[u][c]=sz++;
               // cout<<"u=c=word[u][c]="<<u<<" "<<c<<" "<<word[u][c]<<endl;
            }
            u=word[u][c];
            sum[u]++;
            //cout<<"u=sum[u]="<<u<<" "<<sum[u]<<endl;
        }
    }
    int findTrie(string &str)
    {
        int u=0,c,len=str.size();
        for(int i=0; i<len; ++i)
        {
            c=str[i]-'a';
            if(word[u][c])
                u=word[u][c];
            else
                return 0;
        }
        return sum[u];
    }
} st;
int main()
{
//    freopen("in.txt","r",stdin);
//    string str;
//    root = new TrieNode();
//    while(getline(cin,str))
//    {
//        if(str.empty()) break;
//        buildTrie(str);
//    }
//    while(getline(cin,str))
//    {
//        printf("%d\n", findTrie(str));
//    }
//    return 0;

//    freopen("in.txt","r",stdin);
//    string str;
//    while(getline(cin,str))
//    {
//        if(str.empty())
//            break;
//        st.insertTrie(str);
//    }
//    while(getline(cin,str))
//    {
//        printf("%d\n", st.findTrie(str));
//    }
//    return 0;
}

/*
Sample Input
banana
band
bee
absolute
acm

ba
b
band
abc
Sample Output
2
3
1
0
*/
