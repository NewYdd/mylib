class Solution {
public:
    /**
     * @param ages: The ages
     * @return: The answer
     */
    int friendRequest(vector<int> &ages) {
        // Write your code here
        int size = ages.size();
    	int sum = 0;
    	for (int i = 0; i < size; i++)
    	{
    		for (int j = i+1; j < size; j++)
    		{
    			if (ages[i] <= ages[j] / 2 + 7 || ages[i] > ages[j] || ages[i] < 100 && ages[j]>100) {}
    			else
    				sum++;
    
    			if (ages[j] <= ages[i] / 2 + 7 || ages[j] > ages[i] || ages[j] < 100 && ages[i]>100) {}
    			else
    				sum++;
    		}
    
    	}
    	return sum;
    }
};

暴力枚举，A-》B和 b-》a不同