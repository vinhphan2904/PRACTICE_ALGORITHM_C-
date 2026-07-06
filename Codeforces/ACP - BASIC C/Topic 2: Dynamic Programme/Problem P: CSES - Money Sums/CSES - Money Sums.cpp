#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n + 1];
    bool dp[n + 1][100001];
    int sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum += a[i];
    }
    memset(dp,false,sizeof(dp));
    dp[0][0] = true;
    for(int i = 1;i <= n;i++){
        dp[i][0] = true;
        for(int j = 1;j <= sum;j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= a[i]){
                dp[i][j] |= dp[i - 1][j - a[i]];
            }
        }
    }
    int cnt = 0;
    for(int i = 1;i <= sum;i++){
        if(dp[n][i]) cnt++;
    }
    cout << cnt << endl;
    for(int i = 1;i <= sum;i++){
        if(dp[n][i]) cout << i << " ";
    }
}