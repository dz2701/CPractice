//
//  main.cpp
//  2887 SVEMIR
//
//  Created by dz2701 on 7/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
struct edge{int st,ed,cost;};
bool cmp(edge a, edge b){return a.cost>b.cost;}
priority_queue<edge,vector<edge>,function<bool(edge,edge)>>pq(cmp);
int n, p[MAX], sz[MAX];
struct planet{int x,y,z,id;};
bool cmpx(planet a, planet b){return a.x<b.x;}
bool cmpy(planet a, planet b){return a.y<b.y;}
bool cmpz(planet a, planet b){return a.z<b.z;}
planet ps[MAX];
int get_min(planet a, planet b){
    return min(abs(a.x-b.x),min(abs(a.y-b.y),abs(a.z-b.z)));
}
int Find(int a){return p[a]==a?a:p[a]=Find(p[a]);}
bool Union(int a, int b){
    a=Find(a);b=Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    p[a]=b;
    sz[b]+=a;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ps[i].x >> ps[i].y >> ps[i].z;
        ps[i].id = i;
    }
    sort(ps+1,ps+n+1,cmpx);
    pq.push({ps[1].id,ps[2].id,get_min(ps[1],ps[2])});
    for(int i=2;i<=n;i++){
        pq.push({ps[i-1].id,ps[i].id,get_min(ps[i-1],ps[i])});
    }
    sort(ps+1,ps+n+1,cmpy);
       pq.push({ps[1].id,ps[2].id,get_min(ps[1],ps[2])});
       for(int i=2;i<=n;i++){
           pq.push({ps[i-1].id,ps[i].id,get_min(ps[i-1],ps[i])});
       }
    sort(ps+1,ps+n+1,cmpz);
       pq.push({ps[1].id,ps[2].id,get_min(ps[1],ps[2])});
       for(int i=2;i<=n;i++){
           pq.push({ps[i-1].id,ps[i].id,get_min(ps[i-1],ps[i])});
       }
    for(int i=1;i<=n;i++){p[i]=i;sz[i]=1;}
    int idx = n-1; int ans = 0;
    while(!pq.empty() and idx){
        if(Union(pq.top().st,pq.top().ed)){
            ans+=pq.top().cost;
            idx--;
        }
        pq.pop();
    }
    
    cout << ans;
    
}
