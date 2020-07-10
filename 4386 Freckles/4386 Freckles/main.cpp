//
//  main.cpp
//  4386 Freckles
//
//  Created by dz2701 on 7/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
int n;
struct edge{int st,ed;double cost;};
bool cmp(edge a, edge b){return a.cost>b.cost;}
priority_queue<edge,vector<edge>,function<bool(edge,edge)>>pq(cmp);
pair<double,double>star[MAX];
int p[MAX],sz[MAX];
int Find(int a){return p[a]==a?a:p[a]=Find(p[a]);}
bool Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    p[a]=b;
    sz[b]+=sz[a];
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> star[i].first >> star[i].second;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            double c = sqrt(pow((star[i].first-star[j].first),2)+pow((star[i].second-star[j].second),2));
            pq.push({i,j,c});
        }
    }
    
    int idx = n-1;
    for(int i=1;i<=n;i++){
        p[i] = i;
        sz[i] = 1;
    }
    double cost=0;
    while(!pq.empty() and idx){
        if(Union(pq.top().st,pq.top().ed)){
            cost+=pq.top().cost;
            idx--;
        }
        pq.pop();
    }
    printf("%.2f",cost);
    return 0;
     
}
