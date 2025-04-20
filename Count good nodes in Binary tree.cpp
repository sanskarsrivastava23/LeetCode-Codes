class Solution {
    public:
        void f(TreeNode* root, int &cnt, int maxValue) {
            if(root->val>=maxValue)
            {
                cnt++;
                maxValue=max(maxValue, root->val);
            }
            if(root->left)
            f(root->left, cnt, maxValue);
            if(root->right)
            f(root->right, cnt, maxValue);
        }
        int goodNodes(TreeNode* root) {
            int cnt=0;
            f(root, cnt, root->val);
            return cnt;
        }
    };