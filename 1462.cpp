class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
												vector<vector<int>>& queries) {
        vector<bool> ans;
		vector<vector<<bool>> adj(n, vector<bool>(n, false));

		for (vector<int> prerequisite: prerequisites)
			adj[prerequisite[0]][prerequisite[1]] = true;

		stack<pair<int, vector<int>>> st;
		vector<bool> visited(n, false);

		for (int i = 0; i < n; i++) {
			st.push(make_pair(i, vector<int>()));
		}

		while (!st.empty()) {
			pair<int, vector<int>> elem = st.top();
			st.pop();

			//process elem
			int node = elem.first;
			for (int anc: elem.second)
				adj[anc][node] = true;

			vector<int> to_process = elem.second;
			to_process.push(node);
			//push all children in stack
			for (int jj = 0; jj < n; jj++) {
				if (adj[node][jj])
					st.push(make_pair(jj, to_process));
			}
		}

		for (vector<int> query: queries)
			ans.push_back(adj[query[0]][query[1]]);

		return ans;
    }
};
