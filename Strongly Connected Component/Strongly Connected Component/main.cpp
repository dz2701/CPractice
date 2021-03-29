//
//  main.cpp
//  Strongly Connected Component
//
//  Created by Shin Lee on 3/10/21.
//

#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<int>edge[10001];
vector<int>redge[10001];
int Visit[10001];
stack<int>order;
void dfs(int cur){
    if(Visit[cur])return;
    Visit[cur]=1;
    for(int con:edge[cur]){
        dfs(con);
    }
    order.push(cur);
}
set<int>res;
void rdfs(int cur){
    if(Visit[cur])return;
    Visit[cur]=1;
    res.insert(cur);
    for(int con:redge[cur]){
        rdfs(con);
    }
    res.insert(cur);
}

bool cmp(vector<int>a, vector<int>b){return a[0]<b[0];}
vector<vector<int>>ans;
int main(){
    cin >> v >> e;
    for(int i=1;i<=e;i++){
        int a, b; cin >> a >> b;
        edge[a].push_back(b);
        redge[b].push_back(a);
    }
    for(int i=1;i<=v;i++){
        if(!Visit[i])dfs(i);
    }
    fill(&Visit[0],&Visit[10001],0);
    while(!order.empty()){
        res.clear();
        if(Visit[order.top()]){
            order.pop(); continue;
        }
        rdfs(order.top()); order.pop();
        vector<int>temp;
        for(auto it=res.begin();it!=res.end();it++){
            temp.push_back(*it);
        }
        temp.push_back(-1);
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end(),cmp);
    cout << ans.size() << "\n";
    for(auto v:ans){
        for(int num:v){
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}
