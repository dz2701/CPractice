//
//  main.cpp
//  1197 Minimum Spanning Tree
//
//  Created by dz2701 on 7/1/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int p[MAX], sz[MAX], nodes[MAX];
struct edgetype{
    int a, b, cost;
};
edgetype edges[MAX];
//using kruskal's algorithm using union find
int Find(int cur){
    if(p[cur]==cur)return cur;
    return p[cur] = Find(p[cur]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a==b)return;
    if(sz[a]>sz[b])swap(a,b);
    //b is the bigger one.
    p[a]=b;
    sz[b]+=sz[a];
}
bool cmp(edgetype a, edgetype b){return a.cost<b.cost;};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e;
    cin >> v >> e;
    for(int i=1;i<=e;i++){
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
    }
    sort(edges+1,edges+e+1,cmp);
    for(int i=1;i<=v;i++)p[i]=i;
    int ans=0;
    for(int i=1;i<=e;i++){
        if(Find(edges[i].a)==Find(edges[i].b))continue;
        Union(edges[i].a,edges[i].b);
        ans+=edges[i].cost;
    }
    
    cout << ans;
    return 0;
}
