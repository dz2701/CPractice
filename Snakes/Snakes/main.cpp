//
//  main.cpp
//  Snakes
//
//  Created by Shin Lee on 12/13/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 401;
int snakes[MAX], max_val[MAX][MAX];
pair<int,int>dp[MAX][MAX];
int n, k;
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> snakes[i];
    }
    
    for(int i=1;i<=n;i++){
        int temp = snakes[i];
        for(int j=i;j<=k+1;j++){
            temp = max(temp, snakes[j]);
            max_val[i][j] = temp;
            if(dp[i-1][j].first + max_val[i-dp[i-1][j].second][i]-snakes[i] > dp[i-1][j-1].first){
                dp[i][j].first = dp[i-1][j].first + max_val[dp[i-1][j].second][i]-snakes[i];
                dp[i][j].second = dp[i-1][j].second + 1;
            }else{
                dp[i][j].first = dp[i-1][j-1].first;
                dp[i][j].second = 0;
            }
        }
    }
    
    cout << dp[n][k+1].first;
    //dp[i][j] = 0~i using j groups min, pair --> size;
    //dp[i][j].first = min((dp[i-1][j].first + max_val[dp[i-1][j].second][i] - snake[i]), (dp[i-1][j-1].first)
    //dp[i][j].second = if decided above use that one for size: if new, 0; if not, dp[i-1][j].second+1;
    
}
