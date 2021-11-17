#include <iostream>

using namespace std;

class point{
public:
    int start;
    int end;
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
        for(int i = 0; i < n; ++i){
            cin >> p[i].start >> p[i].end;
        }

        Quicksort(p, n); //根据活动结束时间排序

        int dp[n+1];
        int maxn = 1;
        int j = 0;
        for(int i = 1; i < n; ++i){ // 贪心，根据结束时间排序进行遍历判断
            if(p[i].start > p[j].end){
                maxn += 1;
                j = i;
            }
        }
        cout << maxn << endl;

        m--;
    }
    return 0;
}
