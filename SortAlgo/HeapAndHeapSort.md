# 堆和堆排序

## 1、前言

堆 `(Heap)` 这种数据结构的应用场景非常多，最经典的莫过于堆排序。

堆排序是一种原地的、时间复杂度为 `O(nlogn) `的排序算法。

前面我们知道了快速排序，平均情况下，它的时间复杂度也是 `O(nlogn) `，尽管这两个排序算法的时间复杂度都是 `O(nlogn)`，甚至堆排序比快速排序的时间复杂度还要稳定，但是，在实际的软件开发中，快排的性能要比对排序好，这是为什么呢？先留个埋点，本篇末尾会解答。

## 2、如何理解堆？

堆是一种特殊的树。

什么样的树才是堆？有两点要求， 只要满足这两点，它就是一个堆：

-  堆是一个完全二叉树；
-  堆中每一个节点的值都必须大于等于（或小于等于）其子树中每个节点的值。 

再分别解释一下这两点。 第一点，堆必须是一个完全二叉树。完全二叉树要求， 除了最后一层，其他层的节点个数都是满的，最后一层的节点都靠左排列。 

第二点，堆中每个节点的值都大于等于（或者小于等于）其左右子节点的值。 对于每个节点的值都大于等于子树中每个节点值的堆，我们叫作"大顶堆"。对于每个节点的值都小于等于子树中每个节点值的堆，我们叫作"小顶堆"。 

![check-a-heap-tree](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/check-a-heap-tree.png)

如图，其中第 1 个和第 2 个时大顶堆，第 3 个事小顶堆，第 4 个不是堆。

## 3、如何实现一个堆？

要实现一个堆之前，我们需要知道，堆都支持哪些操作以及如何存储一个堆？

从堆本身的性质来看，完全二叉树比较适合用数组来存储。用数组来存储完全二叉树其实是很完美的节省存储空间的。因为不需要存储左右子节点的指针，单纯地通过数组的下标就可以找到一个节点的左右子节点和父节点。

下面就是用数组存储堆的例子

![arr-store-heap](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/arr-store-heap.png)

从图中我们看到，数组中下标为 i 的节点的左子节点，就是下标为 ` i*2` 的节点，右子节点就是 `i*2 +1 `的节点。

父节点就是下标为 `i/2` 的节点。

### 3.1 往堆中插入一个元素

也叫堆化，分两种，从下往上和从上往下。

下面是从下往上的堆化方法。

![heapify1.png](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/heapify1.png)

堆化其实很简单，就是顺着节点所在的路径，一步步往上或者往下，对比，然后进行交换，如下图，让新插入的节点与父节点对比大小。如果不满足子节点小于等于父节点的大小关系，我们就互换两个节点，一直重复这个过程，直到满足关系。

![heapify2.png](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/heapify2.png)

堆化的代码实现

```c++
class Heap {
public:
    Heap(int cap) {
        a = new int[cap + 1];
        n = cap;
        count = 0;
    }
    void insert(int data) {
        if (count >=n) return;//堆满了
        a[++count] = data;
        int i = count;
        while ( i/2 >0 && a[i] > a[i/2]) {
            std::swap(a[i], a[i/2]);
            i /= 2;
        }//自下往上堆化
    }
    void print() {
        
    }
private:
    int *a;//存储数据 下标从 1 开始存储数据
    int n;  //堆可以存储的最大数据
    int count;//堆中已经存储的最大数据个数
};
```

### 3.2 删除堆顶元素

从堆的定义的第二条中，任何节点的值都大于等于（或小于等于）子树节点的值，我们可以发现，堆顶元素存储的就是堆中数据的最大值或者最小值。 

假设我们构造的是大顶堆，堆顶元素就是最大的元素。当我们删除堆顶元素之后，就需要把第二大的元素放到堆顶，那第二大元素肯定会出现在左右子节点中。然后我们再迭代地删除第二大节点 以此类推直到叶子节点被删除。 不过这种方法有点问题，就是最后堆化出来的堆并不满足完全二叉树的特性，会出现数组空洞。

![arr-empty-heap.png](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/arr-empty-heap.png)

实际上，还有另一种思路，可以解决这个问题，而且保证堆化之后满足完全二叉树的特性，这就是从上往下的堆化方法：

> 每次把最后一个节点放到堆顶，然后利用同样的父子节点对比，对于不满足父子节点大小关系的，互换两个节点，重复进行直到满足条件。

![heapify3.png](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/heapify3.png)

删除代码实现：

```c++
void removeMax() {
        if (count == 0) return;
        a[1] = a[count--];
        heapify(a, count, 1);
    }
    
    void heapify(int a[], int n, int i) {
        while (1) {
            int maxPos = i;
            if (i*2 <=n && a[i] < a[i*2]) { maxPos = i*2; }
            if (i*2+1 <=n && a[maxPos] < a[i*2+1]) { maxPos = i*2+1; }
            if (maxPos == i) break;
            std::swap(a[i], a[maxPos]);
            i = maxPos;
        }
    }
```

一个包含 `n` 个 节点的完全二叉树，树的高度不会超过 `log2(n)` 。 堆化的过程是顺着节点所在的路径进行交换的，所以堆化的时间复杂度跟树的高度成正比的，也就是 `O(logn)` 。插入数据和删除堆顶元素的主要逻辑就是堆化，所以，往对堆中插入元素和删除堆顶元素的时间复杂度都是 `O(logn)` 。

## 4、如何基于堆实现排序？

借助堆这种数据结构实现的排序算法，就叫做堆排序。堆排序的时间复杂度非常稳定，是  `O(nlogn)` 。 而且还是原地排序算法，如此优秀，它是怎么做到的呢？

堆排序包含两个步骤：建堆和排序。

### 4.1 建堆

