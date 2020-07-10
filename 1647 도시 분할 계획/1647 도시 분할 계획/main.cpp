//
//  main.cpp
//  1647 도시 분할 계획
//
//  Created by dz2701 on 7/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+5;
struct edge{int st,ed,cost;};
bool cmp(edge a, edge b){return a.cost>b.cost;}
priority_queue<edge,vector<edge>,function<bool(edge,edge)>>pq(cmp);
int n, m, p[MAX],sz[MAX];
int Find(int a){
    return p[a]==a? a : p[a]=Find(p[a]);
}
bool Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    p[a]=b;
    sz[b]+=a;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        pq.push({a,b,c});
    }
    int idx = n-1;
    int ans = 0, mm = -1e9;
    for(int i=1;i<=n;i++){
        p[i]=i;
        sz[i]=1;
    }
    while(!pq.empty() and idx){
        if(Union(pq.top().st,pq.top().ed)){
            ans +=pq.top().cost;
            mm=max(mm,pq.top().cost);
            idx--;
        }
        pq.pop();
    }
    cout << ans - mm;
}
