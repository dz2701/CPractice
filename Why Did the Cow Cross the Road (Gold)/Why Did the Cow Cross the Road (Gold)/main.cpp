//
//  main.cpp
//  Why Did the Cow Cross the Road (Gold)
//
//  Created by dz2701 on 11/11/20.
//

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, t;
int arr[101][101];
int val[101][101];
int dx[4] = {0,1,0,-1}; int dy[4] = {1,0,-1,0};
struct state{
    int x, y;
    int cnt, val;
};
struct cmp{bool operator() (state a, state b){return a.val<b.val;}};
bool coorcheck(int x, int y){
    if(x>0 and y>0 and x<=n and y<=n)return true;
    else return false;
}
priority_queue<state,vector<state>,cmp>pq;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    pq.push({1,1,0,0});
    fill(&val[0][0], &val[100][101], INF); val[1][1] = 0;
    while(!pq.empty()){
        state now = pq.top(); pq.pop();
        for(int i=0;i<4;i++){
            int nx = now.x+dx[i]; int ny = now.y+dy[i];
            if(coorcheck(nx,ny)){
                int nval = t + now.val; if(now.cnt==2)nval+=arr[nx][ny];
                if(val[nx][ny]>nval){
                    val[nx][ny] = nval;
                    if(now.cnt==2)pq.push({nx,ny,0,nval});
                    else pq.push({nx,ny,now.cnt+1,nval});
                }
            }
        }
    }
    cout << val[n][n];
    return 0;
}
