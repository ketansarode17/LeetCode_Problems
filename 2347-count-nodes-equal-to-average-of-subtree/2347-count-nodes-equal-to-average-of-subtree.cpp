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
    private:
    pair<int,int> helper(TreeNode* root,int& ans)
    {
        int sum=root->val,cnt=1;
        if(root->left)
        {
            auto it=helper(root->left,ans);
            sum+=it.first;cnt+=it.second;
        }
        if(root->right)
        {
            auto it=helper(root->right,ans);
            sum+=it.first;cnt+=it.second;
        }
        if(sum/cnt==root->val)ans++;
        return {sum,cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};