class Solution {
public:
	vector<int> get_elem_ops(int val) {
		vector<int> ans({0, 0});

		while (val > 0) {
			if (val % 2 == 0) {
				ans[1]++;
				val /= 2;
			}
			else {
				ans[0]--;
				val -= 1;
			}
		}
		return ans;
	}
	int minOperations(vector<int>& nums) {
		for (int num: nums) {
			vector<int> temp = get_elem_ops(num);
			cout<<temp[0]<<" "<<temp[1]<<endl;
		}
		return 0;
	}
};
