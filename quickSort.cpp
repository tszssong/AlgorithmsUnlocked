// quickSort.cpp : 快排、插入排序、选择排序、归并排序 by 大松。


#include "stdafx.h"
#include "vector"
#include "iostream"
#define MYMAX 2000	//假设要排序的数组元素不超过2000
using namespace std;
// 快排的解释：算法之美-11.4.3，本程序和书里示例代码不全一样，书里以数组第一个元素为基准，这里以中间元素为基准。
// i作为左指针，从左往右找，找到大于nums[m]停止；j作为右指针，从右往左找，找到小于nums[m]停止；交换i、j所指元素；继续直到相遇
void quickSort(vector<int>& nums, int l, int r)
{
	int i = l, j = r;
	int m = l + (r - l) / 2;
	while (i < j){
		while (nums[i] <= nums[m] && i < m) i++;
		while (nums[j] >= nums[m] && j > m) j--;
		if (j == m) m = i;
		else if (i == m) m = j;	//此处必须用else，否则上个if刚把j值给m，这一句又把i给m了
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	if (l<m-1)
		quickSort(nums, l, m - 1);
	if (m+1<r)
		quickSort(nums, m+1 , r);
	
}
//保证前i个元素已经排好序，每次插入当前值
void insertSort(vector<int>& nums){
	for (int i = 1; i < nums.size(); i++){
		int key = nums[i];
		for (int j = i - 1; j >= 0; j--){
			if (nums[j]>key){
				int temp = nums[j];
				nums[j] = key;
				nums[j + 1] = temp;
			}
			else{
				break;
			}
		}
	}
}
//保证每次将i~n之间的最小值放在i处
void selectSort(vector<int>& nums){
	for (int i = 0; i < nums.size(); i++){
		int idx_small = i;
		for (int j = i + 1; j < nums.size(); j++){
			if (nums[j] < nums[idx_small])
				idx_small = j;
		}
		int temp = nums[i];
		nums[i] = nums[idx_small];
		nums[idx_small] = temp;
	}
}
void merge(vector<int>& nums, int l, int m, int r){
	vector<int> B(m-l+2), C(r-m+1);
	int i = 0, j = 0;
	for ( i = 0; i < m - l + 1; i++ )
		B[i] = nums[l+i];
	for ( j = 0; j < r-m; j++ )
		C[j] = nums[m+1+j];
	B[i] = MYMAX;	//最后放上一个最大值
	C[j] = MYMAX;   //这样下面的while循环里就不需要判断是否到达数组末尾
	int k = l;
	i = 0, j = 0;
	while (k <= r)
	{
		if (B[i] <= C[j])
			nums[k++] = B[i++];
		else
			nums[k++] = C[j++];
	}
}
void mergeSort(vector<int>& nums, int l, int r){
	if (l >= r) return;
	else{
		int m = l + (r - l) / 2;
		mergeSort(nums, l, m);	//无限二分下去
		mergeSort(nums, m + 1, r);
		//进入此函数的条件：nums在m左、右均已排好序
		merge(nums, l, m, r);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int nums[] = { 3, 20, 7, 8, 1, 2, 8, 9, 2, 4,  5, 6, 1, 10, 100, -5};
	vector<int> myVector(nums, nums + sizeof(nums) / sizeof(int));
	//quickSort(myVector, 0, myVector.size()-1);
	//insertSort(myVector);
	//selectSort(myVector);
	mergeSort(myVector, 0, myVector.size()-1);
	for (int i = 0; i < myVector.size(); i++)
		cout << myVector[i] << ' ';
	cout << endl;
	
	while (1);
	return 0;
}

