//由于时间限制，使用分治法来寻找逆序对，在递归归并排序对基础上进行改进，当合并流程开始时，如果左边某一个数比右边某一个数大，那么左边从那一位数开始一直到结束对数都可以和右边对数构成逆序对，注意将等于的情况排除。
#include <stdio.h>

int count = 0;

void merge(int *arr, int begin, int mid, int end){
    int size_a = end - begin +1;
    int tmp[size_a];
    int left_b = begin, left_e = mid, right_b = mid+1, right_e = end;
    int i = 0;
    while(left_b <= left_e || right_b <= right_e){//左或右有一个不为空
        if(right_b > right_e || (left_b <= left_e && arr[left_b] <= arr[right_b])){//右边为空，或者左边不为空且左手牌小于右手牌，不构成逆序对。
            tmp[i++] = arr[left_b++];
        }
        else{//左手牌大于右手牌
            tmp[i++] = arr[right_b++];
            count += left_e - left_b +1;
        }
    }
    int n = begin;
    for(int j = 0; j < size_a; j++){
        arr[n++] = tmp[j];
    }
}

void divide(int *arr, int begin, int end){
    if(begin == end)
        return;

    int mid = (begin + end) / 2;
    divide(arr, begin, mid);
    divide(arr, mid+1, end);

    merge(arr, begin, mid, end);
}

void mergesort(int *arr, int n){
    divide(arr, 0,n-1);
}

int main()
{
    int times;
    scanf("%d", &times);
    while(times--){
        int n; scanf("%d", &n);
        int arr[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        count = 0;
        mergesort(arr, n);
        printf("%d\n", count);
    }
    return 0;
}
