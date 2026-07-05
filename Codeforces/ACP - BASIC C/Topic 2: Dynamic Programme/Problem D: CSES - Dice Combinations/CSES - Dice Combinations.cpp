#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
long long dp[1000001];
int main(){
    int n;
    cin >> n;
    dp[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 6;j++){
            if(i >= j){
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    cout << dp[n];
}