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
    dp[1] = a[1];
    for(int i = 2;i <= n;i++){
        dp[i] = max(dp[i - 1],a[i]);
    }
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        cout << dp[x] << endl;
    }
}