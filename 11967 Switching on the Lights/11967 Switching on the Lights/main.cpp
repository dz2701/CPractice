//
//  main.cpp
//  Switching on the Lights
//
//  Created by Shin Lee on 23/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> rule[105][105];
int room[105][105];
int visit[105][105];
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
int n, m;

void dfs(int x,int y){
    if(visit[x][y]==1)return;
    visit[x][y]=1;
    for(int i=0;i<rule[x][y].size();i++){
        room[rule[x][y][i].first][rule[x][y][i].second]=1;
        for(int j=0;j<4;j++){
            if(visit[rule[x][y][i].first+dx[j]][rule[x][y][i].second+dy[j]]==1){
                dfs(rule[x][y][i].first,rule[x][y][i].second);
            }
        }
    }
    for(int i=0;i<4;i++){
        if(room[x+dx[i]][y+dy[i]]==1)dfs(x+dx[i],y+dy[i]);
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c,d;
        cin >> a >> b >> c >> d;
        rule[a][b].push_back({c,d});
    }
    room[1][1]=1;
    
    dfs(1,1);
    
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(room[i][j]==1)ans++;
        }
    }
    cout << ans;
    
    return 0;
    
}
