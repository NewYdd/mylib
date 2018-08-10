class Solution {
public:
    /**
     * @param digits: a number represented as an array of digits
     * @return: the result
     */
    vector<int> plusOne(vector<int> &digits) {
        // write your code here
        int size = digits.size();
    	digits[size - 1] += 1;
    	for (int i = size - 1; i > 0; i--)
    	{
    
    		if (digits[i] <= 9)
    		{
    			return digits;
    		}
    		else
    		{
    			digits[i] = 0;
    			digits[i - 1] += 1;
    		}
    	}
    	if (digits[0] == 10)
    	{
    		digits[0] = 0;
    		digits.insert(digits.begin(), 1);
    	}
    	return digits;
    }
};

考虑9，0情况