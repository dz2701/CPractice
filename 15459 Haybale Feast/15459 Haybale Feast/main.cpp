//
//  main.cpp
//  15459 Haybale Feast
//
//  Created by dz2701 on 7/27/20.
//  Copyright © 2020 dz2701. All rights reserved.
//  틀린 이유: use multiset...

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
long long n, m, F[MAX], S[MAX];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> F[i] >> S[i];
    long long st = 1, ed = 1, sum = F[1], ans = 1e9+1;
    multiset<long long>s; s.insert(S[1]);
    while(ed<n+1){
        if(sum>=m){
            //아무리 증가시켜봤자 더 작아지지는 않음. 커질수는 있겠지만 --> min 찾기라 뒤에는 안봐도 된다.
            //현재 가지고 있는 숫자들의 가장 매운맛을 구해서 최솟값을 본다.
            ans = min(ans, *s.rbegin());
            //시작점을 한칸 땡긴다.
            sum-=F[st];
            s.erase(s.find(S[st]));
            st++;
        }else{
            ed++;
            sum+=F[ed];
            s.insert(S[ed]);
        }
    }
    
    cout << ans;
    
}
