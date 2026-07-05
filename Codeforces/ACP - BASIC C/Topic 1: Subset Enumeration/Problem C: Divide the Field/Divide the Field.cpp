#include <iostream>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

ll n;
ll a[100];
ll cnt = 0;
ll res = 0;
ll target = 0;
ll sum = 0;
bool check = false;
map<pair<ll,ll>,ll> mp;

void genLeft(ll l,ll m,ll sum1,ll sum2){
    if(sum1 > target || sum2 > target) return;
    if(l == m){
        mp[{sum1,sum2}]++;
        return;
    }
    genLeft(l + 1,m,sum1 + a[l],sum2);
    genLeft(l + 1,m,sum1,sum2 + a[l]);
    genLeft(l + 1,m,sum1,sum2);
}

void genRight(ll m,ll r,ll sum1,ll sum2){
    if(m == r){
        ll target1 = target - sum1;
        ll target2 = target - sum2;
        auto it = mp.find({target1,target2});
        if(it != mp.end()){
            cnt += it->second;
        }
        return;
    }
    genRight(m + 1,r,sum1 + a[m],sum2);
    genRight(m + 1,r,sum1,sum2 + a[m]);
    genRight(m + 1,r,sum1,sum2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(ll i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    target = sum / 3;
    if(target * 3 != sum) cout << -1;
    else{
        ll m = n / 2;
        genLeft(0,m,0,0);
        genRight(m,n,0,0);
        cout << (cnt != 0 ? cnt : -1);
    }
}