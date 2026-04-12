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

// inorder traversal to traverse the entire tree in an ascending order
// use a global variable to keep track of the number of nodes being traversed
// once the count reaches k, then return the value at that node

class Solution {
public:
    int cnt = 0;

    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return 0;
        }

        int val = kthSmallest(root->left, k);
        if (cnt == k) {
            return val;
        }

        cnt++;
        if (cnt == k) {
            return root->val;
        }

        val = kthSmallest(root->right, k);
        if (cnt == k) {
            return val;
        }

        return 0;
    }
};