#include <iostream>

using namespace std;


int main()
{
    int m;
    cin >> m;
    while(m > 0){
        int n, k;
        int price[100000] = {0};
        cin >> n >> k;
        int dp[n+1];
        for(int i = 0; i < k; ++i){
            int tem;
            cin >> tem;
            cin >> price[tem];
        }
        dp[0] = 0; //dp[i]表示钢条长度为i时得到的最大收益
        for(int i = 1; i <=n; ++i){
            int temp = INT32_MIN;
            for(int j = 1; j <= i; ++j){
                temp = temp > (price[j]+dp[i-j]) ? temp : (price[j]+dp[i-j]);// 表示i长度的钢条减去j的最大收益
            }
            dp[i] = temp;
        }
        cout << dp[n] << endl;
        m--;
    }
    return 0;
}