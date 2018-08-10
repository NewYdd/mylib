517. 丑数
写一个程序来检测一个整数是不是丑数。

丑数的定义是，只包含质因子 2, 3, 5 的正整数。比如 6, 8 就是丑数，但是 14 不是丑数以为他包含了质因子 7。

class Solution {
public:
    /**
     * @param num: An integer
     * @return: true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // write your code here
         if (num == 1)
		    return true;
		 if(num==0)
		    return false;
    	 while (num!=1)
    	 {
    		 bool flag = false;
    		 if (num % 2 == 0) //能够被2整除
    		 {
    			 num /= 2; flag = true;
    		 }
    		 if (num % 3 == 0) //能够被2整除
    		 {
    			 num /= 3; flag = true;
    		 }
    		 if (num % 5 == 0) //能够被2整除
    		 {
    			 num /= 5; flag = true;
    		 }
    		 if (!flag)
    			 return false;
    	 }
         return true;
    }
};

链接：https://www.nowcoder.com/questionTerminal/6aa9e04fc3794f68acf8778237ba065b
来源：牛客网

class Solution {
public://别人的代码就是精简，惭愧啊，继续学习。
    int GetUglyNumber_Solution(int index) {
        if (index < 7)return index;
        vector<int> res(index);
        res[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0, i;
        for (i = 1; i < index; ++i)
        {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if (res[i] == res[t2] * 2)t2++;
            if (res[i] == res[t3] * 3)t3++;
            if (res[i] == res[t5] * 5)t5++;
        }
        return res[index - 1];
    }
};
