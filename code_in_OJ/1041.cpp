//常规做法，两个数组合并排序后根据索引找到中位数。
#include <iostream>

using namespace std;

void merge(int *a, int begin, int mid, int end){
    int length = end - begin +1;
    int temp[length];
    int n = begin; int m = mid +1;
    int i = 0;
    while(n <= mid || m <=end){
        if(m > end || (n <= mid && a[n] < a[m])){
            temp[i++] = a[n++];
        }
        else{
            temp[i++] = a[m++];
        }
    }
    int a_n = begin;
    for(int i = 0; i < length; ++i){
        a[a_n++] = temp[i];
    }
}

void divide(int *a, int begin, int end){
    if(begin == end)
        return;
    int mid = (begin+end) /2;

    divide(a, begin, mid);
    divide(a, mid+1, end);

    merge(a, begin, mid, end);
}

void mergesort(int *a, int n){
    divide(a, 0, n-1);
}


int main()
{
    int m;
    cin >> m;
    while(m > 0){
        int l_a, l_b;
        cin >> l_a >> l_b;
        int n_t = l_a + l_b;
        int res[n_t];
        int a[l_a];
        for(int i = 0; i < l_a; ++i){
            cin >> a[i];
            res[i] = a[i];
        }
        int b[l_b];
        for(int i = 0; i < l_b; ++i){
            cin >> b[i];
            res[i+l_a] = b[i];
        }

        mergesort(res, n_t);

//        for(int i = 0; i < n_t; i++){
//            cout << res[i] << " ";
//        }

        double mid_num = 0.0;
        mid_num = n_t % 2 == 0 ? (res[n_t / 2] + res[(n_t/2) - 1])/2.0 : res[(n_t - 1) / 2];
        cout << mid_num << endl;

        m--;
    }
    return 0;
}