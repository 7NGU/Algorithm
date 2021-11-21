#include <iostream>
using namespace std;
int reversePairs(int a[], int left, int right, int temp[]); 
int mergeAndCount(int a[], int left, int mid, int right, int temp[]);
 
int reversePairs(int a[], int n){
	if(n < 2){//数组元素只有一个或者零个则不存在逆序对 
		return 0;
	}
	int *copy = new int[n];
	for(int i = 0; i < n; i++){//先拷贝一份原来的数组 
		copy [i] = a[i];
	} 
	int *temp = new int[n];//辅助数组temp用来归并两个有序数组 
	return reversePairs(copy, 0, n-1, temp); 
} 
 
int reversePairs(int a[], int left, int right, int temp[]){//计算从区间left-right里逆序对的个数并进行排序 
	if(left == right){//递归终止条件：当数组里只存在一个元素时，一定不存在逆序对 
		return 0;
	} 
	int mid = left + (right - left) / 2;//不写成(left+right)/2是为了防止整型溢出
	int leftPairs =  reversePairs(a, left, mid, temp);//左半部分逆序对个数
	int rightPairs = reversePairs(a, mid+1, right, temp);//右半部分逆序对个数
	if(a[mid] <= a[mid+1]){//左区间和右区间拼接后已经有序，不用再归并 
		return leftPairs + rightPairs; 
	} 
	int crossPairs = mergeAndCount(a, left, mid, right, temp);//把上面左右两个区间合并一下
	return leftPairs + rightPairs + crossPairs; 
}
 
int mergeAndCount(int a[], int left, int mid, int right, int temp[]){
//函数执行前提：左区间left-mid里元素是有序的，右区间mid+1-right里元素是有序的
	for(int i = left; i <= right; i++){
		temp[i] = a[i];
	} 
	int i = left;//指向左区间的第一个元素
	int j = mid + 1;//右区间的第一个元素
	int count = 0;//统计逆序对个数 
	
	for(int k = left; k <= right; k++){
		if(i == mid + 1){//左区间或者右区间里的元素必然会有一个先归并完，所以我们只要将剩余的元素复制到a里即可
			a[k] =  temp[j++]; 
		}else if(j == right + 1){//右区间先归并完了 
			a[k] = temp[i++]; 
		}else if(temp[i] <= temp[j]){//把较小的那个先归并回a 
			a[k] = temp[i++];
 
		}else{//每次当右区间有元素归并回a时，就要计算逆序数 
			a[k] = temp[j++];
			count += (mid - i + 1);//指定定区间逆序数对的计算公式 
		}
	} 
	
	return count;
}
 
int main(){
	int m;
	cin >> m;
	while(m--){
		int n;
		cin >> n;
		int *a = new int[n];
		int *temp = new int[n];
		for(int i = 0; i < n; i++) 
			cin >> a[i];
		cout << reversePairs(a, 0, n-1, temp) << endl;
		delete []a;
		delete []temp; 
	} 
 
	return 0;
}