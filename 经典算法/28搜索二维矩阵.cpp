28. 搜索二维矩阵
写出一个高效的算法来搜索 m × n矩阵中的值。

这个矩阵具有以下特性：

每行中的整数从左到右是排序的。
每行的第一个数大于上一行的最后一个整数。

class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
    	 if(matrix.empty())
	         return false;
        
         int row = matrix.size(), column=matrix[0].size();
	     int target_r=0;
	 //consider only one row

    	 for (int i = 0; i < row; i++)
    	 {
    		 if (matrix[i][0] > target)
    		 {
    			 if (i == 0)
    				 target_r = i;
    			
    			 else
    				 target_r = i - 1;
    			 break;
    		 }
    		 else
    			 target_r = i;
    	 }
    
    	 for (int i = 0; i < column; i++)
    	 {
    		 if (matrix[target_r][i] == target)
    			 return true;
    	 }
    	 return false;
    }
};

考虑只有一行，或者为空