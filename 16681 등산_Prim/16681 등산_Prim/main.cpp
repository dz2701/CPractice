//
//  main.cpp
//  16681 등산_Prim
//
//  Created by dz2701 on 7/8/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e6+6;
const int INF = 1e9+5;
int n, m, d, e;
int height[MAX], val1[MAX], val2[MAX];
vector<pair<int,int>>v[MAX];
struct travel{int node, val;}; bool cmp(travel a, travel b){return a.val>b.val;}
//going to use array instead of heap. this takes v^2, instead of ElogE.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> d >> e;
    for(int i=1;i<=n;i++)cin >> height[i];
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    //dijkstra from home
    
    //start from 1, 0;
    for(int i=1;i<=n;i++)val1[i]=INF; val1[1]=0;
    int current = 1;
    
    int visit[MAX]; memset(visit,0,sizeof(visit));
    for(int i=0;i<n;i++){
        visit[current]=1;
        int tempcost = INF, tempcur = 0;
        for(auto adj:v[current]){
            if(height[adj.first]>height[current]){
                val1[adj.first] = min(val1[adj.first],val1[current]+adj.second);
            }
        }
        for(int j=2;j<n;j++){
            if(val1[j]<tempcost and visit[j]!=1){
                tempcost = val1[j];
                tempcur = j;
            }
        }
        current = tempcur;
    }
    
    //dijkstra from school
    
    for(int i=1;i<=n;i++)val2[i]=INF; val2[n]=0;
    current = n;
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n;i++){
        visit[current]=1;
        int tempcost = INF, tempcur = 0;
        for(auto adj:v[current]){
            if(height[adj.first]>height[current]){
                val2[adj.first] = min(val2[adj.first],val2[current]+adj.second);
            }
        }
        for(int j=2;j<n;j++){
            if(val2[j]<tempcost and visit[j]!=1){
                tempcost = val2[j];
                tempcur = j;
            }
        }
        current = tempcur;
    }
    int ans = -INF;
    for(int i=1;i<=n;i++){
        if(val1[i]==INF or val2[i]==INF)continue;
        else ans = max(ans,height[i]*e-d*(val1[i]+val2[i]));
    }
    if(ans==-INF)cout << "Impossible";
    else cout << ans;
}

