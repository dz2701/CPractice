//
//  main.cpp
//  10653 Marathon
//
//  Created by dz2701 on 9/24/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 501;
int n, k;
int dp[MAX][MAX];
pair<int,int>arr[MAX];
int dist(int org, int dest){return abs(arr[org].first-arr[dest].first)+abs(arr[org].second-arr[dest].second);}
int main(){
    //freopen("marathon.in","r",stdin);
    //freopen("marathon.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++)cin >> arr[i].first >> arr[i].second;
    dp[2][0] = dist(2,1);
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            int temp = 1e9;
            for(int k=0;k<=j;k++){
                if(i-1-k<=0)break;
                temp = min(temp, dp[i-1-k][j-k]+dist(i,i-1-k));
            }
            dp[i][j] = temp;
        }
    }
    int ans = 1e9;
    for(int i=0;i<=k;i++)ans = min(ans,dp[n][i]);
    cout << ans;
    return 0;
}
