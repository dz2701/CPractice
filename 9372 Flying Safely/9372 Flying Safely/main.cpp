//
//  main.cpp
//  9372 Flying Safely
//
//  Created by dz2701 on 7/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//  using bfs to perform MST

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4+5;
int n, m, T;
vector<int>adj[MAX];
int visit[MAX];
int rt = 0;
void dfs(int cur){
    if(visit[cur]==1)return;
    visit[cur]=1;
    for(int i:adj[cur]){
        if(visit[i]!=1){
            visit[i]=1;
            dfs(i);
            rt++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int i=1;i<=m;i++){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 1e9;
        for(int i=1;i<=n;i++){
            memset(visit,0,sizeof(visit));
            rt = 0; dfs(i);
            ans = min(ans,rt);
        }
        cout << ans;
    }
    return 0;
}
