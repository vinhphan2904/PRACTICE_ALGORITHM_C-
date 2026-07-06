#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long dp[1000001];
    dp[0] = 0;
    long long res = 0;
    for(int i = 1;i <= n;i++){
        long long x;
        cin >> x;
        dp[i] = max(x,dp[i - 1] + x);
        res = max(res,dp[i]);
    }
    cout << res;
}