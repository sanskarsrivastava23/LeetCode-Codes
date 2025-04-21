/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public:
        vector<vector<int>> levelOrder(Node* root) {
            vector<vector<int>> res;
            queue<Node*> q;
            if(root==NULL)
            return res;
            q.push(root);
            while(!q.empty())
            {
                vector<int> ans;
                int size=q.size();
                for(int i=0;i<size;i++)
                {
                    Node* temp=q.front();
                    q.pop();
                    ans.push_back(temp->val);
                    for(int ind=0;ind<temp->children.size();ind++)
                    q.push(temp->children[ind]);
                }
                res.push_back(ans);
            }
            return res;
        }
    };