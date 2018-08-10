
####  二维数组中的查找
在一个二维数组中每行每列都是递增排序的。查找某个数字 。
class Solution {
public:
    /*
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
  bool find(int *matrix,int rows,int columns,int number)
{
    bool found=false;
   if(matrix!=NULL && rows>0&&columns>0)
    {  
        int row=0;
        int column=columns-1;
        while(row<rows&& column>=0)
        {
                if(maxtrix[row*columns+column]==number)
                {
                    found=true;
                    break;
                }
                else if(maxtrix[row*columns+column]>number)
                        column--;
                else
                    row++;                
        }
     }
    return found;
}
};