#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
 
using namespace std;
 
#define ll long long
int main(){
    ll n,m;
    cin >> n >> m;
    ll k = m - 1;
    ll a[n + 1];
    for(ll i = 1;i <= n;i++) cin >> a[i];
    ll pref[n + 1];
    pref[0] = 0;
    for(ll i = 1;i <= n;i++) pref[i] = pref[i - 1] + a[i];
    if(k >= n){
        cout << n << " " << pref[n] << endl;
        for(int i = 1;i <= n;i++) cout << i << " ";
        return 0;
    }
    ll res = k;
    ll dp[n + 1];
    dp[0] = 0;
    dp[1] = a[1];
    dp[k] = pref[k];
    ll kq = dp[k];
    for(ll i = k + 1;i <= n;i++){
        ll tmp = pref[i] - pref[i - k] + dp[i - k - 1];
        dp[i] = dp[i - 1];
        if(tmp >= dp[i - 1]){
            if(tmp >= kq){
                kq = tmp;
                res = i;
            }
            dp[i] = tmp;
        }
    }
    ll tmp = n / m * k;
    cout << tmp << " " << kq;
    vector<ll> ve;
    for(ll i = res;i >= 1;i -= m){
        for(ll j = i;j > i - k;j--){
            ve.push_back(j);
        }
    }
    cout << endl;
    reverse(ve.begin(),ve.end());
    for(auto x : ve) cout << x << " ";
}