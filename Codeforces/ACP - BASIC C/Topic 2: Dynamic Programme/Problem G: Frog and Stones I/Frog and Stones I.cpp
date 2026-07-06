#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
int main(){
    ll n;
    cin >> n;
    ll a[n + 1],dp[n + 1];
    for(ll i = 1;i <= n;i++) cin >> a[i];
    a[0] = 0;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);
    for(ll i = 3;i <= n;i++){
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]),dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[n];
}