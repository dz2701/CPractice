//
//  main.cpp
//  이분 그래프
//
//  Created by Shin Lee on 24/12/2019.
//  Copyright © 2019 Shin Lee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int visit[20000+5];
vector<int> adj[20000+5];
bool ans = true;
void dfs(int cur, int fac){
    visit[cur]=fac;
    for(int i=0;i<int(adj[cur].size());i++){
        if(visit[adj[cur][i]]==0)dfs(adj[cur][i],fac*-1);
        if(visit[adj[cur][i]]==fac)ans = false;
    }
}
int main() {
    int trial;
    cin >> trial;
    for(int a=0;a<trial;a++){
        int v, e;
        cin >> v >> e;
        //need to reset vector and array
        memset(adj,0,sizeof(adj));
        memset(visit,0,sizeof(visit));
        ans = true;
        for(int i=0;i<e;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            
        }
        for(int i=1;i<=v;i++){
            if(visit[i]==0)dfs(i,1);
        }
        if(ans==true)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
