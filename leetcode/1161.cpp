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

int maxLevelSum(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int maxSum = INT_MIN;
    int level = 1, maxLevel = 0;

    while (!q.empty()) {
        int n = q.size();
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            TreeNode* current = q.front(); q.pop();
            sum += current->val;
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxLevel = level; 
        }
        level++;
    }

    return maxLevel;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    cout<<maxLevelSum(buildTreeFromInput());
    return 0;
}