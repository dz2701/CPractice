//
//  main.cpp
//  Dance Mooves Silver
//
//  Created by Shin Lee on 2/26/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int n, k;
int arr[MAX];
set<int>s[MAX];
int visit[MAX];
int endpoint[MAX];
vector<int>cycle;
set<int>check;
void dfs(int node){
    if(visit[node])return;
    visit[node]=1;
    cycle.push_back(node);
    for(int visited:s[node]){
        check.insert(visited);
    }
    dfs(endpoint[node]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        arr[i]=i;
        s[i].insert(i);
    }
    for(int i=1;i<=k;i++){
        int a, b;
        cin >> a >> b;
        //swap those
        swap(arr[a],arr[b]);
        s[arr[a]].insert(a);
        s[arr[b]].insert(b);
    }
    for(int i=1;i<=n;i++){
        endpoint[arr[i]]=i;
    }
    int ans[MAX];
    for(int i=1;i<=n;i++){
        if(visit[i])continue;
        cycle.clear(); check.clear();
        dfs(i);
        for(int node : cycle){
            ans[node] = check.size();
        }
    }
    
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
}
