//
//  main.cpp
//  Segment Tree
//
//  Created by Shin Lee on 3/8/21.
//

#include <bits/stdc++.h>
using namespace std;

int arr[100]; int n;
int tree[100];

//initializing function
int init(int cur, int st, int ed){
    if(st==ed)return tree[cur]=arr[st];
    else return tree[cur] = init(cur*2,st,(st+ed)/2) + init(cur*2+1,(st+ed)/2+1, ed);
}

//query for summation
int query(int cur, int curst, int cured, int queryst, int queryed){
    //not included
    if(curst>queryed or cured<queryst)return 0;
    //range completely included
    else if(curst>=queryst and cured<=queryed)return tree[cur];
    //partilaly included -> call child
    return query(cur*2, curst, (curst+cured)/2, queryst, queryed) + query(cur*2+1, (curst+cured)/2+1, cured, queryst, queryed);
}

//update for summation
void update(int cur, int idx, int st, int ed, int ch){
    //if completely irrelated
    if(idx<st or idx>ed or st==ed)return;
    //else, we have to change value
    tree[cur]+=ch;
    update(cur*2,idx,st,(st+ed)/2,ch);
    update(cur*2+1,idx,(st+ed)/2+1,ed,ch);
}

int main(){
    cin >> n; for(int i=1;i<=n;i++)cin >> arr[i];
    init(1,1,n); //init, from the root that has info abt 1~n
    int q; cin >> q;
    while(q--){
        int t, a, b; cin >> t >> a >> b;
        if(t==1)cout << query(1,1,n,a,b) << "\n";
        //update a to b
        else if(t==2)update(1,a,1,n,-query(1,1,n,a,a)+b);
        else cerr << "invalid input";
    }
    return 0;
}
