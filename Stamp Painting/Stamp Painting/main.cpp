//
//  main.cpp
//  Stamp Painting
//
//  Created by Shin Lee on 1/13/21.
//

#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int FAC = 1e9+7;
const int MAX = 1e5+5;
long long dp[MAX];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("spainting.in","r",stdin);
    //freopen("spainting.out","w",stdout);
    cin >> n >> m >> k;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1]*m;
        if(i-k>=0)dp[i]-=dp[i-k]*(m-1);
        dp[i]%=FAC;
    }
    for(int i=1;i<=n;i++){
        printf("dp[%d]=%d\n",i,dp[i]);
    }
    int temp = 1;
    for(int i=1;i<=n;i++){
        temp*=m;
        temp%=FAC;
    }
    
    cout << (temp - dp[n] + FAC) % FAC;
}
