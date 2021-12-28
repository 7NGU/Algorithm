#include <iostream>

using namespace std;

int main()
{
    int m;
    cin >> m;
    while(m--){
        int n;
        cin >> n;
        int p[2*n];
        for(int i = 0; i < 2 * n; ++i){
            cin >> p[i];
        }

        int len = 0;
        for(int i = 0; i < 2 * n; ++i){
            if(p[i] == -1){
                continue;
            }
            for(int j = i+1; j < 2 * n; ++j){
                if(p[i] != p[j] && p[j] != -1){
                    len += (j - i);
                    p[j] = -1;
                    break;
                }
            }
        }
        cout << len << endl;
    }
    return 0;
}