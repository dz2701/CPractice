//
//  main.cpp
//  Book Shop
//
//  Created by Shin Lee on 2/3/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int n, x;
int dp[1001][MAX];
int val[1001], cost[1001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> x;
    for(int i=1;i<=n;i++){
        cin >> cost[i];
    }
    for(int i=1;i<=n;i++){
        cin >> val[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(j-cost[i]>=0)dp[i][j] = max(dp[i-1][j-cost[i]]+val[i],dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
            ans = max(dp[i][j],ans);
        }
    }
    cout << ans;
}
