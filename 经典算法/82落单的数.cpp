class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        // write your code here
        int size = A.size();
    	int result = 0;
    	for (int i = 0; i < size; i++)
    	{
    		result ^= A[i];
    	}
    	return result;
    }
};
思路可以这样设计，既然位运算中“异或”的操作能消去同样的整数，那么，如果我们对整个数组从前到后异或（第一个数异或第二个，得到的结果再异或第三个。。。），这样一来，只要是数组中成对出现的元素，到最后都能相互抵消（与这两个成对的数是否相邻无关）。也就是说这样依次异或，最后得到的结果就是那个落单的数。