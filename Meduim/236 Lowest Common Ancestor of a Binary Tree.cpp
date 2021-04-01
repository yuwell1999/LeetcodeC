//
// Created by YuYue on 2021/4/1.
//

#include "TreeNode.h"

class Solution_236 {
public:
    TreeNode *ans;

    // 判断root的节点的子树中是否包含p或者q节点
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr) {
            return false;
        }
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);

        if ((left && right) || // 左右子树均包含p或者q节点
            // root恰好是p或者q节点且他的左子树或者右子树有一个包含了另一个节点
            ((root->val == p->val || root->val == q->val) && (left || right))) {
            ans = root;
        }

        return left || right || (root->val == p->val || root->val == q->val);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }
};