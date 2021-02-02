//
//  main.cpp
//  14044 Phonomenal Reviews
//
//  Created by Shin Lee on 1/8/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int n,m; int isPho[MAX];
vector<int>adj[MAX];
int prevPho = -1, prevPhoDeg = 0;
long long sum = 0;
set<int>s;
void dfs(int node, int val, int parent){
    if(isPho[node]){
        sum+= val * 2* (m-1);
        s.insert(val);
    }
    for(int con : adj[node])if(con != parent)dfs(con,val+1,node);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){int temp; cin >> temp; isPho[temp+1]=1;}
    for(int i=1;i<=n-1;i++){
        int a, b; cin >> a >> b;
        adj[a+1].push_back(b+1);
        adj[b+1].push_back(a+1);
    }
    //for distnace between two nodes, we can simply get the sum of degree.
    
    dfs(1,0,-1);
    
    //now construct trees only with phos: impossible, so do during dfs.
    //only value needed: all paths are taken degree * (n-1) times. Therefore, subtract the only largest value of a+b.
    
    int temp = *s.begin(); s.erase(s.begin()); temp+= *s.begin();
    cout << sum - temp;
}
