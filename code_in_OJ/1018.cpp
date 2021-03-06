#include <iostream>

using namespace std;

const int INF = 1000000;

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int main()
{
    int m;
    cin >> m;
    while(m > 0){
        int n, c;
        cin >> n >> c;
        int stone[n+1][2];  // stone[i][0]->weight, stone[i][1]->value
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < 2; ++j){
                cin >> stone[i][j];
            }
        }
//        int dp[n+1][c+1];
//        for(int j = 0; j <= min(stone[n][0]-1, c); ++j){
//            dp[n][j] = 0;
//        }
//        for(int j = stone[n][0]; j <=c; ++j){
//            dp[n][j] = stone[n][1];
//        }
//        for(int i = n-1; i >= 1; --i){
//            for(int j = 0; j <= min(stone[i][0], c); ++j){
//                dp[i][j] = dp[i+1][j];
//            }
//            for(int j = stone[i][0]; j <= c; ++j){
//                dp[i][j] = max(dp[i+1][j], dp[i+1][j-stone[i][0]] + stone[i][1]);
//            }
//        }
//        if(c < stone[1][0]) dp[1][c] = dp[2][c];
//        else dp[1][c] = max(dp[2][c], dp[2][c-stone[1][0]] + stone[1][1]);
        int dp[c+1];
        dp[0] = 0;
        for(int i = 1; i <= c; ++i){
            dp[i] = -INF;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = c; j >= stone[i][0]; --j){
                dp[j] = max(dp[j], dp[j-stone[i][0]] + stone[i][1]);
            }
        }

        if(dp[c] < 0) dp[c] = 0;

        cout << dp[c] << endl;
        /*
         * dp[i][j] = dp[i+1][j]  0 <= j < weight_i
         * dp[i][j] = max(dp[i+1][j], dp[i+1][j-weight_i] + value_i) j >= weight_i
         * dp[n][j] = 0 0 <= j < weight_n
         * dp[n][j] = value_n j >= weight_n
         */

        m--;
    }
    return 0;
}