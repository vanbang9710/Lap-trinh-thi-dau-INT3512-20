#include <bits/stdc++.h>

using namespace std;

int n, numN, ans = 1e9;
bool dp[1005][6005];
pair<int, int> a[1005];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    numN = 6 * n;
    dp[1][a[1].first - a[1].second + numN] = dp[1][-a[1].first + a[1].second + numN] = true;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 12 * n; j++) {
            if (dp[i - 1][j]) {
                dp[i][j + a[i].first - a[i].second] = dp[i][j - a[i].first + a[i].second] = true;
            }
        }
    }
    for (int j = 0; j <= 12 * n; j++) {
        if (dp[n][j]) {
            ans = min (ans, abs(j - numN));
        }
    }
    cout << ans;
}
