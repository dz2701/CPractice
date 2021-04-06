//
//  main.cpp
//  USACO 2020 December Gold #1
//
//  Created by Shin Lee on 12/20/20.
//

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int MAX = 1e3+1;
int n, d;
char grid[MAX][MAX];
vector<pii>start_position;
int possible[MAX][MAX];
int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> d;
    for(int i=1;i<=n;i++){
        string temp; cin >> temp;
        for(int j=1;j<=n;j++){
            grid[i][j] = temp[j-1];
            if(grid[i][j]=='S')start_position.push_back({i,j});
        }
    }
    queue<pair<pii,pii>>q;
    for(auto start : start_position){
        q.push({{start.first,start.second},{-1,0}});
    }
    int ans = 0;
    while(!q.empty()){
        auto now = q.front(); q.pop();
        if(now.first.first+now.second.second>=n or now.first.second+now.second.second>=n or now.first.first-now.second.second<=1 or now.first.second-now.second.second<=1)continue;
        bool is = false;
        for(int i=0;i<=now.second.second;i++){
            for(int j=now.second.second-i;j>=-now.second.second+i;j--){
                if(grid[now.first.first+i][now.first.second+j]=='#' or grid[now.first.first-i][now.first.second+j]=='#'){
                    is = true;
                }
            }
        }
        if(is)continue;
        for(int i=0;i<=now.second.second;i++){
            for(int j=now.second.second-i;j>=-now.second.second+i;j--){
                possible[now.first.first+i][now.first.second+j] = 1;
                possible[now.first.first-i][now.first.second+j]=1;
            }
        }
        //all four sides moving
        if(now.second.first%(d+1)!=0)for(int i=0;i<4;i++)q.push({{now.first.first+dx[i],now.first.second+dy[i]},{now.second.first+1,now.second.second}});
            //expanding
        else{
            q.push({{now.first.first,now.first.second},{now.second.first+1,now.second.second+1}});
                
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=possible[i][j];
        }
    }
    cout << ans;
}
