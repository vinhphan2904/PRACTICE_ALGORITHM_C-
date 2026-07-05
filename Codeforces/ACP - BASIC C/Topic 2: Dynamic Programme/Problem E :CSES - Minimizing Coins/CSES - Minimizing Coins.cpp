#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int coin[105];
int dp[1000005];

int main() {
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
        cin >> coin[i];

    for (int i = 1; i <= x; i++)
        dp[i] = INF;

    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= coin[j])
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
    }

    if (dp[x] == INF)
        cout << -1;
    else
        cout << dp[x];

    return 0;
}