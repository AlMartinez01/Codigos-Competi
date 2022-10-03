#include<bits/stdc++.h>

using namespace std;

int main(){
    int cant_pruebas;
    cin >> cant_pruebas;

    queue <int> buffer;
    for(int j = 0; j < cant_pruebas; j++){
        int cant_dat;
        cin >> cant_dat;
        buffer.push(cant_dat);
        for (int i = 0; i < cant_dat; i++){
            int val;
            cin >> val;
            buffer.push(val);
        }
        for (int i = 0; i < cant_dat; i++){
            int val;
            cin >> val;
            buffer.push(val);
        }
    }

    for(int j = 0; j< cant_pruebas; j++){
        int cant_dat = buffer.front();
        buffer.pop();

        multiset <int> DIE;
        multiset <int> DCC;

        for (int i = 0; i < cant_dat ; i++){
            DIE.insert(buffer.front());
            buffer.pop();
        } 
        for (int i = 0; i < cant_dat ; i++){
            DCC.insert(buffer.front());
            buffer.pop();
        }
        int cant_elim = cant_dat/4;
        int cant_rest = cant_dat - cant_elim;
        int punt_DIE = 0, punt_DCC = 0;

        multiset<int>::iterator it_DIE;
        multiset<int>::iterator it_DCC;
        it_DIE = DIE.begin();
        it_DCC = DCC.begin();
        

        for(int i = 0; i < cant_elim; i++){
            it_DIE++;
            it_DCC++;
        }
        multiset<int>::iterator it_init_DCC = it_DCC;//Quedan "apuntando" al primer dato ingresado en la sumna
        multiset<int>::iterator it_init_DIE = it_DIE;//Quedan "apuntando" al primer dato ingresado
        for (int i = 0; i < cant_rest; ++i){
            punt_DIE += *it_DIE;
            punt_DCC += *it_DCC;
            it_DIE++; //Queda apuntando a un puntaje afuera del rango
            it_DCC++; //Queda apuntando a un puntaje afuera del rango
        }


        int cant_match_ex = 0;
        while(punt_DIE < punt_DCC){
            cant_dat++; cant_match_ex++;

            DIE.insert(100);
            DCC.insert(0);
            
            //-------CAMBIO DIE------
            punt_DIE += 100;
            it_init_DIE++;
            //-------CAMBIO DCC------
            it_init_DCC--;
            punt_DCC += *it_init_DCC;
            

            if(cant_dat/4 != cant_elim){
                cant_elim++;
                //-------CAMBIO DIE------
                punt_DIE -= *it_init_DIE;
                it_init_DIE++;

                //-------CAMBIO DCC------
                it_init_DCC++;
                punt_DCC -= *it_init_DCC;
            }
        }
        cout << cant_match_ex << endl;
    }
    return 0;
}


