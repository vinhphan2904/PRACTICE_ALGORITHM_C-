#include <iostream>

using namespace std;

int dp[1000000];

int main(){
    int n;
    cin >> n;
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        int x = i;
        dp[i] = INT_MAX;
        while(x){
            int d = x % 10;
            if(d > 0){
                dp[i] = min(dp[i],dp[i - d] + 1);
            }
            x /= 10;
        }
    }
    cout << dp[n];
}