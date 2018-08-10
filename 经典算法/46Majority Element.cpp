46. Majority Element
给定一个整型数组，找出主元素，它在数组中的出现次数严格大于数组元素个数的二分之一。
class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        // write your code here
         int result = 0;
    	 map<int, int> my;
    	 for (auto a : nums)
    		 my[a]++;
    	 int max = 0;
    	 for(auto a:my)
    		 if (a.second > max)
    		 {
    			 max = a.second;
    			 result = a.first;
    		 }
    
    	 return result;
    }
};

 int majorityNumber(vector<int> &nums) {
	 // write your code here
	 int value=nums[0], count = 0;
	 int size = nums.size();
	 for (int i = 1; i < size; i++)
	 {
		 if (value == nums[i])
			 count++;
		 else
			 count--;
		 if (count < 0)
			 value = nums[i];
	 }
	 return value;
 }
1)map
2)设置一个count来计数，一个value为数组第一个元素。遍历数组，当数组中的元素与value相等时，就将count++；当数组中的元素与value不相等时，就将count--。如果count值小于0，那么就将value设置为当前的数组元素。那么遍历到最后一个元素的时候，value即为主元素了。空间复杂度降低
3)排序求中位数