646. 第一个独特字符位置
给出一个字符串。找到字符串中第一个不重复的字符然后返回它的下标。如果不存在这样的字符，返回 -1。
class Solution {
public:
    /**
     * @param s: a string
     * @return: it's index
     */
    int firstUniqChar(string &s) {
        // write your code here
       int size = s.size();
	 int letterCount[256] = { 0 };
	 for (int i = 0; i < size; i++)
	 {
		 ++letterCount[s[i]];
	 }
	 for (int i = 0; i < size; i++)
	 {
		 if (letterCount[s[i]] == 1)
			 return i;
	 }
	 return -1;
        
    }
};

map也一样