//
//  main.cpp
//  Milk Pumping recap
//
//  Created by Shin Lee on 2/27/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, m; const int MAX = 1001;
struct edge{int dest; double c, f;};
vector<edge>adj[MAX];
double arr[MAX];
struct cmp{bool operator () (edge a, edge b){return a.f/a.c > b.f/b.c;}};
priority_queue<edge,vector<edge>,cmp>pq;
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b; cin >> a >> b;
        double c, f; cin >> c >> f;
        adj[a].push_back({b,c,f});
        adj[b].push_back({a,c,f});
    }
    fill(arr,arr+n,-1e9);
    arr[1]=0;
    pq.push({1,0,0});
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        if(now.f/now.c <= arr[now.dest])continue;
        arr[now.dest] = now.f/now.c;
        for(auto con : adj[now.dest]){
            pq.push({con.dest,now.f+con.f,now.c+con.c});
        }
    }
    cout << (int)(arr[n]*1000);
}
