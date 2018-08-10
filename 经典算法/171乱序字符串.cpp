描述
给出一个字符串数组S，找到其中所有的乱序字符串(Anagram)。如果一个字符串是乱序字符串，那么他存在一个字母集合相同，但顺序不同的字符串也在S中。

所有的字符串都只包含小写字母

您在真实的面试中是否遇到过这个题？  
样例
对于字符串数组 ["lint","intl","inlt","code"]

返回 ["lint","inlt","intl"]


class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
       vector<string> anagrams(vector<string> &strs) {
    	 // write your code here
    	 vector<string> result;
    	 int length = strs.size();
    	 if (length == 0)
    		 return result;
    	 map<string, vector<int>> my;
    	 for (int i = 0; i < length; i++)
    	 {
    		 string temp = strs[i];
    		 sort(temp.begin(), temp.end());
    		 my[temp].push_back(i);
    	 }
    	 auto it = my.begin();
    	 while (it != my.end())
    	 {
    		 if (it->second.size() > 1)
    		 {
    			 for (int i = 0; i < it->second.size(); i++)
    			 {
    				 int index = it->second[i];
    				 result.push_back(strs[index]);
    			 }
    		 }
    		 it++;
    	 }
    	 return result;
     }
};

map存储下标