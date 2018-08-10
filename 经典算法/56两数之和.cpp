class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> result;
    	int n = numbers.size();
    	unordered_map<int, int> hash(n);
    
    	for (int i = 0; i < n; ++i)
    	{
    		if (hash.find(target - numbers[i]) != hash.end())
    		{
    			result.push_back(hash[target - numbers[i]]);
    			result.push_back(i );
    		}
    		else
    		{
    			hash[numbers[i]] = i ;
    		}
    	}
    	return result;
    }
};