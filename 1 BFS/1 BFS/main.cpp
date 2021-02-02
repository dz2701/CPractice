//
//  main.cpp
//  1 BFS
//
//  Created by Shin Lee on 12/29/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e2+1;
char grid[MAX][MAX];int n, m;
pair<int,int>gravity[MAX][MAX][5];
int visit[MAX][MAX];
struct state{int x, y, val;};
deque<state>dq;
long long val[MAX][MAX];
pair<int,int>dfs(int x, int y, int fac){
    if(x<=0 or y<=0 or x>n or y>m or grid[x][y]=='#'){
        printf("return %d,%d\n",x,y);
        return make_pair(x,y);
    }
    return gravity[x][y][fac+1] = dfs(x+fac, y, fac); //-1 : 0, 1: 2
}

int main(){
    cin >> n >> m;
    pair<int,int>dest;
    for(int i=1;i<=n;i++){
        string temp; cin >> temp;
        for(int j=1;j<=m;j++){
            grid[i][j] = temp[j-1];
            if(grid[i][j]=='C')dq.push_front({i,j,0});
            else if(grid[i][j]=='D')dest = {i,j};
        }
    }
    for(int i=1;i<=m;i++){
        //looking at line i
        int x = n, y = i;
        while((x>=1)){
            //upwards, diff gravity
            printf("x=%d\n",x);
            auto res = dfs(x,y,-1);
            x = res.first -1 ;
        }
        //downwards, original gravity
        x = 1;
        while(x<=n){
            printf("x=%d\n",x);
            auto res = dfs(x,y,1);
            x = res.first + 1;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d %d  ",gravity[i][j][0].first, gravity[i][j][0].second);
        }
        printf("\n");
    }
    printf("\n\n\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d %d  ",gravity[i][j][2].first, gravity[i][j][2].second);
        }
        printf("\n");
    }
    int ans = -1;
    fill(&val[0][0], &val[MAX-1][MAX], INFINITY);
    while(!dq.empty()){
        auto now = dq.front(); dq.pop_front();
        printf("now = %d %d %d\n",now.x,now.y,now.val);
        if(visit[now.x][now.y])continue;
        else if(grid[now.x][now.y] == 'D'){
            ans = now.val;
            break;
        }
        visit[now.x][now.y] = 1;
        // you can move left and right, but moving on the 'gravity' makes a change --> push to back
        if(now.x+1<=n and grid[now.x+1][now.y]!='#' and val[now.x][now.y]>now.val){
            auto change = gravity[now.x+1][now.y][now.val%2==0? 2 : 1];
            if(change.first<=n and change.first>=1 and change.second>=1 and change.second<=n){
                dq.push_front({change.first,change.second,now.val});
            }
        }
        if(now.x-1>=1 and grid[now.x-1][now.y]!='#' ){
            auto change = gravity[now.x-1][now.y][now.val%2==0? 2 : 1];
            if(change.first<=n and change.first>=1 and change.second>=1 and change.second<=n){
                dq.push_front({change.first,change.second,now.val});
            }
        }
        //now we can flip the thing
        if(now.val%2==0){
            //normal gravity, so if changed use diff gravity --> [0]
            pair<int,int> change = gravity[now.x][now.y][0];
            dq.push_back({change.first, change.second, now.val+1});
        }else{
            pair<int,int>change = gravity[now.x][now.y][2];
            dq.push_back({change.first,change.second,now.val+1});
        }
    }
    cout << ans;
    return 0;
}
