//
//  main.cpp
//  Moocast
//
//  Created by dz2701 on 7/5/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3+5;
//using mst
pair<int,int>cows[MAX]; int n; int p[MAX], sz[MAX];
struct edge{
    int st, ed, cost;
};
bool cmp(edge a, edge b){return a.cost>b.cost;}
int Find(int a){
    if(p[a]==a)return a;
    else return p[a]=Find(p[a]);
}
bool Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    //b is always bigger
    p[a] = b;
    sz[b]+=sz[a];
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> cows[i].first >> cows[i].second;
    }
    //need each 'connection' in an 'edge' form. create graph
    priority_queue<edge,vector<edge>,function<bool(edge,edge)>>pq(cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<j){
                int cost = pow((cows[i].first-cows[j].first),2) + pow((cows[i].second-cows[j].second),2);
                pq.push({i,j,cost});
            }
        }
    }
    
    for(int i=1;i<=n;i++){p[i]=i;sz[i]=1;}
    int idx = n-1; int cost = 0;
    while(!pq.empty() and idx){
        //need check if this will make a cycle
        if(Union(pq.top().st,pq.top().ed)){
            cost = max(pq.top().cost,cost);
            idx--;
        }
        pq.pop();
    }
    
    cout << cost;
    
    return 0;
    
}
