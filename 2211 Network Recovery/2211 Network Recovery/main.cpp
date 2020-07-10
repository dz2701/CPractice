//
//  main.cpp
//  2211 Network Recovery
//
//  Created by dz2701 on 7/10/20.
//  Copyright © 2020 dz2701. All rights reserved.
//


#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3+5;
const int INF = 1e9+5;
struct edge{int st,ed,cost;}; struct travel{int node, val;};
bool cmp(travel a, travel b){return a.val>b.val;}
bool qq(edge a, edge b){return a.cost>b.cost;}
priority_queue<travel,vector<travel>,function<bool(travel,travel)>>pq(cmp);
priority_queue<edge,vector<edge>,function<bool(edge,edge)>>q(qq);
vector<pair<int,int>>v[MAX];
int n, m, val[MAX], p[MAX], sz[MAX];
int Find(int a){return p[a]==a?a:p[a]=Find(p[a]);}
bool Union(int a, int b){a=Find(a);b=Find(b);if(a==b)return false;if(sz[a]>sz[b])swap(a,b);sz[b]+=sz[a];p[a]=b;return true;}
int arr[MAX]; vector<pair<int,int>>path; int visit[MAX];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
        q.push({a,b,c});
        q.push({b,a,c});
    }
    
    //do dijkstra
    for(int i=2;i<=n;i++)val[i]=INF;
    val[1]=0;
    pq.push({1,0});
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        for(auto adj: v[now.node]){
            if(val[adj.first]>adj.second + now.val){
                val[adj.first] = adj.second+now.val;
                pq.push({adj.first,val[adj.first]});
            }
        }
    }
    //val[] has the minimum distances from node 1
    
    //now build mst, but one thing that we must check is that the distance from root must be shoter or equal to the original one
    //so let's use prim
    
    fill(&arr[0],&arr[MAX],INF);
    fill(&visit[0],&visit[MAX],0);
    arr[1]=0; int prev = 1;
    for(int i=1;i<=n;i++){
        int minval = 1e9, minidx = -1;
        
        for(int j=1;j<=n;j++){
            if(!visit[j] and arr[j]<minval and arr[j]<=val[j]){
                minval = arr[j];
                minidx = j;
            }
        }
        if(minidx==-1)break; //if it can't select anything, return
        path.push_back(make_pair(prev,minidx));
        prev = minidx;
        visit[minidx] = 1;
        for(auto adj: v[minidx]){
            arr[adj.first] = min(arr[adj.first], adj.second);
        }
    }
    cout << path.size()-1 <<"\n";
    for(auto pair : path){
        if(!(pair.first==1 and pair.second==1))printf("%d %d\n",pair.first, pair.second);
    }
    
    return 0;
}
