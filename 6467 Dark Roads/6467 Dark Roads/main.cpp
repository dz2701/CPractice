//
//  main.cpp
//  6467 Dark Roads
//
//  Created by dz2701 on 7/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;
int n, m; int p[MAX], sz[MAX];
struct edge{int st,ed,cost;};
bool cmp(edge a, edge b){return a.cost>b.cost;}
priority_queue<edge,vector<edge>,function<bool(edge,edge)>>pq(cmp);
int Find(int a){return p[a]==a? a : p[a]=Find(p[a]);}
bool Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a==b)return false;
    if(sz[a]>sz[b])swap(a,b);
    p[a]=b;
    sz[b]+=sz[a];
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        cin >> m >> n;
        if(m==0 and n==0)break;
        int oans=0;
        for(int i=0;i<n;i++){
            int a, b, c; cin >> a >> b >> c;
            oans+=c;
            pq.push({a+1,b+1,c});
        }
        int idx = m-1, ans = 0;
        for(int i=1;i<=m;i++){p[i]=i;sz[i]=1;} //initialize
        while(!pq.empty() and idx){
            if(Union(pq.top().st,pq.top().ed)){
                ans+=pq.top().cost;
                idx--;
            }
            pq.pop();
        }
        cout << oans-ans << "\n";
        while(!pq.empty())pq.pop(); //empty queue
    }
    return 0;
}
