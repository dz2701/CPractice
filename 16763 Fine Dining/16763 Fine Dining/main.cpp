//
//  main.cpp
//  16763 Fine Dining
//
//  Created by dz2701 on 7/10/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
const int INF = 1e9+5;
int n, m, k, haybales[MAX]; vector<pair<int,int>>v[MAX]; vector<int>haynum;
struct mov{int node, val;}; bool cmp(mov a, mov b){return a.val>b.val;}
priority_queue<mov,vector<mov>,function<bool(mov,mov)>>pq(cmp);
int val[MAX];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    fill(&haybales[0],&haybales[MAX],0);
    for(int i=1;i<=k;i++){
        int a, b; cin >> a >> b;
        haybales[a]=b;
        haynum.push_back(a);
    }
    fill(&val[0],&val[MAX],INF);
    val[n]=0; pq.push({n,0});
    
    
}
