// quickSort.cpp : ���š���������ѡ�����򡢹鲢���� by ���ɡ�


#include "stdafx.h"
#include "vector"
#include "iostream"
#define MYMAX 2000	//����Ҫ���������Ԫ�ز�����2000
using namespace std;
// ���ŵĽ��ͣ��㷨֮��-11.4.3�������������ʾ�����벻ȫһ���������������һ��Ԫ��Ϊ��׼���������м�Ԫ��Ϊ��׼��
// i��Ϊ��ָ�룬���������ң��ҵ�����nums[m]ֹͣ��j��Ϊ��ָ�룬���������ң��ҵ�С��nums[m]ֹͣ������i��j��ָԪ�أ�����ֱ������
void quickSort(vector<int>& nums, int l, int r)
{
	int i = l, j = r;
	int m = l + (r - l) / 2;
	while (i < j){
		while (nums[i] <= nums[m] && i < m) i++;
		while (nums[j] >= nums[m] && j > m) j--;
		if (j == m) m = i;
		else if (i == m) m = j;	//�˴�������else�������ϸ�if�հ�jֵ��m����һ���ְ�i��m��
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	if (l<m-1)
		quickSort(nums, l, m - 1);
	if (m+1<r)
		quickSort(nums, m+1 , r);
	
}
//��֤ǰi��Ԫ���Ѿ��ź���ÿ�β��뵱ǰֵ
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
//��֤ÿ�ν�i~n֮�����Сֵ����i��
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
	B[i] = MYMAX;	//������һ�����ֵ
	C[j] = MYMAX;   //���������whileѭ����Ͳ���Ҫ�ж��Ƿ񵽴�����ĩβ
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
		mergeSort(nums, l, m);	//���޶�����ȥ
		mergeSort(nums, m + 1, r);
		//����˺�����������nums��m���Ҿ����ź���
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

