//
//  main.cpp
//  Modern Art 2
//
//  Created by Shin Lee on 1/12/21.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int n, color[MAX];
int Solve(int a, int b){
    printf("Solve(%d %d) is called\n",a,b);
    if(a>=b)return 1;
    int ret = 1;
    int temp = a;
    for(int i=a+1;i<=b;i++){
        if(color[i]==color[a]){
            ret=max(Solve(temp,i)+1,ret);
            temp = i+1;
        }
    }
    if(temp<b)ret=max(Solve(temp,b)+1,ret); //up to the end is called
    printf("Solve(%d %d)=%d\n",a,b,ret);
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> color[i];
    }
    int ans = Solve(0,n); //color[0] is 0, include it to assume that it has been colored by 0
    cout << (ans<0? -1 : ans-1); //-1 bc it counts 0 as a initial coloring all
    return 0;
}
