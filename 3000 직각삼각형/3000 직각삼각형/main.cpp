//
//  main.cpp
//  직각삼각형
//
//  Created by Shin Lee on 08/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n;
const int siz = 1e6+5;
long long samex[siz], samey[siz];
pair<int, int>co[siz];
int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        samex[a]++;
        samey[b]++;
        co[i] = {a,b};
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans = ans + (samex[co[i].first]-1) * (samey[co[i].second]-1);
    }
    
    cout << ans;
    
    return 0;
    
}
