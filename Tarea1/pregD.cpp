#include<bits/stdc++.h>

using namespace std;

int pos_orde();

int main(){
    int cant_prueb;
    cin >> cant_prueb;
    for(int i = 0; i < cant_prueb; i++){
        pos_orde();
    }
    return 1;
}

int pos_orde(){
    int cant_guardias = 0;
    cin >> cant_guardias;

    int guar[cant_guardias];
    for(int i = 0; i<cant_guardias;i++){
        cin >> guar[i];
    }
    if (cant_guardias == 1) return 0; //No hay suficientes guardias

    sort(guar,guar + cant_guardias);

    int izq = 0;
    int der = cant_guardias -1;
    int estim[cant_guardias+1];

    int count = 0;
    while (izq < der){
        estim[count] = guar[izq];
        estim[count+1] = guar[der];
        count += 2;izq++;der--;
    }
    estim[cant_guardias] = guar[0];
    if (izq == der) estim[izq] = guar[izq];

    int mem_ini = estim[0];
    for(int i = 0; i < cant_guardias; i +=2){
        if (estim[i] >= estim[i+1]){
            cout << "NO" << endl;
            return 2;
        }
    }
    for(int i = 1; i < cant_guardias; i +=2){
        if (estim[i] <= estim[i+1]) {
            cout << "NO" << endl;
            return 2;
        }
    }
    cout << "YES" << endl;

    for(int i = 0; i < cant_guardias; i++) cout << estim[i] << " ";
    
    cout << endl;

    return 1;
}