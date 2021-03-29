//
//  main.cpp
//  환상의 듀엣
//
//  Created by Shin Lee on 2/17/21.
//

#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX = 2001;
const int EMPTY = 1e9;
int arr[MAX];
long long dp[MAX][MAX];
/*long long Solve(int i, int j){
    if(i==j)return 1e9;
    if(dp[i][j]!=EMPTY)return dp[i][j];
    if(i>j){
        long long ret = 1e9;
        for(int k=0;k<i;k++){
            ret = min(ret, Solve(k,j));
        }
    }
}*/
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    fill(&dp[0][0],&dp[MAX-1][MAX],EMPTY);
    //initialize:
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //situation: I put the last A in position i, and put the last B in position j.
            if(i==j)continue;
            int pos = max(i,j)+1; //the position of next choice, since one of them has to be the latest choice
            dp[pos][j] = min(dp[pos][j],dp[i][j] + abs(arr[i]-arr[pos])); //I want to put A in the next position.
            dp[i][pos] = min(dp[i][pos], dp[i][j] + abs(arr[j]-arr[pos])); //I want to put B in the next position.
        }
    }*/
    dp[1][2] = 0; dp[2][1] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(i>j){
                for(int k=1;k<i;k++){
                    dp[i][j]=min(dp[i][j],dp[k][j]+abs(arr[k]-arr[i]));
                }
            }else{
                for(int k=1;k<j;k++){
                    dp[i][j]=min(dp[i][j], dp[i][k]+abs(arr[k]-arr[j]));
                }
            }
        }
    }
    long long ans = 1e9;
    for(int i=1;i<=n;i++){
        ans = min(ans, min(dp[i][n],dp[n][i]));
    }
    cout << ans;
}
