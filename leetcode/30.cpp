#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> findSubstring(string s, vector<string> &words)
{
  vector<int> result;
  int len = words.size();
  int sLen = s.size();
  if(sLen ==0 || len ==0) return result;

  int wordLen = words[0].size();
  int window = wordLen * len;

  if (sLen < window) return result;

  unordered_map<string, int> wMap;
  for (int  i = 0; i < len; i++)
  {
    wMap[words[i]]++;
  }
  
  for (int i = 0; i < wordLen; i++)
  {
    int left = i, count = 0;
    unordered_map<string, int> valid;
    for (int  j = i; j + wordLen <= sLen ; j+= wordLen)
    {
      string word = s.substr(j, wordLen);

      if(wMap.count(word)){
        valid[word]++;
        count++;
        while (valid[word] > wMap[word])
        {
          string leftWord = s.substr(left, wordLen);
          valid[leftWord]--;
          count--;
          left += wordLen;
        }
        if (count == len){
          result.push_back(left); 
        }
      }
      else{
          valid.clear();
          count = 0;
          left = j + wordLen;
        }
    }
  }
  return result;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("B001.inp", "r", stdin);
  freopen("B001.out", "w", stdout);
  string s1;
  cin >> s1;
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
  }
  vector<int> result = findSubstring(s1, words);
  int len = result.size();
  for (int  i = 0; i < len; i++)
  {
    cout<< result[i]<<" ";
  }
  return 0;
}