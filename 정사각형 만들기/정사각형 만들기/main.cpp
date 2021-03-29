//
//  main.cpp
//  정사각형 만들기
//
//  Created by Shin Lee on 3/5/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[10001][101];
int Solve(int a, int b){
    if(a<b)swap(a,b);
    if(dp[a][b]!=-1)return dp[a][b];
    if(b==0){
        return dp[a][b] = 0;
    }
    if(a==b){
        return dp[a][b]=1;
    }
    int ret = 1e9;
    for(int i=1;i<=min(a,b);i++){
        ret = min(ret, 1+min(Solve(b-i,a)+Solve(i,a-i),Solve(a-i,b)+Solve(b-i,i)));
    }
    dp[a][b] = ret;
    return ret;
}
int main(){
    int n, m;cin >> n >> m;
    fill(&dp[0][0],&dp[10000][101],-1);
    cout << Solve(n,m);
}
