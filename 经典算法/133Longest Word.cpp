133. Longest Word
给一个词典，找出其中所有最长的单词。
class Solution {
public:
    /*
     * @param dictionary: an array of strings
     * @return: an arraylist of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
         map<int, vector<string>> hash;
    	 for (auto a : dictionary)
    		 hash[a.size()].push_back(a);
    	 
    	 auto it = hash.end();
    	 it--;
    	 return it->second;
    }
};