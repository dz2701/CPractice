//
//  main.cpp
//  1012
//
//  Created by dz2701 on 9/17/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
struct node{int x, y, t;}; bool cmp(node a, node b){return a.t>b.t;} priority_queue<node,vector<node>,function<bool(node,node)>>pq(cmp);
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int grid[51][51]; int cnt[51][51];
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    fill(&grid[0][0], &grid[51][51],0);
    fill(&cnt[0][0], &cnt[51][51],0);
    for(int i=1;i<=c;i++){
        int t1, t2; cin >> t1 >> t2; grid[t1+1][t2+1] = 1;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(grid[i][j]==1){
                for(int k=0;k<4;k++){
                    cnt[i+dx[k]][j+dy[k]]++;
                }
            }
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(grid[i][j]==1)pq.push({i,j,cnt[i][j]});
        }
    }
    int ans = 0;
    while(pq.empty()){
        node front = pq.top();
        pq.pop();
        if(cnt[front.x][front.y]==0)continue;
        ans++;
        cnt[front.x][front.y]=0;
        for(int i=0;i<4;i++){
            cnt[front.x+dx[i]][front.y+dy[i]]=0;
        }
    }
    
    cout << ans;
    
}
