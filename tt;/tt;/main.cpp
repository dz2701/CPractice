//
//  main.cpp
//  tt;
//
//  Created by dz2701 on 6/15/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans = -1;
    for(int i=0;i<=12;i++){
        for(int j=0;j<=12;j++){
            for(int z=0;z<=12;z++){
                if(i+j+z==12){
                    ans = max(ans,i*j*z + i*j + j*z + z*i);
                }
            }
        }
    }
    cout << ans;
    
}
