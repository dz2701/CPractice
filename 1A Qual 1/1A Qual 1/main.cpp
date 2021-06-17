//
//  main.cpp
//  1A Qual 1
//
//  Created by Shin Lee on 4/9/21.
//

#include <bits/stdc++.h>
using namespace std;

bool bigger(string a, string b){
    if(a.size()!=b.size() or a==b)return false;
    
    for(int i=0;i<a.size();i++){
        if(a[i]>b[i])return true;
        else if(b[i]>a[i])return false;
        else continue;
    }
    return true;
}
int main(){
    int t; cin >> t;
    for(int casenum = 1; casenum<=t; casenum++){
        int n; long long arr[101]; string rarr[101];
        cin >> n;
        for(int i=1;i<=n;i++)cin >> arr[i];
        for(int i=1;i<=n;i++){
            while(arr[i]){
                rarr[i]+=arr[i]%10+'0';
                arr[i]/=10;
            }
            for(int j=0;j<rarr[i].size()/2;j++){
                char temp = rarr[i][j];
                rarr[i][j] = rarr[i][rarr[i].size()-i];
                rarr[i][rarr[i].size()-i] = temp;
            }
        }
        string prev = ""; long long ans = 0;
        for(int i=1;i<=n;i++){
            if(prev.size()<rarr[i].size() or bigger(rarr[i],prev)){
                prev = rarr[i];
                continue;
            }else{
                if(prev[0]==rarr[i][0]){
                    //just input the same string + 1
                    string s = "";
                    for(int i=0;i<prev.size()-1;i++){
                        s+=prev[i];
                    }
                    s+=prev[prev.size()-1]+1;
                    ans+=prev.size()-rarr[i].size();
                    prev = s;
                }else if(prev[0]<rarr[i][0]){
                    string s = ""; s+= rarr[i][0];
                    for(int i=0;i<prev.size()-1;i++){
                        s+='0';
                    }
                    ans+=prev.size()-rarr[i].size();
                    prev = s;
                }else{
                    string s = ""; s+=rarr[i][0];
                    for(int i=0;i<prev.size();i++){
                        s+='0';
                    }
                    ans+=prev.size()-rarr[i].size()+1;
                }
            }
        }
        
        printf("Case #%lld: %lld\n",casenum,ans);
    }
    
}
