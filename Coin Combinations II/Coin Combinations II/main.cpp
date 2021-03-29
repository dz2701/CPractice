//
//  main.cpp
//  Coin Combinations II
//
//  Created by Shin Lee on 2/3/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, x;
const int MAX = 1e6+1;
const int FAC = 1e9+7;
int dp[101][MAX];//up until ith coin, make j value
int coins[MAX];
int main(){
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        cin >> coins[i];
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            dp[i][j]+=2*dp[i][j-coins[i]] + dp[i-1][j];

            dp[i][j]%=FAC;
        }
    }
    cout << dp[n][x];
}
