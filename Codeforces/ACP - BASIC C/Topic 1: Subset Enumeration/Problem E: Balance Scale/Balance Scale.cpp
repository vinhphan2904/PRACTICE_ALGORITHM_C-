#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define ll long long

ll n,k;
ll a[100];
ll sum = 0;
ll cnt = 0;
map<ll,ll> cntLeft;

void genLeft(ll l,ll m,ll diff){
    if(l == m){
        cntLeft[diff]++;
        return;
    }
    genLeft(l + 1,m,diff);
    genLeft(l + 1,m,diff - a[l]);
    genLeft(l + 1,m,diff + a[l]);
}

void genRight(ll m,ll r,ll diff){
    if(m == r){
        auto it = cntLeft.find(k - diff);
        if(it != cntLeft.end()){
            cnt += it->second;
        }
        return;
    }
    genRight(m + 1,r,diff);
    genRight(m + 1,r,diff - a[m]);
    genRight(m + 1,r,diff + a[m]);
}

int main(){
    cin >> n >> k;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    ll m = n / 2;
    genLeft(0,m,0);
    genRight(m,n,0);
    cout << cnt;
}
