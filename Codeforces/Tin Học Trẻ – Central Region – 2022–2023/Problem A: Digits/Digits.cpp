#include <iostream>
using namespace std;

#define ll long long

int main() {
    int T;
    cin >> T;

    while (T--) {
        ll a, b, L, R;
        cin >> a >> b >> L >> R;

        ll F[61], pre[61];

        F[1] = a % 10;
        F[2] = b % 10;

        pre[0] = 0;
        pre[1] = F[1];
        pre[2] = (pre[1] + F[2]) % 10;

        for (int i = 3; i <= 60; i++) {
            F[i] = (F[i - 1] + F[i - 2]) % 10;
            pre[i] = (pre[i - 1] + F[i]) % 10;
        }

        auto sum = [&](ll x) {
            if (x <= 0) return 0LL;

            ll cycles = x / 60;
            ll rem = x % 60;

            return ((cycles % 10) * pre[60] + pre[rem]) % 10;
        };

        cout << (sum(R) - sum(L - 1) + 10) % 10 << '\n';
    }

    return 0;
}