首先需要将数组原地建成一个堆，所谓“原地”就是，不借助另一个数组，就在原数组上操作。

建堆的过程，可以采用从后往前处理数据的过程，并且每个数据都是从上往下堆化。因为叶子节点往下堆化只能自己和自己比较，所以可以直接从第一个非叶子节点开始，依次堆化就好。

![](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/heapify4.png)

![](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/heapify5.png)

实现代码

```c++
void buildHeap(int a[], int n) {
    for(int i=n/2; i>=1; --i) {
    heapify(a, n, i);
    }
}
void heapify(int a[], int n, int i) {
  while (1) {
   		int maxPos = i;
   		if (i*2 <=n && a[i] < a[i*2]) { maxPos = i*2; }
   		if (i*2+1 <=n && a[maxPos] < a[i*2+1]) { maxPos = i*2+1; }
   		if (maxPos == i) break;
   		std::swap(a[i], a[maxPos]);
   		i = maxPos;
   }
}
```

在上面的代码中，我们对下标 `n/2` 开始到 1 的数据进行堆化，下标是 `n/2+1` 到 `n` 的 节点是叶子节点，不需要我们堆化。实际上，对于完全二叉树来说，下标从  `n/2+1` 到 `n` 的 节点都是叶子节点。

现在，我们来看，建堆操作的时间复杂度是多少呢？

每个节点堆化的时间复杂度是  `O(logn)` ，那 `n/2 + 1`  个节点堆化的总时间复杂度不是就是  `O(nlogn)`  呢？这样算也没错，但是这个值还是不够精确。实际上，对排序的建堆过程时间复杂度是 `O(n)` 。

因为叶子节点不需要堆化，所以需要堆化的节点从倒数第二层开始，每个节点堆化的过程中，需要比较和交换的节点个数，跟这个节点的高度 `k`  成正比。

下面的图展示了每一层的节点个数和对应的高度，只需把每个节点的高度求和就是就是建堆的总时间复杂度。

每个非叶子节点的高度求和，就是下面这个公式：

![buildHeap-sum1.png](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/buildHeap-sum1.png)

利用高中学过的错位相减，得到一个等比数列，最后求和公式就是如下：

![buildHeap-sum2.png](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/buildHeap-sum2.png)

因为 `h= log2N` ，带入 `S ` ，得到 `S= O(n) ` ，所以建堆的时间复杂度就是 `O(n)`。

### 4.2 堆排序

建堆结束之后，数组中的数据已经是按照大顶堆的特性来组织的。数组中的第一个元素就是堆顶，也就是最大的元素。我们把它和最后一个元素交换，那最大元素就放到了下班为 n  的位置。

有点类似于“删除堆顶元素”：当堆顶元素移除之后，我们把下标为 n 的元素放到堆顶。

然后通过堆化的方法，将剩下的 `n-1` 个元素重新构建堆，堆化完成之后，我们再取堆顶的元素，放到下标是 `n-1`  的位置，一直重复这个过程，直到最后堆中只剩下标为 1 的一个元素，排序工作就完成了。

![heapSort.png](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/heapSort.png)



## 5、为什么在实际开发中，快速排序要比堆排序性能好？

整个堆排序的过程，只需要极个别临时存储空间，所以堆排序是原地排序算法。堆排序包括建堆和排序两个操作，建堆过程的时间复杂度是 `O(n) `，排序过程的时间复杂度是 `O(nlogn)` 。所以，堆排序整体的时间复杂度是 `O(nlogn)` 。

另外，堆排序不是稳定的排序，因为在排序的过程中，存在将堆的最后一个节点跟堆节点互换的操作，所以就有可能改变值相同数据的原始相对排序。

解答开头的问题，为什么说，在实际开发中，快速排序要比堆排序性能好？

有两个方便的原因：

### 第一点：堆排序数据访问的方式没有快速排序友好

 对于快排来说，数据是顺序访问的。而对于堆排序来说，数据是跳着访问的。比如堆排序的堆化，下面这个例子，会依次访问数组下标是 1、2、4、8的元素，而不是像快排那样，局部顺序访问，所以这样对CPU缓存来说是不友好的。

![](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/why-heapsort-better-than-sort.png)

### 第二点：对于同样的数据排序，堆排序算法的数据交换次数要多于快排

直观理解就是堆排序的第一步是建堆，建堆的过程会打乱数据原有的相对先后顺序，导致原数据的有序度降低。比如，对于一组已经有序的数据来说，经过建堆之后，数据反而变得无序了。

![why-heap-than-qsort.png](https://cdn.jsdelivr.net/gh/rongweihe/ImageHost01/images/heapSort2.png)

## 6、总结

堆是一种完全二叉树。

它最大的特性是：每个节点的值都大于等于 （或小于等于）其子树节点的值。

因此，堆被分成了两类，大顶堆和小顶堆。 

堆中比较重要的两个操作是插入一个数据和删除堆顶元素。

这两个操作都要用到堆化。插入一个数据的时候，我们把新插入的数据放到数组的最后，然后从下往上堆化；

删除堆顶数据的时候，我们 把数组中的最后一个元素放到堆顶，然后从上往下堆化。

这两个操作时间复杂度都是 O(log n)， 除此之外，我们还讲了堆的一个经典应用，堆排序。

堆排序包含两个过程，建堆和排序。我们将下标从2到1的节点，依次进行从上到下的堆化操作，然后就可以将数组中的数据组织成堆这种数据结构。接下来，我们迭代地将堆顶的元素放到堆的末尾，并将堆的大小减一，然后再堆化，重复这个过程，直到堆中只剩下一个元素，整个数组中的数据就都有序排列了。 

参考：[极客时间-数据结构与算法专栏](https://time.geekbang.org/column/intro/100017301)