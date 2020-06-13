//
//  main.cpp
//  베스트셀러
//
//  Created by Shin Lee on 02/02/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
map<string, int> a;
int main() {
    int n;
    string maxind;
    int ma = -1;
    cin >> n;
    for(int i=0;i<n;i++){
        string b;
        cin >> b;
        a[b]++;
        if(a[b]>ma){
            maxind = b;
            ma = a[b];
        }else if(a[b]==ma){
            maxind = min(maxind, b);
        }
    }
    cout << maxind;
    
    return 0;
}
