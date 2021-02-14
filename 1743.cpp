class Solution {
private:
    void create_rev_idx(vector<vector<int>>& adjacentPairs,
					unordered_map<int, vector<int, int>> &rev_idx)
	{
		for (int ii = 0; ii < adjacentPairs.size(); ii++) {
			vector<int> pair = adjacentPairs[ii];

			if (rev_idx.find(pair[0]) != rev_idx.end())
				rev_idx[pair[0]].push_back(ii);
			else
				ev_idx[pair[0]] = ii;

			if (rev_idx.find(pair[1]) != rev_idx.end())
				rev_idx[pair[1]].push_back(ii);
			else
				ev_idx[pair[1]] = ii;
		}
	}

	pair<int, int> find_start(unordered_map<int, vector<int, int>> rev_idx)
	{
		pair<int, int> ret = {-1, -1};

		for (pair<int, vector<int, int>> elem: rev_idx)
			if (elem.second.size() == 1)
				return make_pair(elem.first, elem.second[0]);
		return ret;
	}

	vector<int> create_ans(pair<int, int> st, vector<vector<int>>& adjacentPairs,
			unordered_map<int, vector<int, int>> &rev_idx)
	{
		vector<int> ans;
		unordered_map<int, bool> visited;
		int elem, elem_idx;

		elem = st.first;
		elem_idx = st.second;
		while () {
			ans.push_back(elem);
			visited[elem] = false;
			//figure out next element
			if (adjacentPairs[elem_idx][0] == elem) {
				elem = adjacentPairs[elem_idx][1];
				for (int idx:rev_idx[elem])
					if (idx != elem_idx)
						elem_idx = idx;
			}
			else {
				elem = adjacentPairs[elem_idx][0];
				for (int idx:rev_idx[elem])
					if (idx != elem_idx)
						elem_idx = idx;
			}
		}

		return ans;
	}
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
	{
        unordered_map<int, vector<int, int>> rev_idx;
		vector<int> ans;
		pair<int, int> start;

        create_rev_idx(adjacentPairs, rev_idx);
    	start = find_start(rev_idx);
		ans = create_ans(start, rev_idx);
		return ans;
	}
};
