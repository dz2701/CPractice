//
//  main.cpp
//  RGB거리
//
//  Created by Shin Lee on 08/04/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <iostream>
using namespace std;

long price[1005][4];
long ans[1005][4];
int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> price[i][1] >> price[i][2] >> price[i][3];
    }
    
    ans[0][1] = price[0][1];
    ans[0][2] = price[0][2];
    ans[0][3] = price[0][3];
    
    for(int i=1;i<n;i++){
        ans[i][1] = min(ans[i-1][2],ans[i-1][3]) + price[i][1];
        ans[i][2] = min(ans[i-1][1],ans[i-1][3]) + price[i][2];
        ans[i][3] = min(ans[i-1][1],ans[i-1][2]) + price[i][3];
    }
    
    cout << min(min(ans[n-1][1],ans[n-1][2]),ans[n-1][3]);
    
    
    return 0;
}
