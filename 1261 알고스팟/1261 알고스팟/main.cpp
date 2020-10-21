//
//  main.cpp
//  1261 알고스팟
//
//  Created by dz2701 on 10/2/20.
//

#include <bits/stdc++.h>
using namespace std;
int n, m; int dx[4]={0,1,0,-1}, dy[4] = {1,0,-1,0};
int grid[101][101]; int arr[101][101]; int visit[101][101];
bool coorcheck(int x, int y){return x>0 and y>0 and x<=n and y<=m;}
struct state{pair<int,int>loc; int cost;};
bool cmp(state a, state b){return a.cost<b.cost;}
priority_queue<state,vector<state>,function<bool(state,state)>>pq(cmp);
int to_integer(char a){return a-'0';}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        string s; cin >> s;
        for(int j=1;j<=m;j++){
            grid[i][j] = to_integer(s[j-1]);
        }
    }
    pq.push({{0,0},0});
    fill(&arr[0][0],&arr[101][101],1e9); arr[0][0] = 0;
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        for(int i=0;i<4;i++){
            int x = now.loc.first+dx[i]; int y=now.loc.second+dy[i];
            if(coorcheck(x,y)){
                if(arr[x][y]>now.cost + grid[x][y]){
                    pq.push({{x,y},now.cost+grid[x][y]});
                    arr[x][y] = now.cost + grid[x][y];
                }
            }
        }
    }
    cout << arr[n][m];
    return 0;
}
