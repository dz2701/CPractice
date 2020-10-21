//
//  main.cpp
//  10652 Piggy Back
//
//  Created by dz2701 on 9/24/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 4e4+1;
int B, E, P;
int n, m;
int visit[MAX];
struct travel{int node, dist;};
vector<int>adj[MAX];
int distfrom1[MAX], distfrom2[MAX], distfromN[MAX];
int main(){
    freopen("piggyback.in","r",stdin);
    freopen("piggyback.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> B >> E >> P >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<travel>q;
    q.push({1,0});
    //initialize
    fill(&visit[0],&visit[MAX],0);
    while(!q.empty()){
        travel front = q.front(); q.pop();
        if(visit[front.node])continue;
        visit[front.node]=1;
        distfrom1[front.node] = front.dist;
        for(int i: adj[front.node]){
            q.push({i,front.dist+1});
        }
    }
    //if over, queue empty
    
    q.push({2,0});
    fill(&visit[0],&visit[MAX],0);
    while(!q.empty()){
        travel front = q.front(); q.pop();
        if(visit[front.node])continue;
        visit[front.node]=1;
        distfrom2[front.node] = front.dist;
        for(int i:adj[front.node]){
            q.push({i,front.dist+1});
        }
    }
    
    //if over, queue empty
    
    q.push({n,0});
    fill(&visit[0],&visit[MAX],0);
    while(!q.empty()){
        travel front = q.front(); q.pop();
        if(visit[front.node])continue;
        visit[front.node] = 1;
        distfromN[front.node] = front.dist;
        for(int i:adj[front.node]){
            q.push({i,front.dist+1});
        }
    }
    
    //did all bfs, now have all distances
    int ans = 1e9;
    for(int meet = 1; meet<=n; meet++){
        ans = min(ans, B*distfrom1[meet] + E*distfrom2[meet] + P*distfromN[meet]);
    }
    cout << ans;
    return 0;
}
