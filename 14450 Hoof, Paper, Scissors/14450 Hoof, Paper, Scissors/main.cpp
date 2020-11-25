//
//  main.cpp
//  14450 Hoof, Paper, Scissors
//
//  Created by dz2701 on 10/27/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int dp[MAX][21][3];
int arr[MAX];
int win[3][3];
int n, k;
int main(){
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        char temp; cin >> temp;
        arr[i] = temp=='P'? 0 : temp=='H' ? 1 : 2; //P=0, H=1, S=2.
    }
    win[0][1]=1; win[1][2]=1; win[2][0]=1;
    dp[1][0][0] = win[0][arr[1]]; dp[1][0][1] = win[1][arr[1]]; dp[1][0][2] = win[2][arr[1]];
    for(int i=2;i<=n;i++){
        dp[i][0][0] = max(dp[i-1][0][1], dp[i-1][0][2]) + win[0][arr[i]];
        dp[i][0][1] = max(dp[i-1][0][0], dp[i-1][0][2]) + win[1][arr[i]];
        dp[i][0][2] = max(dp[i-1][0][0], dp[i-1][0][1]) + win[2][arr[i]];
        for(int j=1;j<=k;j++){
            dp[i][j][0] = max(dp[i-1][j][0], max(dp[i-1][j-1][1], dp[i-1][j-1][2])) + win[0][arr[i]];
            dp[i][j][1] = max(dp[i-1][j][1], max(dp[i-1][j-1][0], dp[i-1][j-1][2])) + win[1][arr[i]];
            dp[i][j][2] = max(dp[i-1][j][2], max(dp[i-1][j-1][0], dp[i-1][j-1][1])) + win[2][arr[i]];
        }
    }
    int ans = -1e9;
    for(int i=0;i<=k;i++){
        ans = max(dp[n][i][0], max(dp[n][i][1],dp[n][i][2]));
    }
    cout << ans;
}
