#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long n,k;
    cin >> n >> k;
    long long dp[n + 1];
    memset(dp,0,sizeof(dp));
    long long a[n + 1];
    for(long long i = 1;i <= k;i++) cin >> a[i];
    dp[0] = 1;
    for(long long i = 1;i <= n;i++){
        for(long long j = 1;j <= k;j++){
            if(i >= a[j]){
                dp[i] += dp[i - a[j]] % MOD;
            }
            else break;
        }
    }
    cout << dp[n] % MOD;
}