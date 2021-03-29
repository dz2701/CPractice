//
//  main.cpp
//  Search Engine
//
//  Created by Shin Lee on 3/11/21.
//

#include <bits/stdc++.h>
using namespace std;
int n;
map<string,vector<string>>edge,redge;
map<string,int>Visit;
stack<string>order;
void dfs(string cur){
    if(Visit[cur])return;
    Visit[cur]=1;
    for(string con:edge[cur]){
        dfs(con);
    }
    order.push(cur);
}
map<string,int>check;
vector<string>v;
void rdfs(string cur){
    if(Visit[cur])return;
    Visit[cur]=1;
    for(string con:redge[cur]){
        rdfs(con);
    }
    check[cur]++;
    v.push_back(cur);
}
map<string,int>cnt;
map<pair<string,string>,int>do_not;
int main(){
    cin >> n;
    vector<string>nodes;
    map<string,int>check;
    for(int i=1;i<=n;i++){
        string dest; int m; cin >> dest >> m;
        if(!check[dest])nodes.push_back(dest);
        check[dest]++;
        for(int i=1;i<=m;i++){
            string temp; cin >> temp;
            edge[temp].push_back(dest);
            redge[dest].push_back(temp);
            cnt[dest]++;
            if(!check[temp])nodes.push_back(temp);
            check[temp]++;
        }
    }
    string want; cin >> want; //want to know want
    for(string i:nodes){
        if(!Visit[i]){
            dfs(i);
        }
    }
    Visit.clear();
    queue<string>q; //used for top sort
    while(!order.empty()){
        if(Visit[order.top()]){
            order.pop(); continue;
        }
        v.clear(); check.clear();
        rdfs(order.top()); order.pop();
        for(string node:v){
            for(auto con : redge[node]){
                if(check[con]){
                    do_not[{con,node}]=1;
                    cnt[node]--;
                }
            }
        }
    }
    for(string nn : nodes)if(cnt[nn]==0)q.push(nn);
    //top.sort based on scc
    map<string,long long>val; Visit.clear();
    for(string nn:nodes)val[nn]=1;
    while(!q.empty()){
        string now = q.front(); q.pop();
        Visit[now]=1;
        for(string con: edge[now]){
            if(!do_not[{now,con}] and !Visit[con]){
                cnt[con]--; val[con]+=val[now];
                if(cnt[con]==0)q.push(con);
            }
        }
    }
    cout << val[want];
}
