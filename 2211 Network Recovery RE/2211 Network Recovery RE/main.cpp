//
//  main.cpp
//  2211 Network Recovery RE
//
//  Created by dz2701 on 7/13/20.
//  Copyright © 2020 dz2701. All rights reserved.
// FINALLY!!!

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+5;
const long long INF = 1e15;
vector<pair<long long,long long>>v[MAX];
struct mov{int node; long long val;};
bool movcmp(mov a, mov b){return a.val>b.val;}
int n, m; long long val[MAX]; bool check[MAX];
pair<long long, long long>MSTval[MAX]; int p[MAX], sz[MAX];
int Find(int a){return p[a]==a?a:p[a]=Find(p[a]);}
bool Union(int a, int b){a=Find(a);b=Find(b);if(a==b)return false;if(sz[a]>sz[b])swap(a,b);sz[b]+=sz[a];p[a]=b;return true;}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));

    }
    
    
    //build minimum spanning tree, but when connecting, we need to make sure that it takes no longer than the shortest path before. Therefore, we will make val[MAX] a dijkstra array to see the mimnimum length.
    priority_queue<mov,vector<mov>,function<bool(mov,mov)>>pq(movcmp);
    fill(&val[0],&val[n+1],INF); fill(&check[0],&check[n+1],false); val[1]=0; pq.push({1,0});
    while(!pq.empty()){
        mov now = pq.top(); pq.pop();
        if(check[now.node])continue;
        check[now.node]=true;
        for(pair<int,int> adj : v[now.node]){
            if(val[adj.first]>adj.second + now.val){
                val[adj.first] = adj.second + now.val;
                pq.push({adj.first,val[adj.first]});
            }
        }
    }
    
    //now we will build a MST, but the only thing different will be checking for the distance (if it is elligible, i.e smaller or equal to val[i]. USE PRIM
    for(int i=1;i<=n;i++){p[i]=i;sz[i]=1;} for(int i=1;i<=n;i++){MSTval[i].second = INF; MSTval[i].first = -1;}
    fill(&check[0],&check[n+1],false);
    vector<pair<int,int>>path; MSTval[1]={0,0}; long long prev = 1; check[1] = true;
    for(auto adj : v[1]){
        MSTval[adj.first].second = min(MSTval[adj.first].second, adj.second);
        MSTval[adj.first].first = 1;
    }
    for(int i=1;i<=n;i++){
        long long Min = 1e12, Minidx = -1;
        for(int j=1;j<=n;j++){
            //find most efficient node to move
            if(!check[j] and MSTval[j].second < Min){
                Min = MSTval[j].second; Minidx = j;
            }
        }
        //check if this node is elligible...
        check[Minidx] = true;
        if(Minidx!=-1 and Min <= val[Minidx]){
            path.push_back({MSTval[Minidx].first,Minidx});
            prev = Minidx;
        }else if(Minidx==-1){
            break;
        }
        
        for(auto adj : v[Minidx]){
            if(MSTval[adj.first].second > adj.second+MSTval[Minidx].second){
                MSTval[adj.first].second = adj.second+MSTval[Minidx].second;
                MSTval[adj.first].first = prev;
            }
        }
    }
    
    cout << path.size() << "\n";
    for(int i=0;i<path.size();i++){cout << path[i].first << " " << path[i].second << "\n";}
    return 0;
}
