#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long

vector<ll> leftSum,rightSum;

int a[100];
int n,m;

void genLeft(int left,int mid,ll sum){
    if(left == mid){
        leftSum.push_back(sum);
        return;
    }
    genLeft(left + 1,mid,sum);
    genLeft(left + 1,mid,sum + a[left]);
}

void genRight(int mid,int right,ll sum){
    if(mid == right){
        rightSum.push_back(sum);
        return;
    }
    genRight(mid + 1,right,sum);
    genRight(mid + 1,right,sum + a[mid]);
}

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i];
    int mid = n / 2;
    genLeft(0,mid,0);
    genRight(mid,n,0);
    sort(rightSum.begin(),rightSum.end());
    ll cnt = 0;
    for(auto x : leftSum){
        cnt += upper_bound(rightSum.begin(),rightSum.end(),m - x) - rightSum.begin();
    }
    cout << cnt;
}