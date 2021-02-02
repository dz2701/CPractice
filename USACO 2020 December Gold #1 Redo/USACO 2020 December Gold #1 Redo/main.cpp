//
//  main.cpp
//  USACO 2020 December Gold #1 Redo
//
//  Created by Shin Lee on 12/28/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3+5;
const int INF = 1e9;
int dist[MAX][MAX];
char grid[MAX][MAX];
int ans[MAX][MAX];
vector<pair<int,int>>start;
int n, d;
struct state{int x,y,val;};struct cmp{bool operator () (state a, state b){return a.val>b.val;}};
priority_queue<state,vector<state>,cmp>pq;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> d;
    for(int i=1;i<=n;i++){
        string temp; cin >> temp;
        for(int j=0;j<n;j++)grid[i][j+1] = temp[j];
    }
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dist[i][j] = INF;
    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j]=='#'){
                dist[i][j] = 0;
                for(int p=0;p<4;p++){
                    int x = i+dx[p], y = j+dy[p];
                    if(x<=1 or y<=1 or x>=n or y>=n or grid[x][y]=='#')continue;
                    pq.push({x,y,1});
                }
            }else if(grid[i][j]=='S')start.push_back({i,j});
        }
    }
    
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        if(dist[now.x][now.y]!=INF)continue;
        dist[now.x][now.y] = now.val;
        for(int i=0;i<4;i++){
            int x = now.x +dx[i]; int y = now.y + dy[i];
            if(dist[x][y]==INF)pq.push({x,y,now.val+1});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d", dist[i][j]);
        }
        printf("\n");
    }
    //now perform BFS from starting points. if the size of the model is bigger than the distance of the appropriate cell, it won't be able to stay there.
    //일단은 비효율적으로 구현해 보자.
    for(pair<int,int>sp : start){
        pq.push({sp.first,sp.second,0}); //value is used as time
    }
    
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        if(dist[now.x][now.y]>=1+(now.val/(d+1))){ //if you can fit this size
            ans[now.x][now.y] = max(ans[now.x][now.y], 1+(now.val/(d+1)));
        }
       
        if(now.val%(d+1)!=0){ //not a time to expand!
            for(int i=0;i<4;i++){
                int x= now.x+dx[i]; int y = now.y+dy[i];
                if(x<=1 or y<=1 or x>=n or y>=n or grid[x][y]=='#')continue;
                pq.push({x,y,now.val+1});
            }
        }else if(dist[now.x][now.y]>=1+(now.val/(d+1))){
            pq.push({now.x,now.y,now.val+1});
        }
    }
    printf("\n\n\n\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
