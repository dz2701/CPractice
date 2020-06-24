//
//  main.cpp
//  1931 회의실배정
//
//  Created by dz2701 on 6/25/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
int n; struct room{int st, ed;};
const int MAX = 1e5+5;
bool cmp(room a, room b){return a.ed==b.ed?a.st<b.st:a.ed<b.ed;};
room rooms[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++)cin >> rooms[i].st >> rooms[i].ed;
    sort(rooms,rooms+n,cmp);
    int ans = 0, cur = 0;
    for(int i=0;i<n;i++){
        if(cur<=rooms[i].st){
            ans++;
            cur = rooms[i].ed;
        }
    }
    cout << ans;
    
}
