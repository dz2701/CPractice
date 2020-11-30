//
//  main.cpp
//  18316 Time is Mooney
//
//  Created by dz2701 on 11/30/20.
//

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int city[1001];
vector<int>adj[1001];
struct ss{int val, dist;};
ss arr[1001];
struct state{int node, val, dist;};
struct cmp{bool operator () (state a, state b){return a.val>b.val;}};
int n, m, c;
int get_dist(int a, int b){return a - c*b*b;}
int main(){
    //freopen("time.in","r",stdin);
    //freopen("time.out","w",stdout);
    cin >> n >> m >> c;
    for(int i=1;i<=n;i++){
        cin >> city[i];
    }
    for(int i=1;i<=m;i++){
        int dep, arr;
        cin >> dep >> arr;
        adj[dep].push_back(arr); //dep --> arr road
    }
    for(int i=1;i<=n;i++)arr[i] = {-INF,0};
    priority_queue<state,vector<state>,cmp> pq;
    pq.push({1,0,0});
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        //printf("now = %d, %d, %d\n",now.node,now.val,now.dist);
        for(int con : adj[now.node]){
            //printf("looking at adjacent node %d:\n",con);
            //printf("original value = %d.\n",get_dist(arr[con].val,arr[con].dist));
            //printf("new value = %d.\n",get_dist(now.val,now.dist+1) + city[con]);
            if(get_dist(arr[con].val,arr[con].dist) < get_dist(now.val,now.dist+1) + city[con]){
                //printf("satisfied.\n");
                pq.push({con,now.val + city[con], now.dist+1});
                arr[con].val = now.val + city[con];
                arr[con].dist = now.dist+1;
            }
        }
    }
    cout << get_dist(arr[1].val,arr[1].dist);
}
