//
//  main.cpp
//  Count the Cows
//
//  Created by Shin Lee on 2/28/21.
//  brute force first

#include <bits/stdc++.h>
using namespace std;

int q;
map<pair<long long,long long>,int>dp;
bool parity_check(long long x, long long y){
    if((x%3==0 or x%3==2) and (y%3==0 or y%3==2))return true;
    if(x%3==1 and y%3==1)return true;
    return false;
}
long long Solve(long long x, long long y){
    if(dp[{x,y}]!=0)return dp[{x,y}];
    if(x==y)return dp[{x,y}]=1;
    else return dp[{x,y}] = parity_check(x,y)? Solve(x/3,y/3)==1? 1 : -1 : -1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    dp.clear();
    for(int i=0;i<=15;i++){
        for(int j=0;j<=15;j++){
            cout << (Solve(i,j)==1?1:0) << " ";
        }
        cout << "\n";
    }
    return 0;
}
