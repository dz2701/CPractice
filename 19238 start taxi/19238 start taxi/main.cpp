//
//  main.cpp
//  19238 start taxi
//
//  Created by dz2701 on 6/29/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 25;
int n, m, oil;
int grid[MAX][MAX];
struct guest{pair<int,int>start;pair<int,int>end;};
guest guests[MAX];
bool cmp(guest a, guest b){return a.start.first==b.start.first?a.start.second<b.start.second:a.start.first<b.start.first;};
int complete;
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
pair<int,pair<int,int>>dfs(int a, int b, int m){
    priority_queue<int,pair<int,int>>pq;
    if(grid[a][b]==2){
        pq.push(make_pair(m,make_pair(a,b)));
    }
    for(int i=0;i<4;i++){
        dfs(a+dx[i],b+dy[i],m-1);
    }
    return pq;
}
int main(){
    cin >> n >> m >> oil;
    complete = m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> grid[i][j];
        }
    }
    int start, end;
    cin >> start >> end;
    for(int i=1;i<=m;i++){
        cin >> guests[i].start.first >> guests[i].start.second >> guests[i].end.first >> guests[i].end.second;
        grid[guests[i].start.first][guests[i].start.second]=2;
        grid[guests[i].end.first][guests[i].end.second]=3;
    }
    sort(guests+1,guests+m+1,cmp);
    for(int i=1;i<=m;i++){
        printf("%d %d %d %d\n",guests[i].start.first,guests[i].start.second,guests[i].end.first,guests[i].end.second);
    }
    //must do dfs. since the cars are sorted by their 'rows and columns', the first one that comes in will be the one that the taxi will choose.
    
    
    
}
