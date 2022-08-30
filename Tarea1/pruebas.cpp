#include<bits/stdc++.h>

using namespace std;

int main(){
    int cant_dat;
    cin >> cant_dat;

    multiset <int> DIE;
    int val;
    for (int i = 0; i < cant_dat ; i++){
        cin >> val;
        DIE.insert(val);
    }

    multiset<int>::iterator it_init_DIE = DIE.begin();
    cout << *it_init_DIE << endl;
    DIE.insert(10);
    it_init_DIE--;
    cout << *it_init_DIE << endl;
}