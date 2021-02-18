/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// recover and create sorted array
// binary search
class FindElements {
private:
    vector<int> flat;
	bool binary_search(int val, int st, int en) {
		int mid = st + (en - st)/2;

		if (st > en)
			return false;
		if (flat[mid] == val)
			return true;
		else if (flat[mid] < val)
			return binary_search(val, mid + 1, en);
		else
			return binary_search(val, st, mid - 1);
	}
public:
    FindElements(TreeNode* root) {
        queue<TreeNode*> q;

        root->val = 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
			flat.push_back(node->val);
            q.pop();
            if (node->left != NULL) {
                node->left = 2 * node->val + 1;
				q.push(node->left);
            }
            if (node->right != NULL) {
                node->right = 2 * node->val + 2;
				q.push(node->right);
            }
        }
    }
    
    bool find(int target) {
        return binary_search(target, 0, flat.size() - 1);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
