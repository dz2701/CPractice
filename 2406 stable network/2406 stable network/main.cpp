//
//  main.cpp
//  2406 stable network
//
//  Created by dz2701 on 7/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
int n, m, p[MAX], sz[MAX];
int Find(int a){return p[a]==a?a:p[a]=Find(p[a]);}
struct edge{int st,ed,cost;}; bool cmp(edge a, edge b){return a.cost>b.cost;}
priority_queue<edge,vector<edge>,function<bool(edge,edge)>>pq(cmp);
bool Union(int a, int b){
    a = Find(a);b=Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    sz[b]+=sz[a];
    p[a]=b;
    return true;
}
map<pair<int,int>,int>cost;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int idx = n-2-m;
    for(int i=1;i<=n;i++){p[i]=i;sz[i]=1;}
    for(int i=1;i<=m;i++){
        int a, b; cin >> a >> b;
        Union(a,b);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int num; cin >> num;
            if(i<j and i!=1 and j!=1)pq.push({i,j,num});
        }
    }
    int ans = 0;
    vector<pair<int,int>>v;
    while(!pq.empty() and idx){
        if(Union(pq.top().st,pq.top().ed)){
            ans+=pq.top().cost;
            v.push_back({pq.top().st,pq.top().ed});
            idx--;
        }
        pq.pop();
    }
    printf("%d %d\n",ans,v.size());
    for(int i=v.size()-1;i>=0;i--){
        printf("%d %d\n",v[i].first,v[i].second);
    }
    
    
    return 0;
}
