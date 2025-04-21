class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDepth(Node* root, int num, int level) {
        if(root==NULL)
        return -1;
        if(root->data==num)
        return level;
        int left=findDepth(root->left, num, level+1);
        if(left!=-1)
        return left;
        int right=findDepth(root->right, num, level+1);
        return right;
    }
    Node* findLCA(Node* root, int a, int b) {
        if(root==NULL)
        return NULL;
        if(root->data==a || root->data==b)
        return root;
        Node* left=findLCA(root->left, a, b);
        Node* right=findLCA(root->right, a, b);
        if(left!=NULL && right!=NULL)
        return root;
        return (left==NULL) ? right : left;
    }
    int findDist(Node* root, int a, int b) {
        Node* lca=findLCA(root, a, b);
        int left=findDepth(lca, a, 0);
        int right=findDepth(lca, b, 0);
        if (left==-1 || right==-1)
        return -1;
        return left+right;
    }
};