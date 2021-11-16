#include <iostream>
#include <cstring>
using namespace std;

#define ll long long

ll min(ll a, ll b){
    return a < b ? a : b;
}

ll max(ll a, ll b){
    return a > b ? a : b;
}

ll  sum[100];
ll dp[100][100];

int main()
{
    int m;
    cin >> m;
    while(m > 0){
        int n, k;
        cin >> n >> k;
        ll nums[n+1];
        sum[0] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> nums[i];
            sum[i] = sum[i-1] + nums[i];
        }
        memset(dp, 0 , sizeof(dp));
        for(int i = 1; i <=n; ++i){
            dp[i][0] = sum[i];
        }
        for(int i = 2; i <=n; ++i){
            for(int j = 1; j <= k; ++j){
                for(int t = 2; t <= i; ++t){
                    ll s = sum[i] - sum[t-1];
                    dp[i][j] = max(dp[t-1][j-1]*s, dp[i][j]);
                }
            }
        }
        cout << dp[n][k] << endl;
        m--;
    }
    return 0;
}
/*
 * dp(n, k) n表示前n个数， k表示具有k个乘号
 * 转移方程dp(n, k) = max_{k <= t <= n}(dp(t, c-1)*sum[vi])
 */