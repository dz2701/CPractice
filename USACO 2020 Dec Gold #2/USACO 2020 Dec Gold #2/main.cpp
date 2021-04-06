//
//  main.cpp
//  USACO 2020 Dec Gold #2
//
//  Created by Shin Lee on 12/20/20.
//

#include <bits/stdc++.h>
using namespace std;
char t[4] = {'A','G','T','C'};
string S;
int can_be_gene(string temp, int nextidx){
    if(temp.size() == S.size()){
        //check if viable
        char last = 'n';
        for(int i=0;i<temp.size();i++){
            if(last=='n'){
                last = temp[i];
            }else if(last==temp[i]){
                last='n';
            }
        }
        if(last=='n'){
            return 1;
        }else return 0;
    }
    long long ret = 0;
    if(S[nextidx]=='?') for(int i=1;i<4;i++){
        ret+=can_be_gene(temp+t[i],nextidx+1);
    }else ret+=can_be_gene(temp+S[nextidx], nextidx+1);
    return ret;
}
int main(){
    cin >> S;
    if(S=="?")cout << 4;
    else cout << can_be_gene("",0) +1;
}

