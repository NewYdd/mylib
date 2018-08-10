
172. 删除元素
给定一个数组和一个值，在原地删除与值相同的数字，返回新数组的长度。

元素的顺序可以改变，并且对新的数组不会有影响。

样例
给出一个数组 [0,4,4,0,0,2,4,4]，和值 4
class Solution {
public:
    /*
     * @param A: A list of integers
     * @param elem: An integer
     * @return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        if(A.empty())
            return 0;
        sort(A.begin(), A.end());

    	int len = A.size();
    	int newIndex = 0;
    	for (int i = 0; i< len; ++i) {
    		if (A[i] != elem) {
    			A[newIndex] = A[i];
    			newIndex++;
    		}
    	}
    	for (int i = 0; i < len - newIndex; i++)
    		A.pop_back();
    	return newIndex;
    }