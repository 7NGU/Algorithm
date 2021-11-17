#include <iostream>
#include <cstring>

using namespace std;


struct point{
    int start;
    int end;
    int val;
    int ans;
};

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

void partition(point *a, int begin, int end){
    if(begin >= end)//递归终止条件
        return;
    //找到基准值的排好序位置p

    int p = begin;

    for(int i = begin+1; i <= end; i++){
        if(a[i].end < a[begin].end){//将比基准元素小的元素交换排列到基准元素的后面，基准元素是第一个
            point temp = a[p+1];
            a[p+1] = a[i];
            a[i] = temp;
            p++;
        }
    }
    point temp = a[begin];
    a[begin] = a[p]; a[p] = temp;

    //递归调用
    partition(a, begin, p-1);
    partition(a, p+1, end);
}

void Quicksort(point *a, int size){
    partition(a, 0, size-1);
}



int main()
{
    int m;
    cin >> m;
    while(m > 0){
        int n;
        cin >> n;
        point p[n];
        memset(&p, 0, sizeof(point)*n);
        for(int i = 0; i < n; ++i){
            cin >> p[i].start >> p[i].end >> p[i].val;
        }

        Quicksort(p, n); //根据活动结束时间排序

//        for(int i = 0; i < n; ++i){
//            cout << p[i].start << p[i].end << p[i].val << p[i].ans << " ";
//        }
//        cout << endl;

        int maxn = 0;
        for(int i = 0; i < n; ++i){
            int pre = 0;
            for(int j = i-1; j >= 0; --j){
                if(p[i].start >= p[j].end){//边界可以重合
                    pre = p[j].ans;
                    maxn = max(maxn, pre + p[i].val);
                    break;
                }
                if(j == 0) maxn = max(maxn, pre + p[i].val);
            }
            if(i == 0) maxn = max(maxn, pre + p[i].val);
            p[i].ans = maxn;
        }
        cout << maxn << endl;
        m--;
    }
    return 0;
}
