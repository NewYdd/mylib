描述
给定一个包含 n 个整数的排序数组，找出给定目标值 target 的起始和结束位置。

如果目标值不在数组中，则返回[-1, -1]

您在真实的面试中是否遇到过这个题？  
样例
给出[5, 7, 7, 8, 8, 10]和目标值target=8,

返回[3, 4]

挑战
时间复杂度 O(log n)

class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
     //查找最后一次出现
 int binarySearchLast(vector<int> &arr, int key)
 {
     if(arr.empty())
        return -1;
	 int left = 0;
	 int right = arr.size() - 1;
	 int mid;

	 while (left < right) {
		 mid = left+(right - left) / 2+1;
		 if (key < arr[mid]) {//key在左边
			 right = mid - 1;
		 }
		 else  {//key在右边
			 left = mid ;
		 }
	 }
	 return arr[left] == key ? left:-1;
 }
  int binarySearchFirst(vector<int> &arr, int key)
 {
     if(arr.empty())
        return -1;
	 int left = 0;
	 int right = arr.size() - 1;
	 int mid;

	 while (left < right) {
		 mid = left+(right - left) / 2;
		if (arr[mid] < key) {//key在右边
            left = mid + 1;
        } else {
           right=mid;
        }
	 }
	  return arr[right] == key ? right:-1;
 }
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> result;
        result.push_back(binarySearchFirst(A,target));
        result.push_back(binarySearchLast(A,target));
        return result;
    }
};