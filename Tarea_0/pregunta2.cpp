#include <iostream>
#include <functional>
using namespace std;

string parLarg(string text){
    int i = text.length();

    if (i < 11){
        cout << text << "\n";
        return text;
    }

    cout << text[0] << i-2 << text[i-1] << "\n" ;

    return "resuelto";
}


int main(){
    int max = 0;
    cin >> max;

    int i = 0;
    while (i < max){
        string s;
        cin >> s;
        parLarg(s);
        i++;
    }
    return 0;
}