#include <iostream>

using namespace std;

void merge(int *a, int begin, int mid, int end, int layer){
    if(layer < 3)
        return;

    int length = end - begin +1;
    int temp[length];
    int n = begin; int m = mid +1;
    int i = 0;
    while(n <= mid || m <= end){
        if(m > end || (n <= mid && a[n] < a[m])){
            temp[i++] = a[n++];
        }
        else{
            temp[i++] = a[m++];
        }
    }
    int a_n = begin;
    for(int i = 0; i < length;i++){
        a[a_n++] = temp[i];
    }
}

void divide(int *a, int begin, int end, int mark){
    if(begin == end)
        return;
    int mid = (begin + end) / 2;
    int layer = mark;
    divide(a, begin, mid, mark+1);
    divide(a, mid+1, end, mark+1);

    merge(a, begin, mid, end, layer);
}

void mergesort(int *a, int n){
    int mark = 1;
    divide(a, 0, n-1, mark);
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
        mergesort(a, n);

        for(int i = 0; i < n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}
