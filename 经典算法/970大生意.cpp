class Solution {
public:
    /**
     * @param a: The cost of the film
     * @param b: The price of the selling of the film
     * @param k: The principal
     * @return: The answer
     */
    int bigBusiness(vector<int> &a, vector<int> &b, int k) {
	// Write your code here
	vector<pair<int, int>>temp;
	for (int i = 0; i < a.size(); i++) {
		temp.push_back(make_pair(a[i], b[i]));
	}
	sort(temp.begin(), temp.end());
	for (auto it : temp) {
		if (it.first < it.second && it.first <= k) {
			k += it.second - it.first;
		}
	}
	return k;
	}
};

贪心算法，只买赚钱的电影。从便宜的开始买