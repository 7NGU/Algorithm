//用较快的时间找到数组中是否有两个数的和为指定值，运用分治的思想，先对数组进行排序，然后从a[0]开始对数组之后的部分进行二分查找（traget=need-a[i]）
//注意两点，一是二分查找的终止条件不应包括begin==end，因为需要对最边上的值也进行判定，二是不要忘记mid移动的判断条件。ps:一开始测试使用的循环条件要记得更新。。。
#include <stdio.h>

int state = 0;

void partition(int *a, int begin, int end){
    if(begin > end)
        return;

    int p = begin;
    for(int i = begin+1; i <= end; i++){
        if(a[begin] > a[i]){
            int temp = a[p+1];
            a[p+1] = a[i];
            a[i] = temp;
            p++;
        }
    }
    int temp = a[begin];
    a[begin] = a[p]; a[p] = temp;

    partition(a, begin, p-1);
    partition(a, p+1, end);
}

void Quicksort(int *a, int size){
    partition(a, 0, size-1);
}

void Binary(int *a, int begin, int end, int number){
    if(begin > end)
        return;

    int mid = (begin + end) / 2;
    if(a[mid] == number){
        state = 1;
        printf("yes\n");
        return;
    }
    else if(a[mid] > number){
        Binary(a, begin, mid-1, number);
    }
    else {
        Binary(a, mid + 1, end, number);
    }
}

int main(){
    int times; scanf("%d\n", &times);
    while(times--){
        int n, need;
        scanf("%d %d\n", &n, &need);
        int a[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }

        Quicksort(a, n);

        for(int i = 0; i < n; i++){
            state = 0;
            int target = need - a[i];
            Binary(a, i+1, n-1, target);
            if(state == 1)
                break;
        }
        if(state == 0)
            printf("no\n");
    }
    return 0;
}
