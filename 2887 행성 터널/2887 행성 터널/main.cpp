//
//  main.cpp
//  2887 행성 터널
//
//  Created by dz2701 on 7/5/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
struct planet{int x,y,z;};
struct edge{int st,ed,cost;};
bool cmp(edge a, edge b){return a.cost>b.cost;};
priority_queue<edge,vector<edge>,function<bool(edge,edge)>>pq(cmp);
planet init[MAX]; int p[MAX], sz[MAX];
int n;

int Find(int a){
    if(p[a]==a)return a;
    else return p[a]=Find(p[a]);
}
bool Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    sz[b]+=sz[a];
    p[a]=b;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> init[i].x >> init[i].y >> init[i].z;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            pq.push({i,j,min(abs(init[i].x-init[j].x),min(abs(init[i].y-init[j].y),abs(init[i].z-init[j].z)))});
        }
    }
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=n;i++)sz[i]=1;
    int idx = n-1; int cost=0;
    while(!pq.empty() and idx){
        if(Union(pq.top().st,pq.top().ed)){
            cost+=pq.top().cost;
            idx--;
        }
        pq.pop();
    }
    
    cout << cost;
    
    return 0;
}
