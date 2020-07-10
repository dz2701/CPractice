//
//  main.cpp
//  16681 등산
//
//  Created by dz2701 on 7/8/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;
const int INF = 1e19;
int n, m, d, e;
int height[MAX];
vector<pair<int,int>>v[MAX];
struct mov{int node; long long val;}; bool cmp(mov a, mov b){return a.val>b.val;}
priority_queue<mov,vector<mov>,function<bool(mov,mov)>>pq(cmp);
long long rightval[MAX], oppval[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> d >> e;
    for(int i=1;i<=n;i++)cin >> height[i];
    for(int i=1;i<=m;i++){
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({b,c}); //for from home
        v[b].push_back({a,c}); //for from school
        
    }
    //dijkstra from home
    pq.push({1,0});
    for(int i=1;i<=n;i++)rightval[i]=INF;
    rightval[1]=0;
    
    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        for(auto adj: v[now.node]){
            if(rightval[adj.first]>now.val+adj.second and height[adj.first]>height[now.node]){
                rightval[adj.first] = now.val+adj.second;
                pq.push({adj.first,rightval[adj.first]});
            }
        }
        
    }
    
    //dijkstra from school
    while(!pq.empty())pq.pop();
    pq.push({n,0});
    for(int i=1;i<=n;i++)oppval[i]=INF;
    oppval[n]=0;
    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        for(auto adj: v[now.node]){
            if(oppval[adj.first]>now.val+adj.second and height[adj.first]>height[now.node]){
                oppval[adj.first] = now.val+adj.second;
                pq.push({adj.first,oppval[adj.first]});
            }
        }
    }
    
    long long ans = -INF;
    
    for(int i=2;i<n;i++){
        //select i as the 'pitch point'
        
        if(rightval[i]==INF or oppval[i]==INF)continue;
        else ans = max(ans, height[i]*e - d*(rightval[i]+oppval[i]));
    }
    
    if(ans==-INF)cout << "Impossible";
    else cout << ans;
    return 0;
}
