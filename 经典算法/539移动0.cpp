class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here
        int index = 0, b = nums.size();
    	for (int i = 0; i < b; i++)
    	{
    		if (nums[i])
    		{
    			nums[index] = nums[i];
    			index++;
    		}
    	}
    	for (int i = index; i < b; i++)
    		nums[i] = 0;
    }
};