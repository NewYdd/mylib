#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include<unordered_map> 
#include<map>

using namespace std;
//tip1  2sum 从数组中寻找两个数和为目标值，返回下标  
/*用key值表示值，用value表示标号 建立hash表*/
vector<int> find2sum(int arr[], int n, int target)
{
	vector<int> result;
	unordered_map<int, int> hash(n);
	for (int i = 0; i < n; ++i)
	{	
		if (hash.find(target - arr[i]) != hash.end())
		{
			result.push_back(hash[target - arr[i]]);
			result.push_back(i + 1);
		}
		else
		{
			hash[arr[i]] = i + 1;
		}
	}

	return result;
}

//tip2 3sum 从数组找出a,b,c 相加等于0，并且结果必须为从小到大排列
/* 排序+2sum*/
vector<vector<int>> find3sum(vector<int> &arr)
{
	sort(arr.begin(), arr.end());
	int n = arr.size();
	vector<vector<int>> result;

	for (int i = 0; i < n-2; ++i)
	{
		vector<int> temp;
		temp.push_back(arr[i]);
		unordered_map<int, int> hash(n);
		int target = 0 - arr[i];

		for (int j= i+1; j < n; ++j)
		{
			if (hash.find(target - arr[j]) != hash.end())
			{
				temp.push_back(arr[j]);
				temp.push_back(target-arr[j]);
			}
			else
			{
				hash[arr[j]] = j;
			}
		}
		if (temp.size() == 3)
			result.push_back(temp);
	}

	return result;
}

//tip3 从数组删除重复元素 不能分配多余空间   ：先排序再处理
int removeSame(vector<int> &nums)
{
	sort(nums.begin(), nums.end());

	int len = nums.size();
	int newIndex = 0;
	for (int i = 1; i< len; ++i) {
		if (nums[i] != nums[newIndex]) {
			newIndex++;
			nums[newIndex] = nums[i];
		}
	}
	for (int i = 0; i < len - newIndex-1; i++)
		nums.pop_back();
	return newIndex + 1;
}
/* 允许出现两次*/
int removeSame2(vector<int> &nums)
{
	sort(nums.begin(), nums.end());

	int len = nums.size();
	int newIndex = 1;
	for (int i = 2; i < len; ++i) {
		if (nums[i] != nums[newIndex] || nums[i] != nums[newIndex - 1]) {
			++newIndex;
			nums[newIndex] = nums[i];
		}
	}
	for (int i = 0; i < len - newIndex - 1; i++)
		nums.pop_back();
	return newIndex + 1;
}

//tip4 合并两有序数组，并且为排序数组 默认数组A有足够多的空间给B ,初始A元素m个，B元素n个
void mergeSortArray(int A[], int m, int B[], int n)
{
	int index = m + n - 1;
	while (m > 0 && n > 0)
	{
		if (A[m - 1] > B[n - 1])
		{
			A[index] = A[m - 1];
			--m;
		}
		else
		{
			A[index] = B[n - 1];
			--n;
		}
		--index;
	}
	while (n > 0)
	{
		A[index] = B[n - 1];
		--n;
		--index;
	}
}

//tip5 合并两有序数组到一个新数组
vector<int> merge2(vector<int> &a, vector<int> &b)
{
	vector<int> result;
	if (a.empty() && b.empty())
		return result;
	if (a.empty()) return b;
	if (b.empty())return a;

	int size_a = a.size();
	int size_b = b.size();

	int i = 0, j = 0;
	while (i < size_a&&j < size_b)
	{
		if (a[i] < b[j])
		{
			result.push_back(a[i]);
			++i;
		}
		else
		{
			result.push_back(b[j]);
			++j;
		}
	}
	while (i<size_a)
	{
		result.push_back(a[i]);
		++i;
	}
	while (j<size_b)
	{
		result.push_back(b[j]);
		++j;
	}

	return result;
}

//tip6 寻找中位数 （若先排序在输出中位数下标 时间负载都为O(nlogn)）
//利用快排找出数组前半个长度较大的数
int quickSort_(int a[], int left, int right, int size)
{
	int l = left, r = right;
	int t = a[l];

	while (l < r)
	{
		while (a[r] >= t&&l < r) r--;
		while (a[l] <= t&&l < r) l++;
		swap(a[l], a[r]);
	}
	swap(a[left], a[r]);

	for (int j = 0; j < 11; ++j)
		cout << a[j] << " ";
	cout << endl;

	if (r - left + 1 == size) //左半边长度为原数组长度一半
		return a[r];
	else if (r - left + 1 > size) //左半边长度长了
	{
		cout << "left" << ": ";
		return	quickSort_(a, left, r - 1, size);
	}
	else
	{
		cout << "right" << ": ";
	     return	quickSort_(a, r + 1, right, size-(r-left+1));
	}
}
int median(int a[], int n)
{
	return quickSort_(a, 0, n - 1, (n+1)/2);

}

//tip7 将整数数组中的奇数偶数分开，奇数在前，偶数在后 ****
void  part(int a[], int n)
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		while (i < j && a[i] % 2 != 0)i++;
		while (i < j && a[j] % 2 == 0)j--;
		if (i != j) swap(a[i], a[j]);
	}

}

// tip8 quick sort 快速排序
void quickSort(int a[], int left,int right,int size)
{
	for (int j = 0; j <size; ++j)
		cout << a[j] << " ";
	cout << endl;
	
	if (left > right)
		return;
	int l = left, r = right;
	int t = a[l];

	while (l < r)
	{
		while (a[r] >= t&&l<r) r--;
		while (a[l] <= t&&l<r) l++;
		swap(a[l], a[r]);
	}
	swap(a[left], a[r]);
	
	quickSort(a, left, r - 1,size);//左侧
	quickSort(a, r+1, right,size);//右侧
}

int main()
{
	int a[] = { 6,1,2,0,9,3,4,5,10,8,7 };
	cout<< median(a, 11);
	
	cout << endl;



	system("PAUSE");

	return 0;
}