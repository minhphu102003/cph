#include<bits/stdc++.h>
#define ll long long

using namespace std;

void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited){
    visited[room] = true;
    int len = rooms[room].size();
    for (int i = 0; i < len; i++)
    {
        if( !visited[rooms[room][i]]){
            dfs(rooms[room][i], rooms, visited);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    dfs(0, rooms, visited);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    return 0;
}