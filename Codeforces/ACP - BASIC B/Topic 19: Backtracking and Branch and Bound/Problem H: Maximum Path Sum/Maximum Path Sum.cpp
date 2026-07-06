#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int NEG = -1000000000;

int main() {
    int m, n;
    cin >> m >> n;

    int a[m + 1][n + 1];
    int dp[m + 1][n + 1];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 0; i <= m + 1; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = NEG;

    for (int i = 1; i <= m; i++)
        dp[i][1] = a[i][1];

    for (int j = 2; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            dp[i][j] = a[i][j] + dp[i][j - 1];

            if (i > 1)
                dp[i][j] = max(dp[i][j], a[i][j] + dp[i - 1][j - 1]);

            if (i < m)
                dp[i][j] = max(dp[i][j], a[i][j] + dp[i + 1][j - 1]);
        }
    }

    int ans = NEG;

    for (int i = 1; i <= m; i++)
        ans = max(ans, dp[i][n]);

    cout << ans;
}