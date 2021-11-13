#include <stdio.h>


int max_Number(int a, int b){
    if(a > b)
        return a;
    else
        return b;

}

int subset(int *a, int begin, int end){
    if(begin == end)
        return a[begin];
    int mid = (begin + end) / 2;
    int l_max = subset(a, begin, mid);//最大子序列在左边
    int r_max = subset(a, mid+1, end);//最大子序列在右边
    //最大子序列跨越两边
    int sum_l = 0, max_l = a[mid], sum_r = 0, max_r = a[mid+1];
    for(int i = mid; i >= begin; i--){
        sum_l += a[i];
        max_l = max_Number(max_l, sum_l);
    }
    for(int i = mid+1; i <= end; i++){
        sum_r += a[i];
        max_r = max_Number(max_r, sum_r);
    }
    int m_max = max_l + max_r;

    return max_Number(m_max, max_Number(l_max, r_max));

}

int main()
{
    int times; scanf("%d", &times);
    while(times--){
        int n; scanf("%d", &n);
        int a[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }

        int max = subset(a, 0, n-1);

        printf("%d\n", max);
    }

    return 0;
}