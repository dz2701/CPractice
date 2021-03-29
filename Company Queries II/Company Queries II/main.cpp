//
//  main.cpp
//  Company Queries II
//
//  Created by Shin Lee on 2/26/21.
//

#include <bits/stdc++.h>
using namespace std;

int n, q; const int MAX = 2e5+1;
int dp[MAX][26], height[MAX];
vector<int>adj[MAX];

void dfs(int cur, int par, int h){
    height[cur]=h;
    dp[cur][0]=par;
    
    for(int con:adj[cur]){
        dfs(con,cur,h+1);
    }
}

int LCA(int a, int b){
    if(height[a]<height[b])swap(a,b);
    //pull up a up to b's height
    for(int i=25;i>=0;i--){
        int check = dp[a][i];
        if(height[check]>=height[b])a=check;
    }
    //now height a and height b will be same, except when a=b
    if(a==b)return b;
    
    //now find a point right before the parents equal
    for(int i=20;i>=0;i--){
        int na = dp[a][i], nb = dp[b][i];
        if(na!=nb){
            a=na; b=nb;
        }
    }
    return dp[a][0];
}
int main(){
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        int t; cin >> t;
        adj[t].push_back(i); //storing info abt child
    }
    dfs(1,1,1);
    for(int j=1;j<=25;j++){
        for(int i=1;i<=n;i++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
    
    while(q--){
        int a, b; cin >> a >> b;
        printf("%d\n",LCA(a,b));
    }
}
