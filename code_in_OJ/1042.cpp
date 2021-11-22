#include <iostream>
#include <algorithm>
using namespace std;
 
 
int mincostTickets(int days[], int costs[],int n){//n表示计划旅游的天数 
//一年有365天，所以days里可能有366项，所以new一个大小为366的数组，
//因为后面会计算i-1,i-7,i-30，会下标溢出，所以把数组大小增大为396，然后把所有的日子全部向后推移30天防止溢出。
	int dp[396]={0};//dp[i]表示从第1天到第i天的最低花费包括当天的费用+票费 
	int dayCost = costs[0];//日票 
	int weekCost = costs[1];//周票 
	int monthCost = costs[2];//月票 
	for(int i = 0; i < n; i++){
		dp[days[i] + 30] = -1;//初始化days[i]在dp中对应的值 
	}
	for(int i = 31; i < 396; i++){
		if(dp[i] == 0){//第i天不在计划内 
			dp[i] = dp[i-1];//最低花费等于前一天的值 
		}else{
			dp[i] = min(min(dp[i-1] + dayCost, dp[i-7] + weekCost), dp[i-30] + monthCost);
		} 
	} 
	return dp[days[n-1] + 30];//动态规划数组最后一个值即为最优解 
}
 
int main(){
	int nums;
	cin >> nums;
	while(nums--){
		int m;
		cin >> m;
		int costs[3], days[366], dp[396];
		for(int i = 0; i < m; i++){
			cin >> days[i];
		}
		cin >> costs[0] >> costs[1] >> costs[2];
		cout << mincostTickets(days, costs, m) << endl;
		
	} 
	return 0;
}