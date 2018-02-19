#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include<unordered_map> 
#include<map>

using namespace std;

//tip1 返回删除指定元素后的数组长度
/*	容器删除 erase var.erase( iterator pos )*/int remoElement(vector<int> &array, int element)
{
	for (auto it = array.begin(); it < array.end(); ++it)
	{
		if (*it == element)
		{
			it = array.erase(it);
			--it;
		}
	}
	return array.size();
}
int remoElement2(int A[], int n, int elem)
{
	for (int i = 0; i < n; ++i) {
		if (A[i] == elem) {
			A[i] = A[n - 1];
			--i;
			--n;
		}
	}

	return n;
}


// tip2 Zero Sum Subarray 寻找数组中 子数组元素和为0
vector<int> zeroSub(int arr[], int n) //两重for 复杂度O(n^2)
{ 
	vector<int> result;
	for (int i = 0; i < n; i++)
	{
		int sum = arr[i];
		for (int j = i + 1; j < n; j++)
		{
			sum += arr[j];
			if (sum == 0)
			{
				result.push_back(i);
				result.push_back(j);
				break;
			}
		}
	}
	return result;
}
vector<int> zeroSub2(int arr[], int n) //f(i)表示从0到i元素之和 ，nums[i] 表示从数组下标 0 开始至下标 i 的和。子串和为0，
									  //也就意味着存在不同的 f(i1) - f(i2) = 0;
{
	vector<int> result;

	int curr_sum = 0;
	vector<int> sum_i;
	for (int i = 0; i<n; ++i) 
	{
		curr_sum += arr[i];
		if (0 == curr_sum) {
			result.push_back(0);
			result.push_back(i);
		}

		vector<int>::iterator iter = find(sum_i.begin(), sum_i.end(), curr_sum);// find 函数
		if (iter != sum_i.end()) {
			result.push_back(iter - sum_i.begin() + 1);
			result.push_back(i);
		}
		sum_i.push_back(curr_sum);
	}
	return result;
}
vector<int> zeroSub3(int arr[], int n) //hash 表 find 函数时间为线性	若为unordered_map 效率更高写
{
	vector<int> result;
	unordered_map<int, int> hash;
	hash[0] = 0;

	int curr_sum = 0;
	for (int i = 0; i <n; ++i) {
		curr_sum += arr[i];
		if (hash.find(curr_sum) != hash.end()) {
			result.push_back(hash[curr_sum]);
			result.push_back(i);
		}
		else {
			hash[curr_sum] = i + 1;
		}
	}
	return result;
}

//tip4 Recover Rotated Sorted Array [4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]  反转题考虑三步法
// 考虑三步法，寻找分割点，（1）反转前半部分为54 （2）反转后半为321 （3）整体反转
void reverse(vector<int> &nums, vector<int>::size_type start, vector<int>::size_type end) {
	for (vector<int>::size_type i = start, j = end; i < j; ++i, --j) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
}
void recoverRotatedSortedArray(vector<int> &nums)
{
	for (vector<int>::size_type index = 0; index != nums.size() - 1; ++index) {
		if (nums[index] > nums[index + 1]) {
			reverse(nums, 0, index);
			reverse(nums, index + 1, nums.size() - 1);
			reverse(nums, 0, nums.size() - 1);
			return;
		}
	}
}

int main()
{
	int a[] = {0, -3,1,2,-3,4 };
	vector<int> result;
	result = zeroSub3(a, 5);
	for (auto b : result)
		cout << b << " ";
	system("PAUSE");

	return 0;
}