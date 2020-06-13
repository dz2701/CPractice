//
//  main.cpp
//  영화감독 숌
//
//  Created by Shin Lee on 22/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    int num = 666;
    while(n-1){
        bool yes = false;
        num++;
        int change = num;
        while(change){
            if(change%1000==666)yes = true;
            change/=10;
        }
        if(yes)n--;
    }
    
    cout << num;
    return 0;
}
