#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long
int main(){
    ll n,k;
    cin >> n >> k;
    ll a[n + 1],dp[n + 1];
    memset(dp,0,sizeof(dp));
    for(ll i = 1;i <= n;i++) cin >> a[i];
    a[0] = 0;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);
    for(ll i = 3;i <= n;i++){
        dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
        for(ll j = 2;j <= k;j++){
            if(j < i){
                dp[i] = min(dp[i],dp[i - j] + abs(a[i] - a[i - j]));
            }
        }
    }
    cout << dp[n];
}