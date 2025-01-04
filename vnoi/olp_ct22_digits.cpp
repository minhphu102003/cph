#include<bits/stdc++.h>
#define ll long long

using namespace std;


string addStrings(const string &a, const string &b) {
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    string result;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

string solve(const string &n){
    int m = n.size();
    string min_sum = string(m+1,'9');
    vector<tuple<int, int, int>> partitions;

    if(m%3 == 0){
        int part_len = m/3;
        partitions = {{part_len, part_len, part_len}};
    }else if(m%3== 1){
        int part_len1 = m/3,part_len2 = m/3+1;
        partitions = {{part_len2, part_len1, part_len1},{part_len1, part_len2, part_len1},{part_len1, part_len1, part_len2}};
    }else{
        int part_len1 = m/3,part_len2= m/3+1;
        partitions = {{part_len1, part_len2, part_len2},{part_len2, part_len1, part_len2},{part_len2, part_len2, part_len1}};
    }

    for(auto [len1,len2,len3]: partitions){
        int pos1 = len1, pos2 = len1 + len2;
        if(n[0] != '0' && n[pos1] != '0' && n[pos2] != '0'){
            string part1  = n.substr(0,pos1);
            string part2  = n.substr(pos1, pos2);
            string part3 = n.substr(pos2, len3);

            string sum1 = addStrings(part1, part2);
            string total_sum = addStrings(sum1, part3);

            if (total_sum.size() < min_sum.size() || (total_sum.size() == min_sum.size() && total_sum < min_sum)) {
                min_sum = total_sum;
            }
        }
    }
    return min_sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    string n;
    cin>>n;
    solve(n);

    return 0;
}