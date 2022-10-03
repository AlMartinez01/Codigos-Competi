#include<bits/stdc++.h>
using namespace std;

int main(){
    int cap_barn, amount_daily;
    cin >> cap_barn >> amount_daily;

    int i = amount_daily; //is amount of pogeons 

    int k = 0;

    while(cap_barn > 0){
        k++;
        cap_barn = cap_barn - k ;
        }

    cout << k << endl;

    cout << i + k << endl;
    return 1;
}