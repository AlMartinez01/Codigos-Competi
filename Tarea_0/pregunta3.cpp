#include <iostream>
#include <functional>
using namespace std;

int main(){
    int n, h; cin >> n >> h;

    int aum = 0;
    for (int i = 0; i < n ; i++){
        int alt; cin >> alt;
        if (alt > h) aum++;
    }

    cout << n+aum << "\n";
    
    return 0;
    }