给出一个整数数组 nums 和一个整数 k。划分数组（即移动数组 nums 中的元素），使得：

所有小于k的元素移到左边
所有大于等于k的元素移到右边
返回数组划分的位置，即数组中第一个位置 i，满足 nums[i] 大于等于 k。
class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
       int partitionArray(vector<int> &nums, int k) {
    	 // write your code here
    	 if (nums.size() == 0)
    		 return 0;
    	 int index = -1;
    	 int i = 0, j = nums.size() - 1;
    	 for (; i < j; )
    	 {
    		 while (nums[i] < k && i < j)i++;
    		 while (nums[j] >=k && i < j)j--;
    		 swap(nums[i], nums[j]);
    	 }
    	 if (j==nums.size()-1)
    	    index=j+1;
    	 else
    	    index=j;
    	 for (auto a : nums)
    		 cout << a << " ";
    	 return index;
    
     }
};

//需要考虑都小于k时，返回size