描述
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
1 -> A
2 -> B
3 -> C

class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a string
     */
    string convertToTitle(int n) {
        // write your code here
        string result;
    	 while (n)
    	 {
    		 result.push_back(n % 26 + 64);
    		 n /= 26;
    	 }
    	reverse(result.begin(), result.end());
        return result;
    }
    
};