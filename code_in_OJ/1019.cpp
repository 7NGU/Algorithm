#include <iostream>

using namespace std;

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
        int dp[n+1][c+1];
        for(int j = 0; j <= min(stone[n][0]-1, c); ++j){
            dp[n][j] = 0;
        }
        for(int j = stone[n][0]; j <=c; ++j){
            dp[n][j] = stone[n][1];
        }

        for(int i = n-1; i >= 1; --i){
            for(int j = 0; j <= min(stone[i][0], c); ++j){
                dp[i][j] = dp[i+1][j];
            }
            for(int j = stone[i][0]; j <= c; ++j){
                dp[i][j] = max(dp[i+1][j], dp[i+1][j-stone[i][0]] + stone[i][1]);
            }
        }
        if(c < stone[1][0]) dp[1][c] = dp[2][c];
        else dp[1][c] = max(dp[2][c], dp[2][c-stone[1][0]] + stone[1][1]);
        /*
         * dp[i][j] = dp[i+1][j]  0 <= j < weight_i
         * dp[i][j] = max(dp[i+1][j], dp[i+1][j-weight_i] + value_i) j >= weight_i
         * dp[n][j] = 0 0 <= j < weight_n
         * dp[n][j] = value_n j >= weight_n
         */
        cout << dp[1][c] << endl;
	// Another method use d[j]
	int d[n+1];
	d[0] = 0;// else d[j] could also init as 0.
	for(int j = 1; j <= n; ++j){
		d[j] = max(d[j-1], d[j-stone[j][0]] + stone[j][1]);
	} 
	cout << d[n] << endl;
        m--;
    }
    return 0;
}#include <iostream>

using namespace std;

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
        int dp[n+1][c+1];
        for(int j = 0; j <= min(stone[n][0]-1, c); ++j){
            dp[n][j] = 0;
        }
        for(int j = stone[n][0]; j <=c; ++j){
            dp[n][j] = stone[n][1];
        }

        for(int i = n-1; i >= 1; --i){
            for(int j = 0; j <= min(stone[i][0], c); ++j){
                dp[i][j] = dp[i+1][j];
            }
            for(int j = stone[i][0]; j <= c; ++j){
                dp[i][j] = max(dp[i+1][j], dp[i+1][j-stone[i][0]] + stone[i][1]);
            }
        }
        if(c < stone[1][0]) dp[1][c] = dp[2][c];
        else dp[1][c] = max(dp[2][c], dp[2][c-stone[1][0]] + stone[1][1]);
        /*
         * dp[i][j] = dp[i+1][j]  0 <= j < weight_i
         * dp[i][j] = max(dp[i+1][j], dp[i+1][j-weight_i] + value_i) j >= weight_i
         * dp[n][j] = 0 0 <= j < weight_n
         * dp[n][j] = value_n j >= weight_n
         */
        cout << dp[1][c] << endl;
//        for(int i = 1; i <= n; ++i){
//            for(int j = 1; j <= c; ++j){
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
        m--;
    }
    return 0;
}
