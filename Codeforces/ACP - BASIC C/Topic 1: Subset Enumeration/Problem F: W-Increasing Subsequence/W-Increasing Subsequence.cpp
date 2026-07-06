#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll n, k;
ll a[100];
vector<ll> ve[100];
ll cnt = 0;

void genLeft(ll l, ll r, ll endPos, ll last, ll sum) {
    if (sum > k) return;
    if (l > r) {
        ve[endPos].push_back(sum);
        return;
    }
    if (a[l] > last)
        genLeft(l + 1, r, l, a[l], sum + a[l]);
    genLeft(l + 1, r, endPos, last, sum);
}

void genRight(ll pos, ll r, ll start, ll last, ll sum) {
    if (sum > k) return;
    if (pos > r) {
        for (ll i = 0; i <= n / 2; i++) {
            if (start == 0 || a[i] < a[start]) {
                cnt += upper_bound(
                    ve[i].begin(),
                    ve[i].end(),
                    k - sum
                ) - ve[i].begin();
            }
        }
        return;
    }
    if (start == 0) {
        genRight(pos + 1, r, pos, a[pos], sum + a[pos]);
    }
    else if (a[pos] > last) {
        genRight(pos + 1, r, start, a[pos], sum + a[pos]);
    }
    genRight(pos + 1, r, start, last, sum);
}

int main() {
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    ll mid = n / 2;
    genLeft(1, mid, 0, 0, 0);
    for (ll i = 0; i <= mid; i++)
        sort(ve[i].begin(), ve[i].end());
    genRight(mid + 1, n, 0, 0, 0);
    cout << cnt;
    return 0;
}