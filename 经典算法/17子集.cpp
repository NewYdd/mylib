描述
给定一个含不同整数的集合，返回其所有的子集

子集中的元素排列必须是非降序的，解集必须不包含重复的子集

class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    void subsetHelper(vector<int>& source, int ind, vector<vector<int>>& result) {

	 vector<int> subset;
	 //1. 退出：当集合只有一个元素时
	 //2. ［1，2］的每个子集都添加［3］
	 //3. ［1，2］的子集与加3后的子集合合并
	 //1
	 if (ind == 0) {
		 result.push_back(subset);   //add null set
		 subset.push_back(source[0]);
		 result.push_back(subset);
		 return;
	 }

	 subsetHelper(source, ind - 1, result);

	 vector<vector<int>> ori = result;//复制集合

									  //2
	 int i = 0;
	 for (i = 0; i < result.size(); i++) {
		 result[i].push_back(source[ind]);
	 }

	 //3
	 result.insert(result.end(), ori.begin(), ori.end());

 }

 vector<vector<int>> subsets(vector<int> &nums) {
	 vector<vector<int>> result;
	 subsetHelper(nums, nums.size() - 1, result);
	 return result;
 }

};

[1,2,3]的子集：[ [], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3] ]
[1,2]   的子集：[ [], [1], [2], [1,2] ]
[1]      的子集：[ [], [1] ]

求123的子集的过程就是：[1,2]的子集里每个元素末尾加3，再并上原来的[1,2]。
抽象下就是：对前一个元素的结果进行处理即得到当前元素的结果。
类似于：