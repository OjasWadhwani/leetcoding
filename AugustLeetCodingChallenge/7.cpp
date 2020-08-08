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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector<pair<int, int>>> mp;
        
        verticalOrderTraversal(mp, 0, 0, root);
        
        map<int, vector<pair<int, int>>>::iterator itr;
        vector<vector<int>> result;
        for(itr=mp.begin(); itr!=mp.end(); itr++){
            sort((*itr).second.begin(), (*itr).second.end());
            vector<pair<int, int>>::iterator itr1;
            vector<int> temp;
            for(itr1=(*itr).second.begin(); itr1!=(*itr).second.end(); itr1++){
                temp.push_back((*itr1).second);
            }
            result.push_back(temp);
        }
        
        return result;
    }
private: 
    void verticalOrderTraversal(map<int, vector<pair<int, int>>>& mp, int x, int y, TreeNode* root){
        if(root==NULL)
            return;
        //using pre-order traversal recursively
        mp[x].push_back(make_pair(-y, root->val));
        verticalOrderTraversal(mp, x-1, y-1, root->left);
        verticalOrderTraversal(mp, x+1, y-1, root->right);
    }
};