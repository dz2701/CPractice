//
//  main.cpp
//  Fruit Feast
//
//  Created by Shin Lee on 2/2/21.
//

#include <bits/stdc++.h>
using namespace std;
int t, a, b;
const int MAX = 5e6+5;
int dp[MAX][2];
int ans = 0;
void Solve(int n, int check){
    if(n>t)return;
    if(dp[n][check])return;
    dp[n][check] = 1;
    ans = max(ans,n);
    if(!check)Solve(n/2,1);
    Solve(n+a,check);
    Solve(n+b,check);
    
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    cin >> t >> a >> b;
    
    Solve(0,0);
    cout << ans;
}
