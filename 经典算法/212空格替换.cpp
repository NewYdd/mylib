Q：什么时候应该从后往前写？
A: 如果从前写要不断改变后面的位置的时候

设计一种方法，将一个字符串中的所有空格替换成 %20 。你可以假设该字符串有足够的空间来加入新的字符，且你得到的是“真实的”字符长度。
class Solution {
public:
    /*
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // write your code here
       int count = 0;
         for (int i = 0; i < length; i++)
    	 {
    		 if (isspace(string[i]))
    			 count++;
    	 }
    	 int newlenth = count * 2 + length;
    	 int j = 1;
    	 for (int i = length-1; i >=0; i--)
    	 {
    		 if (isspace(string[i]))
    		 {
    		     string[newlenth - j++] = '0';
    			 string[newlenth-j++] = '2';
    			 string[newlenth - j++] = '%';
    			
    		 }
    		 else
    		 {
    			 string[newlenth - j] = string[i];
    			 j++;
    		 }
    	 }
    
    	 return newlenth;
    }
};