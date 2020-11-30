//
//  main.cpp
//  18262 Milk Pumping
//
//  Created by dz2701 on 11/30/20.
//

//ORDER: COST, FLOW
#include <bits/stdc++.h>
using namespace std;
int n,m;
const int INF = 1e5;
struct road{int dest; double cost, flow;};
vector<road>adj[1001];
double arr[1001];
struct state{int node; double c, f;}; struct cmp{bool operator () (state a, state b){return a.f/a.c > b.f/b.c;}};
priority_queue<state,vector<state>,cmp>pq;

int getans(double a){
    return a * 1e6;
}
int main(){
    freopen("pump.in","r",stdin);
    freopen("pump.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b; double c, d;
        cin >> a >> b >> c >> d;
        adj[a].push_back({b,c,d});
        adj[b].push_back({a,c,d});
    }
    pq.push({1,0,INF});
    fill(arr,arr+n+1,-INF);
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        //printf("%d, %f, %f\n",now.node,now.c,now.f);
        for(auto con : adj[now.node]){
            if(arr[con.dest]<min(now.f,con.flow) / (now.c+con.cost)){
                pq.push({con.dest,now.c+con.cost,min(now.f,con.flow)});
                arr[con.dest] = min(now.f,con.flow) / (now.c+con.cost);
            }
        }
    }
    cout << getans(arr[n]);
    
}
