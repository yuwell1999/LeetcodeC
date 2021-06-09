//
// Created by YuYue on 2021/6/9.
//

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
#include<vector>
#include <unordered_map>
#include "../Meduim/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        vector<int> ans;
        vector<int> ret;
        preOrder(root, ans);

        unordered_map<int, int> map;
        int n = ans.size();

        for (int i = 0; i < n; i++) {
            if (map.count(ans[n]) != 0) {
                map[ans[n]] += 1;
            } else {
                map[ans[n]] = 1;
            }

        }

        for (int i = 0; i < n; i++) {
            if (map[ans[i]] >= n / 2) {
                ret.push_back(ans[i]);
            }
        }

        return ret;
    }

    void preOrder(TreeNode *root, vector<int> &ans) {
        if (root == nullptr) {
            return;
        }
        ans.push_back(root->val);

        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
};