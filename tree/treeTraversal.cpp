
// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



//preorder:
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	std::stack<TreeNode*> temp;
	while (root || !temp.empty()) {
		while (root) {
			temp.push(root);
			res.push_back(root->val);
			root = root->left;
		}
		root = temp.top();
		temp.pop();
		root = root->right;
	}
	return res;
}


//inorder:
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	std::stack<TreeNode*> temp;
	while (root || !temp.empty()) {
		while (root) {
			temp.push(root);
			root = root->left;
		}
		root = temp.top();
		temp.pop();
		res.push_back(root->val);
		root = root->right;
	}
	return res;
}


//postorder:
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> res;
	std::stack<TreeNode*> temp;
	while (root || !temp.empty()) {
		while (root) {
			temp.push(root);
			res.insert(res.begin(),root->val);
			root = root->right;
		}
		root = temp.top();
		temp.pop();
		root = root->left;
	}
	return res;
}


//recursive
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(root==NULL)return result;
        result.push_back(root->val);
        
        vector<int> leftResult=preorderTraversal(root->left);
        vector<int> rightResult=preorderTraversal(root->right);
        
        //concanecate
        result.insert(result.end(),leftResult.begin(),leftResult.end());
        result.insert(result.end(),rightResult.begin(),rightResult.end());
        return result;
}
