//
//  main.cpp
//  1756 The Disks
//
//  Created by dz2701 on 6/20/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5+5;
int D, N;
int disk[MAX], pizza[MAX];
stack<int>s;

int main(){
    cin >> D >> N;
    for(int i=1;i<=D;i++){
        cin >> disk[i];
    }
    for(int i=1;i<=N;i++){
        cin >> pizza[i];
    }
    int a = 1e9;
    for(int i=1;i<=D;i++){
        a=min(a,disk[i]);
        s.push(a);
    }
    
    
    for(int i=1;i<=N;i++){
        if(s.empty()){printf("0");return 0;}
        while(s.top()<pizza[i]){
            s.pop();
            if(s.empty()){printf("0");return 0;}
        }
        s.pop();
        
    }
    cout << s.size()+1;
    
}
