//
//  main.cpp
//  1135 뉴스 전하기
//
//  Created by Shin Lee on 12/8/20.
//

#include <bits/stdc++.h>
using namespace std;
//dp[i] = root i tree call min time
//then dp[i] = for(adj: con[i]): vector<pair<int,int>>v, p; v.push_back(dp[adj]); sort(v.begin(),v.end()); for(int c=0;c<con[i].size()//get this var first;c++)for(int i=c;i<v.size()+c;i++)p.push_back(v[i-c]+i); sort(p.begin(),p.end()); m = max(m,p.front());
struct node{int node, value;}; struct cmp{bool operator () (node a, node b){return a.value>b.value;}};
vector<int>v;
queue<int>q;
int n;
int dp[51], sz[51];
vector<int>adj[51];
vector<int>radj[51];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        if(temp<0)continue;
        adj[temp].push_back(i);
        radj[i].push_back(temp);
        sz[temp]++;
    }
    for(int i=0;i<n;i++){
        if(!sz[i])q.push(i);
    }
    
    while(!q.empty()){
        int now = q.front(); q.pop();
       // printf("now = %d\n",now);
        for(auto con: radj[now]){
            sz[con]--;
            if(!sz[con])q.push(con);
        }
        vector<int>v;
        for(auto con: adj[now]){
            v.push_back(dp[con]);
        }
        if(v.empty()){
            continue;
        } //no action needed, bc takes no time to do size of 0
        sort(v.begin(),v.end(),greater<int>());
        int mm = -1e9;
        for(int i=0;i<v.size();i++){
            //printf("looking at value %d...\n",v[i]+i+1);
            mm = max(mm, v[i]+i+1);
        }
        dp[now] = mm;
        //printf("dp[%d]=%d\n",now,dp[now]);
    }

    cout << dp[0];
}

