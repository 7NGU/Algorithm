#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 22, K = 22;
int m, n, k;
// 各位数字
int srcNum[N];
// 缓存
long long val_mem[N][N];

// 提取第st位到第ed位数字
long long getNum(int st, int ed){
	long long val = 0;
	for (int i = st; i <= ed; i++){
		val = val * 10 + srcNum[i];
	}
	return val;
}

// 第0个数到第i个数中插入k个乘号得到的最大值
long long getVal(int i, int k){
	// 若有缓存则直接返回
	if (val_mem[i][k]){
		return val_mem[i][k];
	}

	// 插0个乘号，就是直接返回那段数字
	if (k == 0){
		return val_mem[i][k] = getNum(0, i);
	}

	long long ans = 0;
	// 状态转移，乘号数k单调递减，递归
	for (int i2 = k - 1; i2 < i; i2++){
		ans = max(
			ans, 
			getVal(i2, k - 1) * getNum(i2 + 1, i)
		);
	}
	return val_mem[i][k] = ans;
}


int main()
{
	// 测试getNum()函数用
	// for (int i = 0; i < 5; i++)
	// 	scanf("%d", &srcNum[i]);

	// for (int i = 0; i < 3; i++){
	// 	int st, ed;
	// 	scanf("%d%d", &st, &ed);
	// 	printf("%d", getNum(st, ed));
	// }

	// input
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &n, &k);
		
		// each input
		char temp[50];
		scanf("%s", temp);
		for (int j = 0; j < n; j++){
			srcNum[j] = temp[j] - '0';
		}

		// init val_mem
		memset(val_mem, 0, sizeof(val_mem));

		// calcualte answer
		long long ans = getVal(n - 1, k);

		// output
		printf("%lld\n", ans);
	}

	return 0;
}