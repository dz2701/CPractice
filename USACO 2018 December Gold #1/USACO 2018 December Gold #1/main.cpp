//
//  main.cpp
//  USACO 2018 December Gold #1
//
//  Created by Shin Lee on 12/18/20.
//

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int MAX = 1e5+1;
const int INF = 1e9;
int n, m, k;
vector<pii>adj[MAX];
vector<pii>newadj[MAX];
struct state{int node; long long val; int taken_hay;}; struct cmp{bool operator() (state a, state b){return a.val<b.val;}};
priority_queue<state,vector<state>,cmp>pq;
int haybale[MAX];
long long dist[int(5e4)+1], arr[int(5e4)+1];
int main(){
    freopen("dining.in","r",stdin);
    freopen("dining.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c}); adj[b].push_back({a,c});
    }
    for(int i=1;i<=k;i++){
        int a, b; cin >> a >> b;
        haybale[a] = b;
    }
    pq.push({n,0}); dist[n]=0;
    fill(arr,arr+int(5e4)+1, INF);
    fill(dist,dist+int(5e4)+1, INF);
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        for(auto con : adj[now.node]){
                if(dist[con.first] > now.val + con.second){
                    dist[con.first] = now.val + con.second;
                    pq.push({con.first, dist[con.first],0});
                }
        }
    }
    
    //must take to haybale
    
    pq.push({n,0}); arr[n]=0;
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        for(auto con : adj[now.node]){
            if((now.taken_hay and !con.second) or !now.taken_hay){
                if(arr[con.first] > now.val + con.second){
                    arr[con.first] = now.val + con.second;
                    pq.push({con.first, arr[con.first], now.taken_hay + con.second});
                }
            }
        }
    }
    
    for(int i=1;i<n;i++){
        if(arr[i]<=dist[i]){
            cout << 1 << "\n";
        }else cout << 0 << "\n";
    }
    return 0;
}
