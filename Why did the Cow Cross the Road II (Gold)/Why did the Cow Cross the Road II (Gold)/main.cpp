//
//  main.cpp
//  Why did the Cow Cross the Road II (Gold)
//
//  Created by dz2701 on 11/11/20.
//

#include <bits/stdc++.h>
using namespace std;

int n;
int Left[1001], Right[1001];
int dp[1001][1001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> Left[i];
    for(int i=1;i<=n;i++)cin >> Right[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),abs(Left[i]-Right[j])<=4? dp[i-1][j-1]+1 : 0);
        }
    }
    //
    cout << dp[n][n];
}
