
描述
Count the number of prime numbers less than a non-negative number, n.
class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a integer
     */
     bool isPrime_3( int num )  
    {  
        //两个较小数另外处理  
         if(num ==2|| num==3 )  
             return 1 ;  
         //不在6的倍数两侧的一定不是质数  
         if(num %6!= 1&&num %6!= 5)  
             return 0 ;  
         int tmp =sqrt( num);  
         //在6的倍数两侧的也可能不是质数  
         for(int i= 5;i <=tmp; i+=6 )  
             if(num %i== 0||num %(i+ 2)==0 )  
                 return 0 ;  
         //排除所有，剩余的是质数  
         return 1 ;  
    }  
    int countPrimes(int n) {
        // write your code here
        int count=0;
        if(n>2)
            count=1;
        for(int i=3;i<n;i++)
        {
            if(i%2)
                count+=isPrime_3(i);
        }
        return count;
    }
};

判断质数的方法https://blog.csdn.net/huang_miao_xin/article/details/51331710