class Solution {
public:
    /**
     * @param num: a non-negative integer
     * @return: one digit
     */
    int addDigits(int num) {
        if (!(num / 10))
		return num;
    	int temp = num;
    	int sum = 0;
    	do
    	{
    		sum += temp % 10;
    	} while (temp /= 10);
    	addDigits(sum);
        // write your code here
    }
};