//
//  main.cpp
//  C++_SQL Test
//
//  Created by dz2701 on 8/6/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <iostream>
#include <sqlite3.h>
using namespace std;


void open_DB(sqlite3* &DB, string name){
    try{
        int err = 0;
        err = sqlite3_open("test.db", &DB);
        throw err;
        
    }catch(int err){
        if(err)cerr << "DB open error!\n";
        else cout << "DB opened successfully.\n";
    }
}
static int callback(void* data, int argc, char** argv, char** azColName){
    fprintf(stderr, "%s: ", (const char*)data);
    for(int i=1;i<argc;i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void select_query(sqlite3* &DB, string q){
    int err = 0; string data = "";
    try{
        err = sqlite3_exec(DB, q.c_str(), callback, (void*)data.c_str(), NULL);
        throw err;
    }catch(int err){
        if(err!=SQLITE_OK){
            cerr << "there was an error in selection query.\n";
        }else{
            cout << "Performed successfully\n";
        }
    }
}

void create_table(sqlite3* &DB, string q){
    int err = 0;
    char* messageError;
    try{
        err = sqlite3_exec(DB, q.c_str(), NULL, 0 , &messageError);
        throw err;
    }catch(int err){
        if(err != SQLITE_OK){
            cerr << "Error Create Table\n";
            sqlite3_free(messageError);
        }
        else{
            cout << "Table created succesfully\n";
        }
    }
}

void insert_data(sqlite3* &DB, string q){
    char* messageError;
    try {
        int err = sqlite3_exec(DB, q.c_str(), NULL, 0, &messageError);
        throw err;
    }catch(int err){
        if(err!=SQLITE_OK){
            cerr << "ERROR INSERT\n";
            sqlite3_free(messageError);
        }else{
            cout << "Records created Successfully.\n";
        }
    }
}

void delete_data(sqlite3* &DB, string q){
    char* messageError;
    try {
        int err = sqlite3_exec(DB, q.c_str(), NULL, 0, &messageError);
        throw err;
    }catch(int err){
        if(err!=SQLITE_OK){
            cerr << "ERROR DELETE\n";
            sqlite3_free(messageError);
        }else{
            cout << "Records deleted Successfully.\n";
        }
    }
}
int main(int args, char** argv){
    sqlite3* DB;
    
    open_DB(DB, "test.db");
    string query = "CREATE TABLE PERSON("
                    "ID INT PRIMARY KEY     NOT NULL, "
                    "NAME           TEXT    NOT NULL, "
                    "SURNAME          TEXT     NOT NULL, "
                    "AGE            INT     NOT NULL, "
                    "ADDRESS        CHAR(50), "
                    "SALARY         REAL );";
    
    //create_table(DB, query);
    
    string insert_query ("INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);"
    "INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);"
    "INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);");
    //insert_data(DB, insert_query);
    
    
    select_query(DB, "SELECT * FROM PERSON");
    
    sqlite3_close(DB);
    cout << "application closed.\n";
    return 0;
}
