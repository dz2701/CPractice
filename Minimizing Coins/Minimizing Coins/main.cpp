//
//  main.cpp
//  Minimizing Coins
//
//  Created by Shin Lee on 2/2/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, x;
const int MAX = 1e6+5;
int dp[101][MAX];
int c[101];
int main(){
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }
    for(int i=1;i<=x;i++)dp[0][i] = 1e9; //impossible
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(j-c[i]>=0){
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-c[i]]+1, dp[i-1][j-c[i]]+1));
            }else dp[i][j] = dp[i-1][j];
        }
    }
    cout << (dp[n][x]!=1e9? dp[n][x] : -1);
}
