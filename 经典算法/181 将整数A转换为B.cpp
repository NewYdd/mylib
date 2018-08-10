181. 将整数A转换为B
如果要将整数A转换为B，需要改变多少个bit位？

样例
如把31转换为14，需要改变2个bit位。

(31)10=(11111)2

(14)10=(01110)2

class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: An integer
     */
    int bitSwapRequired(int a, int b) {
         int c = a^b;
    	 int count = 0;
    	 for (int i = 0; i < 32; i++)
    	 {
    		 count += c & 1;
    		 c >>= 1;
    	 }
    	 return count;
        // write your code here
    }
};


考虑负数，右移为算术右移，会自动补上符号位。