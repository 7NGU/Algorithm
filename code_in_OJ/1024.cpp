#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int m;
    cin >> m;
    while(m > 0){
        int n;
        cin >> n;
        int nums[n];
        double p[n+1];
        double q[n+1];
        double sum_q = 0;
        for(int i = 0; i < n; ++i){
            cin >> nums[i];
        }
        for(int i = 1; i < n+1; ++i){
            cin >> p[i];
        }
        p[0] = -1.0;
        for(int i = 0; i < n+1; ++i){
            cin >> q[i];
            sum_q += q[i];
        }
        double dp[n+2][n+2];
        double w[n+2][n+2];
        int root[n+1][n+1];
        for(int i = 1; i <= n+1; ++i){
            dp[i][i-1] = q[i-1];
            w[i][i-1] = q[i-1];
        }
        for(int l = 1; l <= n; ++l){
            for(int i = 1; i <= n - l + 1; ++i){
                int j = i + l - 1;
                dp[i][j] = 999999;
                w[i][j] = w[i][j-1] + p[j] + q[j];
                for(int r = i; r <= j; ++r){
                    double t = dp[i][r-1] + dp[r+1][j] + w[i][j];
                    if(t < dp[i][j]){
                        dp[i][j] = t;
                        root[i][j] = r;
                    }
                }
            }
        }
        printf("%.6f\n", dp[1][n] - sum_q);
        m--;
    }
    return 0;
}