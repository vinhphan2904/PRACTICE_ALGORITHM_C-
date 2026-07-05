#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

#define ll long long
ll n;
ll a[100];
map<ll,ll> sumLeft,sumRight;

void genLeft(ll l,ll m,ll sum){
    if(l == m){
        sumLeft[sum]++;
        return;
    }
    genLeft(l + 1,m,sum);
    genLeft(l + 1,m,sum + a[l]);
}

void genRight(ll m,ll r,ll sum){
    if(m == r){
        sumRight[sum]++;
        return;
    }
    genRight(m + 1,r,sum);
    genRight(m + 1,r,sum + a[m]);
}
int main(){
    cin >> n;
    ll sum = 0;
    for(ll i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    ll m = n / 2;
    genLeft(0,m,0);
    genRight(m,n,0);
    ll res = LLONG_MAX;
    ll cnt = 0;
    vector<pair<ll,ll>> ve;
    for(auto x : sumRight){
        ve.push_back(x);
    }
    for(auto x : sumLeft){
        ll valLeft = x.first;
        ll cntleft = x.second;
        auto it1 = lower_bound(ve.begin(),ve.end(),make_pair((ll)(sum / 2 - valLeft),0LL));
        auto check = [&](vector<pair<ll,ll>>::iterator p){
            if(p == ve.end()) return;
            ll valright = p->first;
            ll cntright = p->second;
            ll diff = llabs(sum - 2 * (valLeft + valright));
            if(diff < res){
                res = diff;
                cnt = cntleft * cntright;
            }
            else if(diff == res){
                cnt += cntleft * cntright;
            }
        };
        auto it2 = lower_bound(ve.begin(),ve.end(),make_pair((ll)((sum + 1) / 2 - valLeft),0LL));
        if(sum % 2 == 0){
            check(it1);
            if(it1 != ve.begin()){
                --it1;
                check(it1);
            }
        }
        else{
            check(it2);
            if(it2 != ve.begin()){
                --it2;
                check(it2);
                }
            }
        }   
    cout << res << " " << cnt / 2;
}