#include <iostream>

using namespace std;

int main()
{
    int m;
    cin >> m;
    while(m > 0){
        int n, res;
        cin >> n;
        int nums[n][2];
        int dp[n][n];
        for(int i = 0; i < n; ++i){
            cin >> nums[i][0] >> nums[i][1];
            dp[i][i] = 0;
        }
        if(n == 1) res = 0;
        else if(n == 2) res = nums[0][0] * nums[0][1] * nums[1][1];
        else{
            for(int i = 0; i < n; ++i){
                dp[i][i] = 0;
            }
            for(int L = 1; L < n; ++L){//实现对角线循环的插入间隔值
                for(int i = 0; i < n-L; ++i){ //行
                    int j = i + L; //列
                    if(j > n-1) break;
                    dp[i][j] = 9999999;
                    for(int k = i; k < j; k++){ // 断点位置k
                        int q = dp[i][k] + dp[k+1][j] + nums[i][0] * nums[k][1] * nums[j][1];
                        dp[i][j] = q < dp[i][j] ? q : dp[i][j];
                    }
                }
            }
            res = dp[0][n-1];
        }
        cout << res << endl;
        m--;
    }
    return 0;
}