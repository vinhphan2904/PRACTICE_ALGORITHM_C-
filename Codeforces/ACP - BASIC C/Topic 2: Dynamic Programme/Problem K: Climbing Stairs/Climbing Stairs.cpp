#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

const int MOD = 14062008;
int main(){
    int n,k;
    cin >> n >> k;
    int a[n + 1],dp[n + 1];
    memset(a,0,sizeof(a));
    for(int i = 1;i <= k;i++){
        int x;
        cin >> x;
        a[x] = 1;
    }
    dp[1] = 1;
    dp[0] = 0;
    for(int i = 2;i <= n;i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        if(a[i]) dp[i] = 0;
    }
    cout << dp[n];
}