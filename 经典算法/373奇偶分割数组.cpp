373. 奇偶分割数组
分割一个整数数组，使得奇数在前偶数在后

class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int i = 0, j = nums.size() - 1;
    	while (i < j)
    	{
    		while (i < j && nums[i] % 2 != 0)i++;
    		while (i < j && nums[j] % 2 == 0)j--;
    		if (i != j) swap(nums[i], nums[j]);
    	}
    }
};

不改变顺序
void InsertionSort(int A[], int n)
{
	for (int i = 1; i < n; i++)         // 类似抓扑克牌排序
	{
		int get = A[i];					// 右手抓到一张扑克牌
		int j = i - 1;                  // 拿在左手上的牌总是排序好的
		if (get % 2 == 0) //如果是偶数
			A[j + 1] = get;
		else
		{
			while (j >= 0 && A[j]%2==0)    // 将抓到的牌与手牌从右向左进行比较
			{
				A[j + 1] = A[j];            // 如果该手牌比抓到的牌大，就将其右移
				j--;
			}
			A[j + 1] = get; // 直到该手牌比抓到的牌小(或二者相等)，将抓到的牌插入到该手牌右边(相等元素的相对次序未变，所以插入排序是稳定的)
		}
	}
}