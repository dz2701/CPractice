//
//  main.cpp
//  asdnjfkas
//
//  Created by Shin Lee on 1/14/21.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int>s; s.insert(1); s.insert(5); s.insert(7);
    
    cout << *s.lower_bound(2) << endl;
    cout << * s.lower_bound(5) << endl;
    cout << *s.lower_bound(99) << endl;
}
