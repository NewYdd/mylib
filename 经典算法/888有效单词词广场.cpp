class Solution {
public:
    /**
     * @param words: a list of string
     * @return: a boolean
     */
    bool validWordSquare(vector<string> &words) {
        // Write your code here
        int size = words.size();
    	int count = words[0].size();
    	if (count != size)
    		return false;
    	for (int i = 0; i < count; i++)
    	{
    		string target = words[i];
    		string word;
    		for(int j=0;j<size;j++)
    		{
    			if (i < words[j].size())
    				word.push_back(words[j][i]);
    			else
    				break;
    		}
    		if (word != target)
    			return false;
    	}
    	return true;
    }
};