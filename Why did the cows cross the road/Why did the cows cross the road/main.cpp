//
//  main.cpp
//  Why did the cows cross the road
//
//  Created by Shin Lee on 3/1/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, t;
int cost[101][101], arr[101][101];

struct loc{int x, y;};
struct state{loc node; int val, cnt;};
struct cmp{bool operator () (state a, state b){return a.val<b.val;}};
priority_queue<state,vector<state>,cmp>pq;

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int main(){
    cin >> n >> t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> cost[i][j];
        }
    }
    fill(&arr[0][0],&arr[100][101],1e9);
    pq.push({{1,1},0,-1});
    arr[1][1] = 0;
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        for(int i=0;i<4;i++){
            int nx = now.node.x+dx[i], ny=now.node.y+dy[i];
            if(nx>0 and ny>0 and nx<=n and ny<=n){
                if(arr[nx][ny]!=now.val+t+(now.cnt==2?cost[now.node.x][now.node.y]:0)){
                    arr[nx][ny] = now.val+t+(now.cnt==2?cost[now.node.x][now.node.y]:0);
                    pq.push({{nx,ny},arr[nx][ny],(now.cnt+1)%3});
                }
            }
        }
    }
    cout << arr[n][n];
    return 0;
}
