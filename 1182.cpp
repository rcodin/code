class Solution {
public:
	int get_idx(vector<int> &idxes, int l, int r, int val) {
		if (l >= r) {
			if (l >= idxes.size())
                return idxes.size() - 1;
            else if (r < 0)
                return 0;
            return l;
        }
		int m = l + (r - l)/2;
		if (idxes[m] == val)
			return m;
		else if (idxes[m] < val)
			return get_idx(idxes, m + 1, r, val);
		else
			return get_idx(idxes, l, m - 1, val);
		return 0;
	}
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> idxes1;
        vector<int> idxes2;
        vector<int> idxes3;
		vector<int> ans;
		int idx = 0;

		//initialize idxes
		for (int color: colors) {
			switch(color) {
				case 1:
					idxes1.push_back(idx);
					break;
				case 2:
					idxes2.push_back(idx);
					break;
				case 3:
					idxes3.push_back(idx);
					break;
			}
			idx++;
		}
		for (vector<int> query: queries) {
			vector<int> &idxes;
			int ans_elem = -1;
			switch(query[1]) {
				case 1:
					idxes = idxes1;
					break;
				case 2:
					idxes = idxes2;
					break;
				case 3:
					idxes = idxes3;
					break;
			}
			if (idxes.size() != 0) {
				int appr_idx = get_idx(idxes, 0 , idxes.size(), query[0]);
				if ((appr_idx - 1) >= 0)
					ans_elem = abs(idxes[appr_idx - 1] - query[0]);
				if ((appr_idx + 1) < idxes.size())
					ans_elem = abs(idxes[appr_idx + 1] - query[0]);
				ans_elem = abs(idxes[appr_idx] - query[0]);
			}
		}
		return ans;
    }
};
