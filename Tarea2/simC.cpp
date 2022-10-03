#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ll cap_barn, amount_daily;
    cin >> cap_barn >> amount_daily;
    if (cap_barn <= amount_daily){
        cout << cap_barn << endl;
        return 0;
    }

    //ll mount_barn = cap_barn;

    ll day = 0;
    ll amount_bar = cap_barn - amount_daily;
    while (amount_bar > 0){
         day++;
         amount_bar -= day;
    }

    ll rest = day + amount_daily;
    cout << rest << endl;

    return 0;
}