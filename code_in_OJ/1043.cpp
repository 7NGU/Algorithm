#include <iostream>
#include <algorithm>
 
using namespace std;
int dp[10001][101] = {0};
 
int superEggDrop(int N, int K){// dp[i][j]：一共有 i 层楼梯的情况下，使用 j 个鸡蛋的最少实验的次数
// 注意：K表示鸡蛋数，N表示楼层数 
// 1、i 表示的是楼层的大小，不是第几层的意思，例如楼层区间 [8, 9, 10] 的大小为 3，这一点是在状态转移的过程中调整的定义
// 2、j 表示可以使用的鸡蛋的个数，它是约束条件，我个人习惯放在后面的维度，表示消除后效性的意思
 
// 0 个楼层和 0 个鸡蛋的情况都需要算上去，虽然没有实际的意义，但是作为递推的起点，被其它状态值所参考  
// 初始化：填写下标为 0、1 的行和下标为 0、1 的列
// 第 0 行：楼层为 0 的时候，不管鸡蛋个数多少，都测试不出鸡蛋的 F 值，故全为 0
    for (int j = 0; j <= K; j++) {
            dp[0][j] = 0;
    }
 
    // 第 1 行：楼层为 1 的时候，0 个鸡蛋的时候，扔 0 次，1 个以及 1 个鸡蛋以上只需要扔 1 次
    dp[1][0] = 0;
    for (int j = 1; j <= K; j++) {
        dp[1][j] = 1;
    }
 
    // 第 0 列：鸡蛋个数为 0 的时候，不管楼层为多少，也测试不出鸡蛋的 F 值，故全为 0
    // 第 1 列：鸡蛋个数为 1 的时候，这是一种极端情况，要试出 F 值，最少次数就等于楼层高度（想想复杂度的定义）
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
        dp[i][1] = i;
    }
 
    // 从第 2 行，第 2 列开始填表
    for (int i = 2; i <= N; i++) {//i-楼层数，j-鸡蛋数 
        for (int j = 2; j <= K; j++) {
             // 在区间 [1, i] 里确定一个最优值（二分查找法） 
            int left = 1;
            int right = i;
            while (left+1 < right) {
                int mid = left + (right - left) / 2;//这么写是为了防止溢出 
                
                int breakCount = dp[mid - 1][j - 1];
                int notBreakCount = dp[i - mid][j];
                if (breakCount > notBreakCount) {//鸡蛋破了 
                    right = mid;//往下找 
                } else if(breakCount < notBreakCount){//鸡蛋没破 
                    left = mid;//往上找 
                }else{
                    right = left = mid;
                }
            }
                
        dp[i][j] = 1 + min(max(dp[left - 1][j - 1], dp[i - left][j]), 
		max(dp[right - 1][j - 1], dp[i - right][j]));
            
        }
    }
    return dp[N][K];
}
 
int main(){
	int nums;
	cin >> nums;
	while(nums--){
		int K, N;
		cin >> K >> N;//K表示鸡蛋数,N表示楼层数 
		cout << superEggDrop(N, K) << endl; 
	}
	return 0;
}