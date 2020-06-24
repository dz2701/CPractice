//
//  main.cpp
//  10273 Connected Caves
//
//  Created by dz2701 on 6/16/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int T, N, E;
int value[MAX], in[MAX], pv[MAX], dp[MAX];
vector<pair<int,int>>p[MAX];
int main(){
    cin >> T;
    while(T--){
        memset(in,0,sizeof(in));
        memset(p,0,sizeof(p));
        cin >> N >> E;
        for(int i=1;i<=N;i++)cin >> value[i];
        for(int i=0;i<E;i++){
            int a, b, c;
            cin >> a >> b >> c;
            p[a].push_back(make_pair(b,c));
            in[b]++;
        }
        queue<int>q;
        q.push(1);
        fill(dp+1,dp+N+1,-1e9);
        dp[1] = value[1];
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(auto c:p[cur]){
                int next = c.first;
                int cost = c.second;
                in[next]--;
                if(dp[next]<dp[cur]+value[next]-cost){
                    dp[next] = dp[cur]+value[next]-cost;
                    pv[next] = cur;
                }
                
                if(in[next]==0){
                    q.push(next);
                }
                
            }
        }
        int maxind = 0;
        for(int i=1;i<=N;i++){
            //printf("dp[%d]=%d\n",i,dp[i]);
            if(dp[maxind]<dp[i])maxind = i;
        }
        //maxind has the array index of maximum
        
        vector<int>path;
        for(int i=maxind; i!=0; i=pv[i]){
            path.push_back(i);
        }
        reverse(path.begin(),path.end());
        
        printf("%d %d\n",dp[maxind],path.size());
        for(int i : path)printf("%d ",i);
        printf("\n");
        path.clear();
        
    }
    
    
}
