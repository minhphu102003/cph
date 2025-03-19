#include<bits/stdc++.h>
#define ll long long

using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    map<vector<int>, int> rowCount;
    
    for (int i = 0; i < n; i++) {
        rowCount[grid[i]]++;
    }
    
    int count = 0;
    
    for (int j = 0; j < n; j++) {
        vector<int> col;
        for (int i = 0; i < n; i++) {
            col.push_back(grid[i][j]);
        }
        if (rowCount.find(col) != rowCount.end()) {
            count += rowCount[col];
        }
    }
    
    return count;
}

void readInput(vector<vector<int>>& grid) {
    int n;
    cin >> n;
    grid.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    vector<vector<int>> grid;
    readInput(grid);
    cout << equalPairs(grid) << "\n";

    return 0;
}