//
//  main.cpp
//  Jump The Board!
//
//  Created by Shin Lee on 19/04/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX 105
using namespace std;
long long arr[MAX][MAX], grid[MAX][MAX];int n;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    grid[1][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i+arr[i][j]<=n and arr[i][j]!=0){
                grid[i+arr[i][j]][j]+=grid[i][j];
                
            }
            if(j+arr[i][j]<=n and arr[i][j]!=0){
                grid[i][j+arr[i][j]]+=grid[i][j];
                
            }
        }
    }
    
    
    cout << grid[n][n];//self counting 2 times
}
