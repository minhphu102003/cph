#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
public:
    TreeNode* root;
    BST() : root(NULL) {}

    void insert(int val) {
        root = insertRec(root, val);
    }

private:
    TreeNode* insertRec(TreeNode* node, int val) {
        if (node == NULL) {
            return new TreeNode(val);
        }
        if (val < node->val) {
            node->left = insertRec(node->left, val);
        } else {
            node->right = insertRec(node->right, val);
        }
        return node;
    }
};

TreeNode* findLCA(TreeNode* root, int A, int B) {
    if (root == NULL) return NULL;
    if (root->val > A && root->val > B) {
        return findLCA(root->left, A, B);
    }
    if (root->val < A && root->val < B) {
        return findLCA(root->right, A, B);
    }
    return root;
}

void findPath(TreeNode* root, int val, vector<int>& path) {
    TreeNode* current = root;
    while (current != NULL) {
        path.push_back(current->val);
        if (val < current->val) {
            current = current->left;
        } else if (val > current->val) {
            current = current->right;
        } else {
            break;
        }
    }
}

pair<int, int> findMinMaxOnPath(TreeNode* root, int A, int B) {
    TreeNode* lca = findLCA(root, A, B);

    vector<int> pathA, pathB;
    findPath(lca, A, pathA);
    findPath(lca, B, pathB);

    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    for (int val : pathA) {
        minValue = min(minValue, val);
        maxValue = max(maxValue, val);
    }
    for (int val : pathB) {
        minValue = min(minValue, val);
        maxValue = max(maxValue, val);
    }

    return {minValue, maxValue};
}

void solve() {
    int N;
    cin >> N;
    vector<int> values(N);
    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }
    int A, B;
    cin >> A >> B;

    BST tree;
    for (int val : values) {
        tree.insert(val);
    }

    pair<int, int> result = findMinMaxOnPath(tree.root, A, B);
    cout<<result.first<<" "<<result.second;
}

int main() {
    solve();
    return 0;
}
