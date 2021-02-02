//
//  main.cpp
//  물 채우기
//
//  Created by Shin Lee on 2/1/21.
//

#include <bits/stdc++.h>
using namespace std;
int w, h;
int grid[301][301];
struct state{int x, y, val;};
struct cmp{bool operator () (state a, state b){return a.val<b.val;}};
priority_queue<state,vector<state>,cmp>pq;
int arr[301][301], visit[301][301];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int main(){
    cin >> w >> h;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> grid[i][j];
            if(i==h or j==w){
                pq.push({i,j,grid[i][j]});
                visit[i][j]=1;
            }
        }
    }
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        visit[now.x][now.y] = 1;
        for(int i=0;i<4;i++){
            int nx = now.x+dx[i], ny = now.y+dy[i];
            if(nx>1 and ny>1 and nx<h and ny<w and grid[nx][ny]<=now.val){
                //flooding in!
                if(!visit[nx][ny])arr[nx][ny] = now.val;
                pq.push({nx,ny,arr[nx][ny]});
            }
            
        }
    }
    int ans =0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            ans+=arr[i][j] - grid[i][j];
        }
    }
    cout << ans;
}
