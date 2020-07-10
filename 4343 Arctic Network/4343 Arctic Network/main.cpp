//
//  main.cpp
//  4343 Arctic Network
//
//  Created by dz2701 on 7/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e2+2;
int t, n, m, p[MAX], sz[MAX];
struct post{double x,y;}; post posts[MAX];
struct edge{int st,ed; double cost;}; bool cmp(edge a, edge b){return a.cost>b.cost;}
priority_queue<edge,vector<edge>,function<bool(edge,edge)>>pq(cmp);
double get_dist(post a, post b){return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));}
int Find(int a){return p[a]==a?a:p[a]=Find(p[a]);}
bool Union(int a, int b){
    a = Find(a);b=Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    sz[b]+=sz[a];
    p[a]=b;
    return true;
}
vector<double>costs;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        while(!pq.empty())pq.pop(); //initialize pq
        cin >> n >> m;
        for(int i=1;i<=m;i++){
            cin >> posts[i].x >> posts[i].y;
        }
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;j++){
                pq.push({i,j,get_dist(posts[i],posts[j])});
            }
        }
        costs.clear();
        int idx = m-1;
        for(int i=1;i<=m;i++){p[i]=i;sz[i]=1;}
        while(!pq.empty() and idx){
            if(Union(pq.top().st,pq.top().ed)){
                costs.push_back(pq.top().cost);
                idx--;
            }
            pq.pop();
        }
        printf("%.2f\n",costs[costs.size()-n]);
    }
    
}
