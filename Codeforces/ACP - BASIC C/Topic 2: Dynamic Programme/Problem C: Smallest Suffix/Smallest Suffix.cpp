#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

ll a[1000001],dp[1000001];
ll n;

int main(){
    ll q;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dp[n] = a[n];
    for(int i = n - 1;i >= 1;i--){
        dp[i] = min(dp[i + 1],a[i]);
    }
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        cout << dp[x] << endl;
    }
}