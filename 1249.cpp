class Solution {
public:
	string minRemoveToMakeValid(string s) {
		stack<int> st;
		vector<bool> bits(s.size(), false);
		string ans;

		for (int ii = 0; ii < s.size(); ii++) {
			char c = s[ii];

			if (c == '(') {
				st.push(ii);
			}
			else if (c == ')') {
				if (!st.empty()) {
					bits[ii] = true;
					int idx = st.top();
					st.pop();
					bits[idx] = true;
				}
			}
			else {
				bits[ii] = true;
			}
		}
		for (int ii = 0; ii < bits.size(); ii++) {
			if (bits[ii] == true)
				ans += s[ii];
		}
		return ans;
	}
};

