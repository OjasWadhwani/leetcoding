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
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int count=0;
        vector<int> path;
        pathSumFind(root, sum, path, count);
        return count;
    }
private:
    void pathSumFind(TreeNode* root, int sum, vector<int>& path, int& count){
        if(!root)
            return;
        path.push_back(root->val);
        pathSumFind(root->left, sum, path, count);
        pathSumFind(root->right, sum, path, count);
        int tempSum=0;
        for(int i=path.size()-1; i>=0; i--){
            tempSum+=path[i];
            // cout<<"tempSum: "<<tempSum<<endl;
            if(tempSum==sum)
                count++;
        }
        path.pop_back();
    }
};