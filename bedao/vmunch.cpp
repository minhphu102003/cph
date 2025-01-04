#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int dx[] = {-1, 1, 0, 0}; // Di chuyển theo 4 hướng
int dy[] = {0, 0, -1, 1};

// Kiểm tra xem ô (x, y) có hợp lệ hay không
bool isValid(int x, int y, int R, int C, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
    return x >= 0 && x < R && y >= 0 && y < C && !visited[x][y] && grid[x][y] != '*';
}

// BFS để tìm đường ngắn nhất và đếm số ô `.` trên đường
int bfs(int startX, int startY, int endX, int endY, int R, int C, vector<vector<char>> &grid) {
    queue<pair<int, int>> q;
    vector<vector<int>> distance(R, vector<int>(C, -1)); // Khoảng cách từ điểm bắt đầu
    vector<vector<pair<int, int>>> parent(R, vector<pair<int, int>>(C, {-1, -1})); // Lưu cha của mỗi ô
    vector<vector<bool>> visited(R, vector<bool>(C, false)); // Đánh dấu ô đã thăm

    q.push({startX, startY});
    visited[startX][startY] = true;
    distance[startX][startY] = 0;

    // BFS tìm đường ngắn nhất
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Nếu gặp đích, dừng BFS
        if (x == endX && y == endY) {
            break;
        }

        // Duyệt qua 4 hướng
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny, R, C, grid, visited)) {
                visited[nx][ny] = true;
                distance[nx][ny] = distance[x][y] + 1;
                parent[nx][ny] = {x, y}; // Lưu cha của ô hiện tại
                q.push({nx, ny});
            }
        }
    }
    int grassCount = 0;
    int x = endX, y = endY;
    while (x != startX || y != startY) {
        if (grid[x][y] == '.') {
            grassCount++;
        }
        tie(x, y) = parent[x][y]; // Đi ngược về cha
    }
    return grassCount;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> grid(R, vector<char>(C));
    int startX, startY, endX, endY;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'C') {
                startX = i;
                startY = j;
            } else if (grid[i][j] == 'B') {
                endX = i;
                endY = j;
            }
        }
    }
    int result = bfs(startX, startY, endX, endY, R, C, grid);
    cout << result + 1 << endl;
    return 0;
}
