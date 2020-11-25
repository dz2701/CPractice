//
//  main.cpp
//  ㅅ드ㅔ
//
//  Created by dz2701 on 11/10/20.
//

#include <bits/stdc++.h>

dp[i] = 1~i LIS length i end!
for(int i=1;i<=n;i++){
    int res = 0;
    for(int j=1;j<i;j++){
        if(arr[j]<arr[i])res = max(res,dp[j]);
    }
    dp[i] = res + 1;
}
