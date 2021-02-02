//
//  main.cpp
//  15681 트리와 쿼리
//
//  Created by Shin Lee on 12/23/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int dp[MAX]; vector<int>adj[MAX];
int N, R, Q;

void dfs(int cur, int par){
    int ret = 0;
    for(int con : adj[cur]){
        if(con!=par){
            dfs(con,cur);
            ret+=dp[con];
        }
    }
    dp[cur] = ret+1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> R >> Q;
    for(int i=1;i<N;i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(R,-1);
    for(int i=1;i<=Q;i++){
        int q; cin >> q;
        cout << dp[q] << "\n";
    }
    return 0;
}
