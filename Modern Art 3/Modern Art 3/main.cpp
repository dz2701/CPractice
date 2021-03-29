//
//  main.cpp
//  Modern Art 3
//
//  Created by Shin Lee on 2/28/21.
//

#include <bits/stdc++.h>
using namespace std;

int n, dp[301][301];
vector<int>arr;
int Solve(int a, int b){
    if(a>b)return 0;
    if(a==b)return 1;
    if(dp[a][b]!=-1)return dp[a][b];
    dp[a][b]=1e9;
    //no reuse
    dp[a][b] = min(dp[a][b],Solve(a+1,b)+1);
    //reuse
    for(int i=a;i<=b;i++){
        if(i!=a and arr[i]==arr[a]){
            dp[a][b] = min(dp[a][b],Solve(a+1,i-1)+Solve(i,b));
        }
    }
    return dp[a][b];
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int temp; cin >> temp; arr.push_back(temp);
    }
    fill(&dp[0][0],&dp[300][301],-1);
    cout << Solve(0,n-1);
}
