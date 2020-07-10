//
//  main.cpp
//  1922 네트워크 연결
//
//  Created by dz2701 on 7/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3+5;
struct edge{int st, ed, cost;};
int n, m, p[MAX], sz[MAX];
bool cmp(edge a, edge b){return a.cost>b.cost;}
priority_queue<edge,vector<edge>,function<bool(edge,edge)>>pq(cmp);
int Find(int a){
    if(p[a]==a)return a;
    else return p[a]=Find(p[a]);
}
bool Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    p[a]=b;
    sz[a]+=sz[b];
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, c; cin >> a >> b >> c;
        pq.push({a,b,c});
    }
    int idx = n-1;
    int ans = 0;
    for(int i=1;i<=n;i++){
        p[i] = i;
        sz[i] = 1;
    }
    while(!pq.empty() and idx){
        if(Union(pq.top().st,pq.top().ed)){
            ans+=pq.top().cost;
            idx--;
        }
        pq.pop();
    }
    
    cout << ans;
    return 0;
}
