class Solution {
public:

    TreeNode* FindMin(TreeNode* root) {
        if(root -> left == NULL) {
            return root;
        }
        return FindMin(root -> left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return root;
        }
        else if(root -> val > key) {
            root -> left = deleteNode(root -> left , key);
        }
        else if(root -> val < key) {
            root -> right = deleteNode(root -> right , key);
        }
        else{
            if(root -> left == NULL && root -> right == NULL) {
                return NULL;
            }
            else if(root -> right == NULL) {
                root = root -> left;
            }
            else if(root -> left == NULL) {
                root = root -> right;
            }
            else{
                TreeNode *temp = FindMin(root -> right);
                root -> val = temp -> val;
                root -> right = deleteNode(root -> right , temp -> val);
            }
        }
        return root;
    }
};
