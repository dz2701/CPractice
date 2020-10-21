//
//  main.cpp
//  10147 Censoring
//
//  Created by dz2701 on 9/24/20.
//

#include <bits/stdc++.h>
using namespace std;
string s, t;
int main(){
    cin >> s >> t;
    //reverse t
    string mt;
    for(int i=t.size()-1;i>=0;i--){
        mt+=t[i];
    }
    string r;
    for(int i=s.size()-1;i>=0;i--){
        r+=s[i];
        if(r.size()<t.size())continue;
        if(r.substr(r.size()-t.size(),r.size())==mt){
            r = r.substr(0,r.size()-t.size());
        }
    }
    for(int i=r.size()-1;i>=0;i--){
        cout << r[i];
    }
    return 0;
}
