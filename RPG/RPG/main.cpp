//
//  main.cpp
//  RPG
//
//  Created by Shin Lee on 3/4/21.
//

#include <bits/stdc++.h>
using namespace std;

int n;
struct quest{int STR, INT, PNT;};
quest q[51];
bool cmp(quest a, quest b){return a.STR+a.INT!=b.STR+b.INT?a.STR+a.INT<b.STR+b.INT:a.STR<b.STR;};

int dp[51][1001];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> q[i].STR >> q[i].INT >> q[i].PNT;
    }
    sort(q+1,q+n,cmp);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=25;j++){
            dp[i][j] = dp[i-1][j];
            if(dp[i-1][j-q[i].STR]+2-i>=q[i].INT and i>=q[i].STR){
                dp[i][j] = max(dp[i][j],dp[i-1][j-q[i].STR]+q[i].PNT);
            }
            printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
        }
        
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j]){
                ans = max(ans,i);
                break;
            }
        }
    }
    cout << ans;
}
