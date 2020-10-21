//
//  main.cpp
//  19654 Cow Jog
//
//  Created by dz2701 on 9/23/20.
//  algoirhtm: brute force

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, t;
ll arr[int(1e5+1)];
int main(){
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> t;
    ll m = 1e18;
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        ll a, b; cin >> a >> b; arr[i] = a + b*t;
    }
    for(ll i=n;i>=1;i--){
        if(arr[i]<m)ans++;
        m = min(arr[i],m);
    }
    cout << ans << "\n";
    return 0;
}

