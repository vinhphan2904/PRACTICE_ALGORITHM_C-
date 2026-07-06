#include <iostream>
using namespace std;

const int MAXN = 100000;

int main() {
    int A[MAXN + 1] = {0};
    int mx[MAXN + 1] = {0};

    A[0] = 0;
    A[1] = 1;

    for (int i = 1; 2 * i <= MAXN; i++) {
        A[2 * i] = A[i];
        if (2 * i + 1 <= MAXN)
            A[2 * i + 1] = A[i] + A[i + 1];
    }

    for (int i = 1; i <= MAXN; i++)
        mx[i] = max(mx[i - 1], A[i]);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << mx[N] << '\n';
    }

    return 0;
}