//
//  main.cpp
//  Labudovi
//
//  Created by Shin Lee on 5/4/20.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX 1505
#define INF 1e9
using namespace std;

int R, C; char grid[MAX][MAX]; queue<pair<int,int>>q; pair<int,int>start[2]; int num[MAX][MAX]; int visit[MAX][MAX];
int gmin(int x, int y){
    int ans = 1e9;
    if(x>1)ans = min(ans,num[x-1][y]);
    if(y>1)ans = min(ans,num[x][y-1]);
    if(x<R)ans = min(ans,num[x+1][y]);
    if(y<C)ans = min(ans,num[x][y+1]);
    
    return ans;
}
int main(){
    cin >> R >> C; int ind = 0;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin >> grid[i][j];
            if(grid[i][j]=='L')start[ind++] = {i,j};
        }
    }
    queue<pair<int,int>>qq;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(grid[i][j]=='.' or grid[i][j]=='L'){
                num[i][j]=1;
                qq.push({i,j});
            }
        }
    }
    int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
    while(!qq.empty()){
        auto fr = qq.front();
        qq.pop();
        
        for(int i=0;i<4;i++){
            int x = fr.first+dx[i]; int y =fr.second+dy[i];
            if(x>0 and y>0 and x<=R and y<=C and num[x][y]==0){
                qq.push({x,y});
                num[x][y]= num[fr.first][fr.second]+1;
            }
        }
    }

    
    int hi = 1500, lo = 0;
    while(hi!=lo){
        int mid = (hi+lo)/2;
        memset(visit,0,sizeof(visit));
        q.push(start[0]);
        visit[start[0].first][start[0].second]=1;
        bool c = false;
        while(!q.empty()){
            auto now = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int x = now.first + dx[i]; int y = now.second+dy[i];
                if(x>0 and y>0 and x<=R and y<=C and visit[x][y]==0 and num[x][y]<=mid){
                    q.push({x,y});
                    visit[x][y]=1;
                    if(x == start[1].first and y==start[1].second){
                        c = true;
                        break;
                    }
                }
            }
            
        }
        if(c){
                       hi = mid;
                   }else lo = mid+1;
    }
    
    cout << lo-1;
    
    return 0;
}
