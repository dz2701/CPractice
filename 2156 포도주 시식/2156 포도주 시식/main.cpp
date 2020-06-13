//
//  main.cpp
//  포도주 시식
//
//  Created by Shin Lee on 19/04/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX int(1e4+5)
using namespace std;
int arr[MAX];
int dp[MAX][3];
int main(){
    int n; cin>> n;
    for(int i=1;i<=n;i++)cin >> arr[i];
    dp[1][0] = 0;
    dp[1][1] = arr[1];
    dp[1][2]  = -1e9;
    int m = arr[1];
    for(int i=2;i<=n;i++){
        dp[i][0] = max(max(dp[i-1][2],dp[i-1][1]),dp[i-1][0]);
        dp[i][1] = dp[i-1][0]+arr[i];
        dp[i][2] = dp[i-1][1]+arr[i];
        m = max(max(dp[i][0],dp[i][1]),max(dp[i][2],m));
    }
    
    cout << m;
    
    
    
    return 0;
}
