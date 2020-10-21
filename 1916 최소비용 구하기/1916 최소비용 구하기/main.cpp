//
//  main.cpp
//  1916 최소비용 구하기
//
//  Created by dz2701 on 10/2/20.
//

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1001];
struct path{int node, cost;};
vector<pair<int,int>>adj[1001];
bool cmp(path a, path b){return a.cost<b.cost;}
int main(){
    cin >> n; cin >> m;
    for(int i=1;i<=m;i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    int st, ed; cin >> st >> ed;
    priority_queue<path,vector<path>,function<bool(path,path)>>pq(cmp);
    fill(&arr[0],&arr[1001],1e9);
    pq.push({st,0}); arr[st]=0;
    while(!pq.empty()){
        path a = pq.top(); pq.pop();
        for(pair<int,int>c : adj[a.node]){
            if(arr[c.first]>a.cost+c.second){
                pq.push({c.first,a.cost+c.second});
                arr[c.first] = a.cost+c.second;
            }
        }
    }
    cout << arr[ed];
    return 0;
}
