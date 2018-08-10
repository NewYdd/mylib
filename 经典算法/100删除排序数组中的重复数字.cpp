class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        
        if(nums.empty())
            return 0;
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
        // write your code here
    }
};

//tip3 从数组删除重复元素 不能分配多余空间   ：先排序再处理 双指针