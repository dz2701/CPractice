//
//  main.cpp
//  Team Building
//
//  Created by Shin Lee on 2/15/21.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int FJ[1001], FP[1001];
set<int>s;
long long dp[1001][1001]; //~i까지 j개 이기게 고르는 방법의 합
const int FAC = 1e9+9;
int main(){
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)cin >> FJ[i];
    for(int i=1;i<=m;i++){
        cin >> FP[i];
    }
    sort(FP+1,FP+m);
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            int cnt = upper_bound(FP+1,FP+m,FJ[i]-1) - (FP+1);
            dp[i][j] = dp[i-1][j-1]*(cnt-j+1) + dp[i-1][j]%FAC;
            printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
        }
    }
    cout << dp[n][k];
}
