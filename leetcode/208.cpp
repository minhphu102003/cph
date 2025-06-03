#include <bits/stdc++.h>
#define ll long long

using namespace std;

class TrieNode {
  public: 
   TrieNode* children[26];
   bool isEndOfWord;
   TrieNode() {
    isEndOfWord = false;
    for (int  i = 0; i < 26; i++)
    {
      children[i] = nullptr;
    }
    
   }
};

class Trie {
  private: 
   TrieNode* root;
  public:
    Trie(){
      root = new TrieNode();
    }

    void insert(string word){
      TrieNode* node = word;
      int len = word.size();
      for (int  i = 0; i < len; i++)
      {
        int ind = word[i] - 'a';
        if(!node -> children[ind])
          node->children[ind] = new TrieNode();
        node = node->children[ind];
      }
      node->isEndOfWord = true;
    }

    bool search(string word){
      TrieNode* node = root;
      int len = word.size();
      for (int  i = 0; i < len; i++)
      {
        int ind = word[i] - 'a';
        if(!node->children[ind])
          return false;
        node = node->children[indx];
      }
      return node->isEndOfWord;
    }

    bool startWith(string prefix){
      TrieNode* node = root;
      int len = prefix.size();
      for (int i = 0; i < len; i++)
      {
        int ind = prefix[i] - 'a';
        if (!node->children[ind])
          return false;
        node = node ->children[ind];
      }
      return true;
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("B001.inp", "r", stdin);
  freopen("B001.out", "w", stdout);

  return 0;
}