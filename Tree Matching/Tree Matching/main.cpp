//
//  main.cpp
//  Tree Matching
//
//  Created by Shin Lee on 2/18/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1;
int n;
int dp[MAX][2];
vector<int>adj[MAX];
queue<int>q;
int arr[MAX], visit[MAX];
int root = -1;
int main(){
    cin >> n;
    for(int i=1;i<=n-1;i++){
        int a, b; cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    //look queue first, and only calculate if they processed all of the children.
    bool c = false;
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1){
            q.push(i); //leaf node
            arr[i] = 1;
        }
        else if(!c){
            arr[i] = adj[i].size()+1; //configuring this as the root of the tree
            c = true;
            root = i;
        }else arr[i] = adj[i].size();
    }
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(visit[node])continue;
        visit[node]=1;
        for(int con : adj[node]){
            //update setting
            arr[con]--;
            if(arr[con]==1)q.push(con);
            //update value
            if(visit[con])dp[node][0]+= max(dp[con][0],dp[con][1]);
        }
        for(int con : adj[node]){
            if(visit[con])dp[node][1] = max(dp[node][1], dp[node][0]-max(dp[con][0],dp[con][1])+dp[con][0]+1);
        }
        //printf("dp[%d][0]=%d, dp[%d][1]=%d\n",node,dp[node][0],node,dp[node][1]);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, max(dp[i][0],dp[i][1]));
    }
    cout << ans;
}
