 158. Valid Anagram
写出一个函数 anagram(s, t) 判断两个字符串是否可以通过改变字母的顺序变成一样的字符串。

 bool anagram(string &s, string &t) {
	 // write your code here
	 int size = s.size();
	 if (s != t.size)
		 return false;
	 int letterCount[256] = { 0 };
	 for (int i = 0; i < size; i++)
	 {
		 ++letterCount[s[i]];
		 --letterCount[t[i]];
	 }
	 for (int i = 0; i < 256; i++)
	 {
		 if (letterCount[i])
			 return false;
	 }
	 return true;
 }
 
 class Solution {
public:
    /**
     * @param s: The first string
     * @param t: The second string
     * @return: true or false
     */
    bool anagram(string &s, string &t) {
        // write your code here
        int size = s.size();
	    if (size != t.size())
		    return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s==t)
            return true;
    }
};