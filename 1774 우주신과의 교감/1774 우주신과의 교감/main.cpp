//
//  main.cpp
//  1774 우주신과의 교감
//
//  Created by Shin Lee on 12/23/20.
//

#include <bits/stdc++.h>
#define pii pair<double, double>
using namespace std;
const int MAX = 1e3+1;
struct edge{int st, ed; double val;}; struct cmp{bool operator () (edge a, edge b){
    return a.val>b.val;}};priority_queue<edge,vector<edge>,cmp>pq;
pii coor[MAX];
int check[MAX][MAX];
int n, k;
int sz[MAX], arr[MAX];
int Find(int a){
    if(arr[a]==a)return a;
    else return arr[a] = Find(arr[a]);
}
bool Union(int a, int b){
    a = Find(a); b = Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    sz[b]+=sz[a];
    arr[a]=b;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> coor[i].first >> coor[i].second;
        arr[i]=i;
        sz[i]=1;
    }
    for(int i=1;i<=k;i++){
        int a, b; cin >> a >> b;
        check[a][b] = 1; check[b][a]=1;
        pq.push({a,b,0});
    }
    int cnt = n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!check[i][j])pq.push({i,j,sqrt(pow(coor[i].first-coor[j].first,2) + pow(coor[i].second-coor[j].second,2))});
        }
    }
    double cost=0;
    while(!pq.empty() and cnt){
        edge now = pq.top(); pq.pop();
        if(Union(now.st, now.ed)){
            cost+=now.val;
            cnt--;
        }
    }
    printf("%.2f",cost);
    return 0;
}
