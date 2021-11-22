#include <iostream>
using namespace std;
const int maxmn = 1001;
int a[maxmn][maxmn];
 
int main(){
	int nums;
	cin >> nums;
	while(nums--){
		int m, n, target;
		cin >> m >> n >> target;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		int x = m-1, y = 0;
		bool flag = false;
		while(x >=0 && y <= n-1){//从二维矩阵左下角开始搜索 
			if(a[x][y] == target){
				flag = true;
				break;
			}else if(a[x][y] > target){//往上方搜索 
				x--;
			}else if(a[x][y] < target){//往右边搜索 
				y++;
			} 
		}
		if(flag)
            cout << "true" << endl;
        else
            cout << "false" << endl;
	}
	return 0;
}