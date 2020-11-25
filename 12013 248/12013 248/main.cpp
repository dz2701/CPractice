//
//  main.cpp
//  12013 248
//
//  Created by dz2701 on 10/27/20.
//

#include <bits/stdc++.h>
using namespace std;
int n; arr[249];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp; arr.push_back(temp);
    }
    cout << Solve(arr);
}
//dp[i][j] --> i~j all use max (if impossible -1)

