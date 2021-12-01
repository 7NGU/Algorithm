#include <iostream>
#include <string>

using namespace std;


int main()
{
    int m;
    cin >> m;
    while(m > 0){
        string s1, s2;
        cin >> s1 >> s2;
        int l1 = s1.size(), l2 = s2.size();
        int dp[l1+1][l2+1];// d[i][j]表示字符串1到i位置，字符串到j位置时最长公共子序列长度。
        for(int i = 0; i < l1; ++i){
            dp[i][0] = 0;
        }
        for(int j = 0; j < l2; ++j){
            dp[0][j] = 0;
        }
        for(int i = 1; i <= l1; ++i){
            for(int j = 1; j <= l2; ++j){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else{
                    dp[i][j] = dp[i-1][j] >= dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
                }
            }
        }
        cout << dp[l1][l2] << endl;
        m--;
    }
    return 0;
}