55. 比较字符串
比较两个字符串A和B，确定A中是否包含B中所有的字符。字符串A和B中的字符都是 大写字母

样例
给出 A = "ABCD" B = "ACD"，返回 true

给出 A = "ABCD" B = "AABC"， 返回 false

class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: if string A contains all of the characters in B return true else return false
     */
    bool compareStrings(string &A, string &B) {
        // write your code here
        int a_size = A.size(), b_size = B.size();
    	if (a_size < b_size)
    		return false;
    	unordered_map<char, int> map;
    	for (char a : A)
    		map[a]++;
    	for (char b : B)
    	{
    		map[b]--;
	     	if (map[b] < 0)
		    	return false;
    	}
    	return true;
    }
};