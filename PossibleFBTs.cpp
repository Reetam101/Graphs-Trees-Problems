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
   unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if(N % 2 == 0) return {};
        if(memo[N].size() > 0) return memo[N];
        if(N == 1){
            res.push_back(new TreeNode(0));
        }      
        else{
            for(int i = 1; i < N; i += 2){
                auto left = allPossibleFBT(i);
                auto right = allPossibleFBT(N - i - 1);
                for(auto l : left){
                    for(auto r : right){
                        TreeNode* node = new TreeNode(0);
                        node->left = l;
                        node->right = r;
                        res.push_back(node);
                    }
                }
            }   
        }
        memo[N] = res;
        return res;
    }
};