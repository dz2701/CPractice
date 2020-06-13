//
//  main.cpp
//  SLIKAR
//
//  Created by Shin Lee on 21/04/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX 55
using namespace std;
long long r, c; char grid[MAX][MAX]; long long visit[MAX][MAX];
long long dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
struct loc{
    long long type;
    pair<long long,long long>location;
};

int main(){
    cin >> r >> c;
    loc initloc;
    pair<long long,long long>destination;
    initloc.type = 1;
    queue<loc>q;

    for(long long i=1;i<=r;i++){
        for(long long j=1;j<=c;j++){
            cin >> grid[i][j];
            if(grid[i][j]=='S'){
                initloc.location = {i,j};
            }else if(grid[i][j]=='*'){
                loc nowloc;
                nowloc.location = {i,j};
                nowloc.type = 2;
                q.push(nowloc);
                visit[nowloc.location.first][nowloc.location.second] = -1;
            }else if(grid[i][j]=='D')destination = {i,j};
        }
    }

    q.push(initloc);
    visit[initloc.location.first][initloc.location.second]=1;

    while(!q.empty()){
        auto now = q.front();
        q.pop();

        for(long long i=0;i<4;i++){
            long long x = now.location.first + dx[i];
            long long y = now.location.second + dy[i];
            if(x<1 or y<1 or x>r or y>c)continue;
            if(now.type ==1){
                if(grid[x][y]!='X' and visit[x][y]==0){
                    visit[x][y] = visit[now.location.first][now.location.second]+1;
                    loc nloc;
                    nloc.location = {x,y};
                    nloc.type = 1;
                    q.push(nloc);
                }
            }else{
                if(grid[x][y]!='X' and grid[x][y]!='D' and visit[x][y]==0){
                    visit[x][y] = -1;
                    loc nloc;
                    nloc.location = {x,y};
                    nloc.type = 2;
                    q.push(nloc);
                }
            }

        }
        
    }
    



    if(visit[destination.first][destination.second]!=0)cout << visit[destination.first][destination.second]-1;
    else cout << "KAKTUS";
    
    return 0;
}
