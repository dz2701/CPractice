//
//  main.cpp
//  2xn타일링2
//
//  Created by Shin Lee on 06/04/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
long long arr[1005];
int main(){
    int n;
    cin >> n;
    arr[1] = 1;
    arr[2] = 3;
    for(int i=3;i<=n;i++){
        arr[i] = arr[i-1] + 2*arr[i-2];
        arr[i]%=10007;
    }
    
    cout << arr[n];
    
}
