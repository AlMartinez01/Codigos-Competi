#include<bits/stdc++.h>
using namespace std;

long long cantParsminor(vector <int> &); 

int main(){
    int cant_rep;
    cin >> cant_rep;

    //memory
    //queue <long long> memory;

    //optimitation
    int cant_dat;
    int val;
    vector<int> datos;
    for(int i = 0; i < cant_rep; i++){
        cin >> cant_dat;
        for (int j = 0; j < cant_dat; j++){
            cin >> val;
            datos.push_back(val);
        }
        
    }
}