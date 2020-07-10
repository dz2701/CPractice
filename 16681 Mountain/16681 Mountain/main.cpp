//
//  main.cpp
//  16681 Mountain
//
//  Created by dz2701 on 7/10/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;
const long long INF = 1e15+5;
vector<pair<int,int>>v[MAX]; int n, m, d, e; int height[MAX];
long long fromhome[MAX], fromschool[MAX];
struct climb{int node; long long val;}; bool cmp(climb a, climb b){return a.val>b.val;}
priority_queue<climb, vector<climb>, function<bool(climb,climb)>>pq(cmp);
priority_queue<climb, vector<climb>, function<bool(climb,climb)>>qq(cmp);
long long getval(int i){
    return (height[i]*e)-(d*(fromhome[i]+fromschool[i]));
}
bool check[MAX];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> d >> e;
    for(int i=1;i<=n;i++){
        cin >> height[i];
    }
    for(int i=1;i<=m;i++){
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    
    //initiate from home
    fill(&check[0],&check[MAX],false);
    for(int i=1;i<=n;i++)fromhome[i]=INF;
    pq.push({1,0}); fromhome[1] = 0;
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        if(check[now.node])continue;
        check[now.node] = true;
        for(auto adj: v[now.node]){
            if(fromhome[adj.first]>=now.val+adj.second and height[now.node]<height[adj.first]){
                fromhome[adj.first] = now.val+adj.second;
                pq.push({adj.first,fromhome[adj.first]});
            }
        }
    }
    
    for(int i=1;i<=n;i++)fromschool[i]=INF;
    qq.push({n,0}); fromschool[n]=0;
    fill(&check[0],&check[MAX],false);
    while(!qq.empty()){
        auto now = qq.top(); qq.pop();
        if(check[now.node])continue;
        check[now.node] = true;
        for(auto adj: v[now.node]){
            if(fromschool[adj.first]>=now.val+adj.second and height[now.node]<height[adj.first]){
                fromschool[adj.first] = now.val+adj.second;
                qq.push({adj.first,fromschool[adj.first]});
            }
        }
    }
    
    
    
    long long ans = -INF;
    for(int i=2;i<n;i++){
        if(fromhome[i]==INF or fromschool[i]==INF)continue;
        ans = max(ans,getval(i));
    }
    
    if(ans!=-INF)cout << ans;
    else cout << "Impossible";
    
    return 0;
    
}
