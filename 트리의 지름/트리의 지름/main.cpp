//
//  main.cpp
//  트리의 지름
//
//  Created by Shin Lee on 1/7/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4+5; int v;
vector<pair<int,int>>adj[MAX];
pair<int,int> dfs(int node, int value, int parent){
    pair<int,int> ret = {value,node};
    for(pair<int,int>con : adj[node])if(con.first!=parent)ret = max(ret, dfs(con.first,value+con.second,node));
    return ret;
}
int main(){
    cin >> v;
    for(int i=1;i<=v-1;i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    
    //first find the farthest point from the root, then the farthest point from that point.
    
    //root is node #1.
    
    pair<int,int> u = dfs(1,0,0);
    
    //u is the farthest point from root. Now figure out the distance of the farthest point from u.
    
    cout << dfs(u.second,0,0).first;
    
}
