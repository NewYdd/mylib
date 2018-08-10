class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(!source ||!target )
            return -1;
        const int lenth_target =strlen(target);
		const int lenth_source =strlen(source);
		
        if(lenth_target > lenth_source)
		    return -1;
		if(!lenth_source && lenth_target)
            return -1;
    
		for(int i = 0;i < lenth_source-lenth_target +1;++i)
		{
			int j = 0;
			for(;j < lenth_target;++j)
			{
				if(target[j]!=source[i+j]) break;
			}
			if(j == lenth_target ) return i;
		}
		return -1;
    }
};

考虑空字符串 以及两者均为空应返回0