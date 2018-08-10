class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
     void reverse(string &str, int start, int end)
    {

    	for(int i=start,j=end;i<j;++i,--j)
	    	swap(str[i],str[j]);
    }   
    void rotateString(string &str, int offset) {
        // write your code here
        int size = str.size();
        if(str.empty())
            return;
        offset=offset%size;
    	reverse(str, 0, size - offset-1);
    	reverse(str, size - offset, size-1);
    	reverse(str, 0, size-1);
    }
};

考虑为空字符串