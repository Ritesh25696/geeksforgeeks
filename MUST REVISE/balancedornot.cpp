Given a binary tree, find if it is height balanced or not.  A tree is heigh balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.    Expected time complexity is O(n).
*************************************************************************************************************************
pair<int, bool> isBalancedWithDepth(Node *root) {
        if (root == NULL) return make_pair(0, true);
        pair<int, bool> left = isBalancedWithDepth(root->left);
        pair<int, bool> right = isBalancedWithDepth(root->right);
        int depth = max(right.first, left.first) + 1;
         bool isbalanced = right.second && left.second && (abs(right.first - left.first) < 2);
        return make_pair(depth, isbalanced);
    }

bool isBalanced(Node *root)
{
     if (root == NULL) return true;
    return isBalancedWithDepth(root).second;
}
