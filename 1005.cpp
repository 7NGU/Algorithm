//在快速排序的基础上对前两次的排序结果进行记录，其流程是找到基准值对确定位置，即将比其小对放在右侧，比其大对放在左侧，然后运用分治的思路对左右进行递归划分。值得注意的是原地对基准元素进行排序对过程。
//
// Created by 王政御 on 2021/9/16.
// Quicksort

#include <stdio.h>
#include <math.h>

int res[1000] = {0};
//int depth = 0;

void partition(int *a, int begin, int end, int layer){
    if(begin >= end)//递归终止条件
        return;
    //找到基准值的排好序位置p

    int p = begin;

    for(int i = begin+1; i <= end; i++){
        if(a[i] < a[begin]){//将比基准元素小的元素交换排列到基准元素的后面，基准元素是第一个
            int temp = a[p+1];
            a[p+1] = a[i];
            a[i] = temp;
            p++;
        }
    }
    int temp = a[begin];
    a[begin] = a[p]; a[p] = temp;

    if(layer == 1){
        res[p] = a[p];
    }
    else if(layer == 2){
        for(int i = begin; i <= end; i++){
            res[i] = a[i];
        }
    }

    //递归调用
    partition(a, begin, p-1, layer+1);
    partition(a, p+1, end, layer+1);
}

void Quicksort(int *a, int size){
    int layer = 1;
    partition(a, 0, size-1, layer);
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

        //depth = floor(log(n)/log(2));

        Quicksort(a, n);

        for(int i = 0; i <n; i++){
            printf("%d ", res[i]);
        }
        printf("\n");
    }

    return 0;
}

