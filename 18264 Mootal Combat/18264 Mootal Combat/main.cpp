//
//  main.cpp
//  18264 Mootal Combat
//
//  Created by Shin Lee on 12/2/20.
//

#include <bits/stdc++.h>
using namespace std;
//dp[i][j][k] == i~j 를 k로 끝나는 콤보로 만드는데 드는 최소비용
//dp[i][j][k] = min(dp[i][j-1][k] + dist[S[j]][k], for(int p -> i+c~j-c, for k -> 1~23 , dp[i][p][k]))
// (n^2 m) * (n m) = n^3 m^2

//dp[i][j] = 1~i를 j로 끝나는 콤보로 만드는데 드는 최소비용
//dp[i][j] = min(dp[i-1][j] + dist[S[i]][j], min(dp[i-1][j],dp[i-c][1~26]));
int n, m, c;
const int MAX = 1e5+1;
int arr[27][27];
int dp[MAX][27];
int dist[27][27][27];
int s[MAX];
int main(){
    
    cin >> n >> m >> c;
    string S;
    cin >> S;
    for(int i=0;i<S.size();i++)s[i] = S[i] - 'a' + 1;
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)for(int k=1;k<=m;k++)dist[i][j][k] = 1e9;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            dist[i][j][0] = arr[i][j];
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dist[i][j][k] = min(dist[i][j][k-1], dist[i][k][k-1]+dist[k][j][k-1]);
            }
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j] + dist[s[i-1]][j][n]; //s[i-1] = ith
            if(i-c>0 and i-1-1>0){
                for(int k=1;k<=m;k++){
                    //change to all cost + i-c change
                    int cost = 0;
                    for(int p=i-1;p>=i-c;p--){
                        //calculate cost to change all of these
                        cost+=dist[s[p-1]][k][n];
                    }
                    //now calculate the maximum
                    dp[i][j] = min(dp[i][j], cost+dp[i-c][k]);
                }
            }
        }
    }
    
    int ans = 1e9;
    for(int i=1;i<=m;i++)ans = min(dp[n][i],ans);
    cout << ans;
    return EXIT_SUCCESS;
}
//arr check
//base case

