//
//  main.cpp
//  Cow Beauty Pageant
//
//  Created by Shin Lee on 21/04/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX 55
using namespace std;
char grid[MAX][MAX]; int rgrid[MAX][MAX];
int visit[MAX][MAX], rvisit[MAX][MAX];
int n, m;pair<int,int>X;
queue<pair<int, int>>q;
void find(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j]=='X'){
                X = {i,j};
                return;
            }
        }
    }
}
int dx[4]={1,0,-1,0}, dy[4] = {0,1,0,-1};
void dfs(int x, int y){
    visit[x][y]=1;
    for(int i=0;i<4;i++){
        int a = x + dx[i];
        int b = y + dy[i];
        if(visit[a][b]==0 and grid[a][b]=='X'){
            dfs(a,b);
        }
    }
    
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> grid[i][j];
        }
    }
    
    find();
    dfs(X.first,X.second);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]=='X'){
                if(visit[i][j]==1){
                    rgrid[i][j]=1;
                    q.push({i,j});
                    rvisit[i][j]=1;
                }
                else rgrid[i][j]=2;
            }
        }
    }
    
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int x = front.first + dx[i];
            int y = front.second + dy[i];
            if(x>0 and y>0 and x<=n and y<=m and rvisit[x][y]==0){
                rvisit[x][y]=rvisit[front.first][front.second]+1;
                q.push({x,y});
                if(rgrid[x][y]==2){
                    cout << rvisit[x][y] -2;
                    return 0;
                }
            }
            
            
        }
    }
    
    
    return 0;
}
