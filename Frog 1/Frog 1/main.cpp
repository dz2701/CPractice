//
//  main.cpp
//  Frog 1
//
//  Created by Shin Lee on 1/28/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int n, dp[MAX], arr[MAX];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)cin >> arr[i];
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        dp[i] = min(dp[i-1] + abs(arr[i]-arr[i-1]), dp[max(i-2,1)] + abs(arr[i]-arr[max(1,i-2)]));
    }
    cout << dp[n];
}
