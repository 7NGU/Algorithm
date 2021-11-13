//DP
#include <iostream>

using namespace std;

int main()
{
    int m;
    cin >> m;
    while(m > 0){
        int n;
        cin >> n;
        int a[n], d[n];
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            d[i] = 1;
        }
        int res = 0;
        if(n == 1){
            res = 1;
        }
        else{
            for(int i = n-2; i >= 0; --i){
                for(int j = i+1; j < n; ++j){
                    if(a[i] <= a[j] && d[i] < d[j]+1){
                        d[i] = d[j]+1;
                    }
                }
            }
            for(int i = 0; i< n; i++){
                if(res < d[i]){
                    res = d[i];
                }
            }
        }
        cout << res << endl;

        m--;
    }
    return 0;
}