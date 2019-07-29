/*
【京东电话面试题目1】
假设现有一个数组A里的元素有N个，把N个元素分配M个其他数组，
要求分配到每个M数组里的元素个数平均。如果总数N不能整除M，
那么就分配的接近，也就是最后分配的和其他分配的差别一个。 给出思路和方法都可以

【思路】：
在A中遍历每一个元素，依次给M个其他数组各分配一个元素，
如果A中仍有元素，再如此循环，直到A中所有元素都分配完毕
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+233;
int n,m,T;
vector<int>a;
int main()
{
    //freopen("in.txt", "r", stdin);
    cin>>n>>m;
    for(int i=0; i<n; ++i)
    {
        int v;
        cin>>v;
        a.push_back(v);
    }
    vector<vector<int> >b(m,vector<int>(0));
    for(int i=0; i<n; ++i)
    {
        b[i%m].push_back(a[i]);
    }
    for(int i=0; i<m; ++i)
    {
        cout<<"b[i].size()="<<b[i].size()<<endl;
        for(int j=0; j<b[i].size(); ++j)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
b[i].size()=4
1 4 7 10
b[i].size()=3
2 5 8
b[i].size()=3
3 6 9

Process returned 0 (0x0)   execution time : 0.110 s
Press any key to continue.
*/

/*
海量数据排序，内存有限
*/
【思路一】先快排再多路归并
2、1TB数据使用32GB内存如何排序
　　①、把磁盘上的1TB数据分割为40块（chunks），每份25GB。（注意，要留一些系统空间！）
　　②、顺序将每份25GB数据读入内存，使用quick sort算法排序。
　　③、把排序好的数据（也是25GB）存放回磁盘。
　　④、循环40次，现在，所有的40个块都已经各自排序了。（剩下的工作就是如何把它们合并排序！）
　　⑤、从40个块中分别读取25G/40=0.625G入内存（40 input buffers）。
　　⑥、执行40路合并，并将合并结果临时存储于2GB 基于内存的输出缓冲区中。当缓冲区写满2GB时，写入硬盘上最终文件，并清空输出缓冲区；当40个输入缓冲区中任何一个处理完毕时，写入该缓冲区所对应的块中的下一个0.625GB，直到全部处理完成。

3、继续优化
　　磁盘I/O通常是越少越好（最好完全没有），那么如何降低磁盘I/O操作呢？关键就在第5和第6步中的40路输入缓冲区，我们可以先做8路merge sort，把每8个块合并为1路，然后再做5-to-1的合并操作。
　　再深入思考一下，如果有多余的硬件，如何继续优化呢？有三个方向可以考虑：
　　使用并发：如多磁盘（并发I/O提高）、多线程、使用异步I/O、使用多台主机集群计算。
　　提升硬件性能：如更大内存、更高RPM的磁盘、升级为SSD、Flash、使用更多核的CPU。
　　提高软件性能：比如采用radix sort、压缩文件（提高I/O效率）等。
【思路二】分区再多路归并排序，类似桶排序，桶与桶之间无序，桶内有序
