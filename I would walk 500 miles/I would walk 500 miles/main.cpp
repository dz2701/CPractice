//
//  main.cpp
//  I would walk 500 miles
//
//  Created by dz2701 on 11/25/20.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll F1 = -84;
const ll  F2 = -48;
const ll F3 = 2019201997;
const int MAX = 7501;
ll get_dist(ll a, ll b){
    return a*F1 + b*F2 + F3;
}
struct edge{
    int st, ed;
    ll cost;
};
struct cmp{bool operator () (edge a, edge b){return a.cost<b.cost;}};
priority_queue<edge,vector<edge>,cmp>pq;

int sz[MAX], arr[MAX];
int Find(int a){
    if(arr[a]==a)return a;
    else return arr[a]=Find(arr[a]);
}
int tcnt;
bool Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    arr[a] = b;
    sz[b]+=sz[a];
    return true;
}
int main(){
    freopen("walk.in","r",stdin);freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            pq.push({int(i),int(j),get_dist(i,j)});
        }
    }
    //init union find
    for(int i=1;i<=n;i++){
        arr[i]=i;
        sz[i]=1;
    }
    //build mst
    tcnt = n;
    while(tcnt!=k){
        edge now = pq.top(); pq.pop();
        if(Union(now.st,now.ed))tcnt--;
    }
    while(!Union(pq.top().st,pq.top().ed))pq.pop();
    cout << pq.top().cost;
}
