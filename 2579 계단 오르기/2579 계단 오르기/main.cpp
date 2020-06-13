//
//  main.cpp
//  계단 오르기
//
//  Created by Shin Lee on 06/04/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int stairs[305];
long maxval[305][3];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++)cin >> stairs[i];
    maxval[0][1]= stairs[0];
    maxval[0][2] = -1e9;
    maxval[1][1] = stairs[1];
    maxval[1][2] = stairs[0]+stairs[1];
    for(int i=2;i<n;i++){
        maxval[i][1] = stairs[i]+max(maxval[i-2][2], maxval[i-2][1]);
        maxval[i][2] = stairs[i]+maxval[i-1][1];
    }
    cout << max(maxval[n-1][1],maxval[n-1][2]);
    return 0;
}
