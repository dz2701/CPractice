//
//  main.cpp
//  내리막 길
//
//  Created by dz2701 on 9/2/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[501][501];
int dp[501][501];
int dx[4] = {0,1,0,-1}, dy[4]={1,0,-1,0};
bool rangecheck(int x, int y){return x<=N and x>=1 and y<=M and y>=1;}
int Solve(int x, int y){
    if(x==N and y==N)return 1;
    if(dp[x][y]!=0)return dp[x][y];
    int ret = 0;
    for(int i=0;i<4;i++){
        int xx = x+dx[i]; int yy = y+dy[i];
        if(!rangecheck(xx,yy))continue;
        if(arr[xx][yy] < arr[x][y]){
            ret += Solve(xx,yy);
        }
    }
    
    dp[x][y] = ret;
    return ret;
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> arr[i][j];
        }
    }
    cout <<  Solve(1,1);
    
}
