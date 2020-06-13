//
//  main.cpp
//  트리
//
//  Created by dz2701 on 5/11/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
#define MAX 400005
using namespace std;
int n, q;
int connection[MAX], arr[MAX];
struct qq{
    int id;
    int num;
    int question1, question2;
};
qq question[MAX];
int Find(int a){
    if(arr[a]==a)return a;
    else return arr[a] = Find(arr[a]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    arr[a]=b;
}
vector<string>ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        cin >> connection[i];
    }
    for(int i=0;i<n+q-1;i++){
        cin >> question[i].id;
        if(question[i].id==1){
            cin >> question[i].question1 >> question[i].question2;
        }else cin >> question[i].num;
    }
    for(int i=1;i<=n;i++)arr[i] = i;
    for(int i=n+q-2;i>=0;i--){
        if(question[i].id==0){
            Union(question[i].num,connection[question[i].num]);
        }else{
            if(Find(question[i].question1)==Find(question[i].question2)){
                ans.push_back("YES");
            }else ans.push_back("NO");
        }
    }
    
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] + "\n";
    }
    
    return 0;
}
