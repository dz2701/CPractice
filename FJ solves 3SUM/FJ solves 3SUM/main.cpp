//
//  main.cpp
//  FJ solves 3SUM
//
//  Created by Shin Lee on 12/14/20.
//

#include <bits/stdc++.h>
using namespace std;
int n, q;
const int MAX = 5005;
long long dp[MAX][MAX];
long long arr[MAX];
long long sum[MAX];
int main(){
    cin >> n >> q;
    long long temp = 0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        temp+=arr[i];
        sum[i] = temp;
    }
    for(int i=n;i>=1;i--){
        for(int j=0;j<=n;j++){
            dp[i][j] = dp[i][j-1] + dp[i+1][j];
            if(sum[j]-sum[i-1]==0)dp[i][j]++;
            if(sum[j]-sum[j-1-1]==0)dp[i][j]++;
            if(sum[i+1]-sum[i-1]==0)dp[i][j]++;
            printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
        }
    }
    //recursive? order change
    
    for(int i=1;i<=q;i++){
        int a, b; cin >> a >> b;
        printf("%lld\n",dp[a][b]);
    }
}
