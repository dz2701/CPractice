//
//  main.cpp
//  16763 Fine Dining
//
//  Created by dz2701 on 7/13/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
const int INF = 1e8;
vector<pair<int,int>>path[MAX];
struct edge{int st, ed; long long cost;};
struct travel{int node; long long val;};
bool tcmp(travel a, travel b){return a.val>b.val;}
bool cmp(edge a, edge b){return a.cost>b.cost;}
priority_queue<edge,vector<edge>,function<bool(edge,edge)>>pq(cmp);
priority_queue<travel,vector<travel>,function<bool(travel,travel)>>q(tcmp);
bool check[MAX]; bool checktwice[MAX];
int haybales[MAX];
int n, m, k, val[MAX];
void possible(){
    for(int i=1;i<n;i++){
        cout << "1\n";
    }
}
long long bfsVals[MAX];
bool check_haybale(int i){
    if(haybales[i]){return true;}
    fill(&checktwice[0],&checktwice[n+1],false);
    q.push({i,0});
    while(!q.empty()){
        auto now = q.top();q.pop();
        if(checktwice[now.node])continue;
        checktwice[now.node] = true;
        for(auto adj: path[now.node]){
            q.push({adj.first,adj.second+now.val});
            if(haybales[adj.first]){
                //check if elligible
                if(adj.second+now.val+val[adj.second]<=val[i]+haybales[adj.first]){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        path[a].push_back({b,c});
        path[b].push_back({a,c});
    }
    for(int i=1;i<=k;i++){
        int a, b;
        cin >> a >> b;
        haybales[a] = b;
    }
    for(int i=1;i<n;i++){
        val[i]=INF;
        check[i]=false;
    }
    val[n]=0; q.push({n,0});
    while(!q.empty()){
        auto now = q.top(); q.pop();
        if(check[now.node])continue;
        check[now.node] = true;
        for(auto adj: path[now.node]){
            if(val[adj.first] > val[now.node]+adj.second){
                val[adj.first] = val[now.node]+adj.second;
                q.push({adj.first,val[adj.first]});
            }
        }
    }
    
    //just run bfs from every node except the end and haybales
    for(int i=1;i<=n;i++){
        if(haybales[i])printf("yes");
    }
    
    return 0;
}
