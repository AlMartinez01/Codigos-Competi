#include <iostream>
#include <functional>
using namespace std;

int main(){
    int i1;

    for(int i = 0; i < 25; i++){
        cin >> i1 ;
        
        if (i1 == 1){
            int fila = i / 5;
            int diff;

            if (fila > 2) diff = fila - 2;
            else diff = 2-fila;

            int columa = i % 5;
            int diff2;

            if (columa > 2) diff2 = columa - 2;
            else diff2 = 2-columa;

            cout << diff + diff2 << "\n";
        }
    }
}