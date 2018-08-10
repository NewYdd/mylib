class Solution {
public:
    /**
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        // write your code here
        long long origin = num;
    	long long result=0;
    	do 
    	{
    		result = result * 10 + num % 10;
    	
    	} while (num/=10);
    	if (result == origin)
    		return true;
    	else
    		return false;
        }
};