//
//  main.cpp
//  Pointer Tutorial
//
//  Created by Shin Lee on 4/8/21.
//

//reference: https://gist.github.com/ericandrewlewis/720c374c29bbafadedc9

#include <bits/stdc++.h>
using namespace std;

void changevalue(int* num){
    *num+=5; //dereference
}
struct Point{
    int x, y;
};
int main(){
    int *emptypointer; //0x0
    int *randompointer = new int(3); //assigns value with creation
    
    *randompointer = 4; //access memory using dereferencing operator
    
    //using pointers will lower memory usage
    //no additional variables will be created
    
    int n = 5;
    changevalue(&n); //give the 'address' of variable.
    cout << n;
    
    //structure pointers are to be accessed with the arrow operator
    struct Point* p2 = new Point({1,2});
    cout << p2->x; //does not need to be dereferenced
    
    return 0;
}
