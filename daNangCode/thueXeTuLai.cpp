#include <bits/stdc++.h>
const int MOD = 1000000007;
#define ll long long

using namespace std;

pair<int, string> max_requests(int N, int R, int Q, double P, vector<pair<int, int>>& intervals) {
    // Sắp xếp các yêu cầu theo thời gian trả xe (Fi)
    // sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    //     return a.second < b.second;
    // });

    // Sử dụng hàng đợi ưu tiên để theo dõi thời gian rảnh rỗi của các xe
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

    // Ban đầu tất cả các xe đều rảnh rỗi từ thời điểm 0
    for (int i = 0; i < Q; ++i) {
        pq.push(0);
    }

    int count = 0;
    for (const auto& interval : intervals) {
        int start = interval.first;
        int end = interval.second;

        // Lấy xe rảnh rỗi sớm nhất
        int earliest_available_time = pq.top();
        pq.pop();

        if (earliest_available_time <= start) {
            // Chấp nhận yêu cầu và cập nhật thời gian rảnh rỗi của xe
            pq.push(end);
            count++;
        } else {
            // Xe không rảnh rỗi kịp thời, đưa lại vào hàng đợi
            pq.push(earliest_available_time);
        }
    }

    double percentage_achieved = (static_cast<double>(count) / R) * 100;

    string need_more_cars = ((100 - percentage_achieved) > P) ? "Yes" : "No";

    return {count, need_more_cars};
}

void solve(){
    int n, r, q;
    double p;
    cin >> n >> r >> q >> p;
    vector<pair<int, int>> b;
    int s, f;
    for (int i = 0; i < r; ++i) {
        cin >> s >> f;
        b.push_back({s, f});
    }
    pair<int, string> result = max_requests(n, r, q, p, b);
    cout << result.first << "/" << r << ": ";
    cout << result.second << endl;
}

int main(){
    solve();
    return 0;
}
