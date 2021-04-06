//
//  main.cpp
//  Company Queries II
//
//  Created by Shin Lee on 12/16/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1; //2^10 = 1024; 10^3
int dp[MAX][20];
int n, q;
vector<int>adj[MAX];
int height[MAX];
int lca(int a, int b){
    if(height[a]<height[b])swap(a,b);
    for(int f=20;f>=0;f--){
        int aa = dp[a][f];
        if(height[aa]>=height[b])a=aa;
    }
    if(a==b)return a;
    
    for(int f=20;f>=0;f--){
        int aa = dp[a][f], bb = dp[b][f];
        if(aa!=bb){
            a=aa;
            b=bb;
        }
    }
    return dp[a][0];
}

void dfs(int cur, int par, int h){
    height[cur] = h;
    for(int con : adj[cur]){
        if(con!=par){
            dfs(con,cur,h+1);
        }
    }
}
int main(){
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        int temp; cin >> temp;
        adj[temp].push_back(i);
        dp[i][0] = temp;
    }
    dp[1][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=20;j++){
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
    
    dfs(1,-1,0);
    for(int i=0;i<q;i++){
        int c, d;
        cin >> c >> d;
        printf("%d\n",lca(c,d));
    }
    return 0;
}
