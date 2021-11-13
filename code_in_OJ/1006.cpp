#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapsort_adj(int *a, int len, int i){
    int min = i;
    int l_s = i * 2 +1;
    int r_s = i * 2 +2;
    if(l_s < len && a[min] >= a[l_s]){
        min = l_s;
    }
    if(r_s < len && a[min] > a[r_s]){
        min = r_s;
    }

    if(min != i){
        swap(&a[min], &a[i]);
        heapsort_adj(a, len, min);
    }
}


void Heapsort(int *a, int len){
    //下标为i的节点的父节点下标：(i-1)/2
    //下标为i的节点的左孩子下标：i*2 +1
    int i;
    //建堆
    for(i = len/2 -1; i >=0; --i){
        heapsort_adj(a, len, i);
    }

    //sort
//    for(i = len-1; i > 0; --i){
//        swap(&a[i], &a[0]);
//        heapsort_adj(a, i, 0);
//    }
}

int main()
{
    int m;
    scanf("%d", &m);
    while(m > 0){
        int n;
        scanf("%d", &n);
        int a[n];
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }

        Heapsort(a, n);

        for(int i = 0; i < n; ++i){
            printf("%d", a[i]);
            if(i != n-1){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
        --m;
    }
    return 0;
}