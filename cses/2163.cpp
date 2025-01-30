#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct TreapNode{
    int key,priority,size;
    TreapNode *left,*right;
    TreapNode(int key): key(key), priority(rand()), size(1), left(NULL), right(NULL){}
};

struct IndexSet{
    TreapNode* root = NULL;

    int getSize(TreapNode* t){
        return t ? t -> size : 0;
    }

    void updateSize(TreapNode* t){
        if (t) t -> size = 1 + getSize(t -> left) + getSize(t -> right);
    }
    
    pair<TreapNode*,TreapNode*> split(TreapNode* t, int key){
        if (!t) return {NULL,NULL};
        if (t->key < key) {
            auto [l, r] = split(t->right, key);
            t->right = l;
            updateSize(t);
            return {t, r};
        } else {
            auto [l, r] = split(t->left, key);
            t->left = r;
            updateSize(t);
            return {l, t};
        }
    }
    
    TreapNode* merge(TreapNode* l, TreapNode* r) {
        if (!l || !r) return l ? l : r;
        if (l->priority > r->priority) {
            l->right = merge(l->right, r);
            updateSize(l);
            return l;
        } else {
            r->left = merge(l, r->left);
            updateSize(r);
            return r;
        }
    }

    void insert(int key) {
        if (find(root, key)) return;
        auto [l, r] = split(root, key);
        root = merge(merge(l, new TreapNode(key)), r);
    }

    void erase(int key) {
        auto [l, mid] = split(root, key);
        auto [_, r] = split(mid, key + 1);
        root = merge(l, r);
    }

    TreapNode* find(TreapNode* t, int key) {
        if (!t) return nullptr;
        if (t->key == key) return t;
        return key < t->key ? find(t->left, key) : find(t->right, key);
    }

    int order_of_key(int key) {
        TreapNode* t = root;
        int count = 0;
        while (t) {
            if (key > t->key) {
                count += getSize(t->left) + 1;
                t = t->right;
            } else {
                t = t->left;
            }
        }
        return count;
    }

    int find_by_order(int index) {
        TreapNode* t = root;
        while (t) {
            int leftSize = getSize(t->left);
            if (index == leftSize) return t->key;
            if (index < leftSize) t = t->left;
            else {
                index -= leftSize + 1;
                t = t->right;
            }
        }
        return -1; // Not found
    }

};

void solve(){
    srand(time(0));
    IndexSet s;
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) 
        s.insert(i);

    int ind = k % n;
    while (n--) {
        int val = s.find_by_order(ind);
        cout << val << " ";
        s.erase(val);
        if (n) ind = (ind % n + k) % n;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    solve();
    return 0;
}