//
//  main.cpp
//  10038 Dueling GPSs
//
//  Created by dz2701 on 10/15/20.
//

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int MAX = 1e4+1; const int INF = 1e9;
int n, m;
struct state{int node, val;}; struct cmp{bool operator () (state a, state b){return a.val>b.val;};};
vector<pii>GPS[MAX][2], RGPS[MAX][2];
int val1[MAX], val2[MAX], alert[MAX];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, c1, c2;
        cin >> a >> b >> c1 >> c2;
        GPS[a][0].push_back(make_pair(b,c1));
        GPS[a][1].push_back(make_pair(b,c2));
        RGPS[b][0].push_back(make_pair(a,c1));
        RGPS[b][1].push_back(make_pair(a,c2));
    }
    //dijkstra to find minimum val for each node
    //GPS1:
    priority_queue<state,vector<state>,cmp>pq; fill(&val1[0],&val1[MAX],INF);
    pq.push({n,0}); val1[n] = 0;
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        if(now.val > val1[now.node])continue;
        for(pii conn : RGPS[now.node][0]){
            if(val1[conn.first]>now.val + conn.second){
                val1[conn.first] = now.val + conn.second;
                pq.push({conn.first,val1[conn.first]});
            }
        }
    }
    //GPS2: (pq should be empty)
    fill(&val2[0],&val2[MAX],INF);
    pq.push({n,0}); val2[n] = 0;
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        if(now.val > val2[now.node])continue;
        for(pii conn : RGPS[now.node][1]){
            if(val2[conn.first] > now.val + conn.second){
                val2[conn.first] = now.val + conn.second;
                pq.push({conn.first, val2[conn.first]});
            }
        }
    }
    
    //checking dijkstra; remove after debug
    /*
    for(int i=1;i<=n;i++){
        printf("val1[%d]=%d\n",i,val1[i]);
    }
    for(int i=1;i<=n;i++){
        printf("val2[%d]=%d\n",i,val2[i]);
    }
    */
    //using same method to perform dijkstra but value == alerting, real value == pair<> rval;
    //pq should be empty by now
    fill(&alert[0],&alert[MAX],INF); alert[1]=0; pq.push({1,0});
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        if(alert[now.node] < now.val)continue;
        for(int i=0;i<GPS[now.node][0].size();i++){
            int fac = 0;
            if(val1[now.node] != val1[GPS[now.node][0][i].first] + GPS[now.node][0][i].second)fac++;
            if(val2[now.node] != val2[GPS[now.node][0][i].first] + GPS[now.node][1][i].second)fac++;
            //printf("looking at %d -> %d\n",now.node,GPS[now.node][0][i].first);
            if(alert[GPS[now.node][0][i].first] > now.val + fac){
                //printf("updating GPS[%d]: -> %d\n",GPS[now.node][0][i].first, now.val+fac);
                alert[GPS[now.node][0][i].first] = now.val + fac;
                pq.push({GPS[now.node][0][i].first, fac+now.val});
            }
        }
    }
    cout << alert[n];
    return 0;
}
