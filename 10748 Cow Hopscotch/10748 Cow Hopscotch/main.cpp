//
//  main.cpp
//  10748 Cow Hopscotch
//
//  Created by dz2701 on 9/24/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;
const int FAC = 1000000007;
int dp[MAX][MAX];
int grid[MAX][MAX];
int r, c, k;
int main(){
    freopen("hopscotch.in","r",stdin);
    freopen("hopscotch.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> r >> c >> k;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> grid[i][j];
        }
    }
    dp[1][1] = 1;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            for(int p=1;p<=i-1;p++){
                for(int q=1;q<=j-1;q++){
                    if(grid[p][q]!=grid[i][j]){
                        dp[i][j]+=dp[p][q];
                        dp[i][j]%=FAC;
                    }
                }
            }
        }
    }
    cout << dp[r][c];
    return 0;
}
