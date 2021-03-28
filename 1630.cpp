class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
  		int n = nums.size();
  		int m = l.size();
		vector<int> ans;

		for (int ii = 0; ii < m; ii++) {
			int l_elem = l[ii];
			int r_elem = r[ii];

			if ((r_elem - l_elem) < 2)
				ans.push_back(true);
			vector<int> vec(nums.begin() + l_elem, nums.begin() + r_elem);
			sort(vec.begin(), vec.end());
			int diff = vec[1] - vec[0];
			for (int jj = 2; jj < vec.size(); jj++) {
				if ((vec[jj] - vec[jj - 1]) != diff) {
					ans.push_back(false);
					continue;
				}
			}
			ans.push_back(true);
		}
		return ans;
    }
};
