//
//  main.cpp
//  16763 Fine Dining
//
//  Created by dz2701 on 7/15/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
const int INF = 1e9;
struct value{
    int val;
    bool take;
};
value val[MAX], val2[MAX] ; bool check[MAX];
int n,m ,k; vector<pair<int,int>>path[MAX];
pair<int,int>haybale[MAX];

struct state{
    int node, val;
    bool take;
};
bool cmp(state a, state b){return a.val>b.val;}
priority_queue<state, vector<state>, function<bool(state,state)>>pq(cmp);
int visit[MAX];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
   //freopen("dining.in","r",stdin);
    //freopen("dining.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int a, b, c; cin>> a >> b >> c;
        path[a].push_back(make_pair(b,c));
        path[b].push_back(make_pair(a,c));
    }
    for(int i=1;i<=k;i++)cin >> haybale[i].first >> haybale[i].second;
    //dijkstra from N
    for(int i=1;i<=n;i++){
        val[i].val = INF;
        val[i].take = false;
    }
    fill(&visit[0],&visit[MAX],false);
    val[n] = {0,false}; pq.push({n,0,false});
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        if(visit[now.node])continue;
        visit[now.node] = true;
        for(auto adj: path[now.node]){
            if(val[adj.first].val>adj.second+now.val){
                val[adj.first].val = adj.second+now.val;
                pq.push({adj.first,val[adj.first].val,val[adj.first].take});
            }
        }
    }
    //now 'take the route' i.e update the nodes
    for(int i=1;i<=k;i++){
        val[haybale[i].first].val-=haybale[i].second;
        val[haybale[i].first].take = true;
        
    }
    
    //now do dijkstra again, but if visit the haybale node, turn true;
    fill(&visit[0],&visit[MAX],false);
    
    x
    return 0;
    
}
