415. 有效回文串
给定一个字符串，判断其是否为一个回文串。只考虑字母和数字，忽略大小写。
class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
         if (s.empty()) return true;
		 int i = 0, j = s.size() - 1;
		 while (i < j)
		 {
			 while (i<j&&!isalnum(s[i]))i++;
			 while (i<j&&!isalnum(s[j]))j--;
			 if (tolower(s[i]) != tolower(s[j]))
				 return false;
			 i++; j--;
		 }
		 return true;
    }
};

考虑空字符串