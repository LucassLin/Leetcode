/*
given a list of node to delete, return the roots of tree after deletion
check if a node is root and if it should not be deleted. if it is, add to result set
tree problem should always consider recursive first.

*/

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        set<int> delSet(to_delete.begin(), to_delete.end());
        dfs(root, res, delSet, true);
        return res;
    }
    
TreeNode* dfs(TreeNode* root, vector<TreeNode*>& res, set<int>& delSet, bool is_root){
    if(!root) return NULL;
    bool deleted = delSet.count(root->val);
    if(is_root && !deleted) res.push_back(root);
    root->left = dfs(root->left, res, delSet, deleted);
    root->right = dfs(root->right, res, delSet, deleted);
    return deleted? NULL:root;
}