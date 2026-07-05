#include <iostream>

using namespace std;

#define ll long long

ll a[1000001],dp[1000001];
ll n;

int main(){
    ll q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        dp[i] = dp[i - 1] + a[i];
    }
    while(q--){
        ll x,y;
        cin >> x >> y;
        cout << dp[y] - dp[x - 1] << endl;
    }
}