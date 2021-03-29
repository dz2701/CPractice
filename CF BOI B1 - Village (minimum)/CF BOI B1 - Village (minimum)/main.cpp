//
//  main.cpp
//  CF BOI B1 - Village (minimum)
//
//  Created by Shin Lee on 2/18/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int n;
vector<int>adj[MAX];
int arr[MAX], cnt[MAX], visit[MAX];
queue<int>q;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int a, b; cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    bool c = true;
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1){
            //has only one --> parent, so is leaf
            q.push(i);
        }else if(c){
            cnt[i] = adj[i].size()+1;
        }
        else cnt[i] = adj[i].size();
        arr[i] = i;
    }
    
    int ans = 0;
    
    while(!q.empty()){
        int leaf_node = q.front();
        visit[leaf_node] = 1;
        //update leaf status
        for(int con : adj[leaf_node]){
            cnt[con]--;
            if(cnt[con]==1)q.push(con);
            
        }
        
    }
}
