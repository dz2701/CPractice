//
//  main.cpp
//  10761 Bessie Goes Moo
//
//  Created by dz2701 on 10/1/20.
//

#include <bits/stdc++.h>
using namespace std;

vector<int>v[8];
int n;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        char temp; int val;
        cin >> temp >> val;
        if(temp=='B')v[1].push_back(val);
        if(temp=='E')v[2].push_back(val);
        if(temp=='S')v[3].push_back(val);
        if(temp=='I')v[4].push_back(val);
        if(temp=='G')v[5].push_back(val);
        if(temp=='O')v[6].push_back(val);
        if(temp=='M')v[7].push_back(val);
    }
    //eq = (B+2E+2S+I) * (G+O+E+S) * (M+2O)
    //each of them has to be multiple of 7. we can consider them separately:
    //if for 1 and 2, we view every single instance of an varaible, we will take
    // O(500^4), which is O(5e8). this can be performed.
    
    //so we want to find:
    // (only 1) + (only 2) + (only 3) - (1 and 2) - (2 and 3) - (3 and 1) + (1 and 2 and 3);
    //but then at this point it's unable to be solved.
    
    ??/
}
