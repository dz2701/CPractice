//
//  main.cpp
//  Cow Checklist
//
//  Created by Shin Lee on 2/25/21.
//

#include <bits/stdc++.h>
using namespace std;
long long H, G; const long long MAX = 1e3+1;
pair<long long,long long>h[MAX], g[MAX];
long long dp[MAX][MAX][2];
long long get_dist(pair<long long,long long>a, pair<long long,long long>b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}
int main(){
    cin >> H >> G;
    for(long long i=1;i<=H;i++){
        cin >> h[i].first >> h[i].second;
    }
    for(long long i=1;i<=G;i++){
        cin >> g[i].first >> g[i].second;
    }
    fill(&dp[0][0][0],&dp[MAX-1][MAX-1][2],4e9);
    dp[1][0][0] = 0; //starting point, but otherwise we don't start there...
    for(int i=2;i<=H;i++){
        dp[i][0][0] = dp[i-1][0][0]+get_dist(h[i-1],h[i]);
        //dp[i][0][1] is impossible
    }
    g[0]=g[1];
    h[0]=h[1];
    for(long long i=1;i<=H;i++){
        for(long long j=1;j<=G;j++){
            dp[i][j][0] = min(dp[i-1][j][0]+get_dist(h[i-1],h[i]), dp[i-1][j][1]+get_dist(g[j],h[i]));
            dp[i][j][1] = min(dp[i][j-1][0]+get_dist(h[i],g[j]), dp[i][j-1][1]+get_dist(g[j-1],g[j]));
            
        }
    }
    
    cout << dp[H][G][0];
}
