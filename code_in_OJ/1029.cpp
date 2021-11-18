#include <iostream>
#include <cstring>

using namespace std;

int pre[15000];

struct edge{
    int start;
    int end;
    int len;
};

void init(int n){
    for(int i = 0; i <= n; i++){
        pre[i] = i;
    }
}

int Find(int x){
    int r = x;
    while(pre[r] != r)
        r = pre[r];
    int i = x, j;
    while(pre[i] != r){
        j = pre[i];
        pre[i] = j;
        i = j;
    }
    return r;
}

void partition(edge *a, int begin, int end){
    if(begin >= end)//递归终止条件
        return;
    //找到基准值的排好序位置p

    int p = begin;

    for(int i = begin+1; i <= end; i++){
        if(a[i].len < a[begin].len){//将比基准元素小的元素交换排列到基准元素的后面，基准元素是第一个
            edge temp = a[p+1];
            a[p+1] = a[i];
            a[i] = temp;
            p++;
        }
    }
    edge temp = a[begin];
    a[begin] = a[p]; a[p] = temp;

    //递归调用
    partition(a, begin, p-1);
    partition(a, p+1, end);
}

void Quicksort(edge *a, int size){
    partition(a, 0, size-1);
}



int main()
{
    int m;
    cin >> m;
    while(m > 0){
        int n, e;
        cin >> n >> e;
        edge p[e];
        memset(&p, 0, sizeof(edge)*e);
        for(int i = 0; i < e; ++i){
            cin >> p[i].start >> p[i].end >> p[i].len;
        }
        /*
         * 首先对len进行从小到大的排序
         * 开始将边加入集合，判断加入的边是否是同一个集合，若是则不加入，不是就加入（Kruskal Algorithm）
         * 便利完成后判断图中存在的集合是不是只有一个，若是说明最小生成树构建成功，若不是说明构建失败，返回-1
         * ps:对节点是否属于同一个集合的判断可以用并查集进行优化
         */
        // sort according to length of edge
        Quicksort(p, e);

        // traverse and union
        /*
         * 每个节点自身是一个树
         * 遍历边集（剔除重复边集合）判断加入该边后点集是否成环
         * 遍历结束判断是否构建成功
         */

        //对是否成功构建最小生成树进行判断


//        for(int i = 0; i < e; ++i){
//            cout << p[i].start << p[i].end << p[i].len << " ";
//        }
//        cout << endl;

        m--;
    }
    return 0;
}
