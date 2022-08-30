#include <iostream>
#include <functional>
using namespace std;

bool funcion(int peso){
    if (peso%2 != 0) return false;
    if(peso > 2) return true;
    return false;
}

int main(){
    int s = 0;
    cin >> s;

    bool trat = funcion(s);

    if (trat == true) cout << "YES";
    else cout << "NO";

    return 0;
}