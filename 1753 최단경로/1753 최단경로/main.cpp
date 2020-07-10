//
//  main.cpp
//  1753 최단경로
//
//  Created by dz2701 on 7/7/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5+5;
const int INF = 1e9;
vector<pair<int,int>>edges[MAX];
int val[MAX];
struct travel{int node, cost;}; bool cmp(travel a, travel b){return a.cost>b.cost;}
priority_queue<travel,vector<travel>,function<bool(travel,travel)>>pq(cmp);
int n, m; int start;
int main(){
    cin >> n >> m;
    cin >> start;
    for(int i=1;i<=m;i++){int a,b,c; cin >>a>>b>>c; edges[a].push_back({b,c});}
    
    pq.push({start,0});
    for(int i=1;i<=n;i++)val[i]=INF;
    val[start] = 0;
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        for(auto adj: edges[now.node]){
            if(val[adj.first]>adj.second+now.cost){
                val[adj.first] = adj.second+now.cost;
                pq.push({adj.first, val[adj.first]});
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(val[i]!=INF)printf("%d\n",val[i]);
        else printf("INF\n");
    }
    
    
    return 0;
}
