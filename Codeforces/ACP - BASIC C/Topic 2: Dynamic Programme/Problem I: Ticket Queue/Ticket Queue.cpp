#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n + 1],b[n];
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) cin >> b[i];
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = a[1];
    for(int i = 2;i <= n;i++){
        dp[i] = min(dp[i - 2] + b[i - 1],dp[i - 1] + a[i]);
    }
    cout << dp[n];
}