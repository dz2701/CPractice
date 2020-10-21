//
//  main.cpp
//  10674 Meeting Time
//
//  Created by dz2701 on 10/6/20.
//

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n, m;
vector<pii>BADJ[101], EADJ[101];

int arr[101][10001];
int aarr[101][10001];
int main(){
    freopen("meeting.in","r",stdin);
    freopen("meeting.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        BADJ[max(a,b)].push_back(make_pair(min(a,b),c));
        EADJ[max(a,b)].push_back(make_pair(min(a,b),d));
    }
    arr[1][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10000;j++){
            for(auto adj: BADJ[i]){
                if(j-adj.second>=0){
                    arr[i][j]+= arr[adj.first][j-adj.second];
                }
            }
        }
    }
    
    aarr[1][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10000;j++){
            for(auto adj: EADJ[i]){
                if(j-adj.second>=0){
                    aarr[i][j]+= aarr[adj.first][j-adj.second];
                }
            }
        }
    }
    
    for(int i=0;i<=10000;i++){
        if(arr[n][i] and aarr[n][i]){
            cout << i;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
