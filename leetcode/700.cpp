#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreeFromInput() {
    int n;
    cin >> n;
    if (n == 0) return nullptr;
    
    vector<int> values(n);
    for (int i = 0; i < n; i++) cin >> values[i];
    
    if (values[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < n) {
        TreeNode* current = q.front(); q.pop();
        
        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;
        
        if (i < n && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
    
    return root;
}

TreeNode* searchBST(TreeNode* root, int val) {
        
    if (root == nullptr) return nullptr;
    
    if (root->val == val) return root;
    
    if (val < root->val) return searchBST(root->left, val);
    
    return searchBST(root->right, val);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int val;
    cin >> val;
    TreeNode* root = buildTreeFromInput();
    TreeNode* result = searchBST(root, val);
    
    return 0;
}