//
//  main.cpp
//  14451 Cow Navigation
//
//  Created by dz2701 on 5/06/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX 25
using namespace std;


int n; int visit[MAX][MAX][5][MAX][MAX][5];
char grid[MAX][MAX];
struct coor{
    int x1, y1, dir1, x2, y2, dir2;
};
pair<int,int> moveforward(int x, int y, int dir){
    pair<int,int>p[5] = {{x,y},{x,y+1},{x,y-1},{x-1,y},{x+1,y}};
    if(x==1 and y==n)return p[0];
    if(dir==1)return y<n and grid[x][y+1]!='H'? p[1] : p[0];
    if(dir==2)return y>1 and grid[x][y-1]!='H'? p[2] : p[0];
    if(dir==3)return x>1 and grid[x-1][y]!='H'? p[3] : p[0];
    if(dir==4)return x<n and grid[x+1][y]!='H'? p[4] : p[0];
    return {NULL,NULL};
}
int turnleft(int dir){
    if(dir==1)return 3;
    if(dir==2)return 4;
    if(dir==3)return 2;
    if(dir==4)return 1;
    
    return NULL;
}
int turnright(int dir){
    if(dir==1)return 4;
    if(dir==2)return 3;
    if(dir==3)return 1;
    if(dir==4)return 2;
    return NULL;
}
int main(){
    //freopen("cownav.in","r",stdin);
    //freopen("cownav.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> grid[i][j];
        }
    }
    //1 is right, 2 is left, 3 is up, 4 is down
    queue<coor>q;
    q.push({n,1,1,n,1,3});
    visit[n][1][1][n][1][3]=1;
    while(!q.empty()){
        coor front = q.front();
        q.pop();
        
        //move forward
        pair<int,int> for1 = moveforward(front.x1,front.y1,front.dir1);
        pair<int,int> for2 = moveforward(front.x2, front.y2, front.dir2);
        
        if(visit[for1.first][for1.second][front.dir1][for2.first][for2.second][front.dir2]==0){
            visit[for1.first][for1.second][front.dir1][for2.first][for2.second][front.dir2] = visit[front.x1][front.y1][front.dir1][front.x2][front.y2][front.dir2]+1;
            q.push({for1.first,for1.second,front.dir1,for2.first,for2.second,front.dir2});
            
        }
        //turn left
        if(visit[front.x1][front.y1][turnleft(front.dir1)][front.x2][front.y2][turnleft(front.dir2)]==0){
            visit[front.x1][front.y1][turnleft(front.dir1)][front.x2][front.y2][turnleft(front.dir2)]= visit[front.x1][front.y1][front.dir1][front.x2][front.y2][front.dir2]+1;
            q.push({front.x1,front.y1,turnleft(front.dir1),front.x2,front.y2,turnleft(front.dir2)});
        }
        
        //turn right
        if(visit[front.x1][front.y1][turnright(front.dir1)][front.x2][front.y2][turnright(front.dir2)]==0){
            visit[front.x1][front.y1][turnright(front.dir1)][front.x2][front.y2][turnright(front.dir2)]= visit[front.x1][front.y1][front.dir1][front.x2][front.y2][front.dir2]+1;
            q.push({front.x1,front.y1, turnright(front.dir1),front.x2,front.y2,turnright(front.dir2)});
        }
        
            
    }
    
    int ans = 1e9;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(visit[1][n][j][1][n][i]!=0)ans = min(ans,visit[1][n][j][1][n][i]);
        }
    }
    
    cout << ans-1;
    
    
    return 0;
}
