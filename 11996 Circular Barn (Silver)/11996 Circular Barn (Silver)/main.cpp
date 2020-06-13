//
//  main.cpp
//  Circular Barn
//
//  Created by Shin Lee on 28/03/2020.
//  Copyright © 2020 Shin Lee. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n; vector<int>v;
int main(){
    cin >> n;
    long long f=0;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
        f = max(0LL,f+v[i]-1);
    }
    for(int i=0;;i++){
        if(f==0){
            rotate(v.begin(),v.begin()+i,v.end());
            break;
        }
        f = max(0LL, f+v[i]-1);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        long long change = v[i]+f-1;
        ans+=(change*(change+1)*(2*change+1)/6)-((f-1)*f*(2*f-1)/6);
        f = max(0LL, f+v[i]-1);
    }
    
    cout << ans;
    return 0;
}
