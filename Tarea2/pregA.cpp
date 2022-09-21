//Incluimos indices 
#include<bits/stdc++.h>
using namespace std;

int busqbin(int,vector<int> &, int);

int main(){
    int cant_rep, cant_dat;
    cin >> cant_dat >> cant_rep;

    vector<int> vector;//Nuestro vector de datos
    int val = 0; //variable para ingresar los valores al vector
    for(int i = 0; i < cant_dat; i++){//introducimos los valores
        cin >> val;
        vector.push_back(val);
    }

    for(int i = 0; i < cant_rep; i++){//recogemos los numeros que buscamos (reutilizamos val)
        cin >> val;
        val = busqbin(val,vector,cant_dat);
        cout << val << endl;
    }
    return 0;
}

int busqbin(int val,vector<int> &dats,int len){
    int init = 0;
    int end = len-1;
    while(init <= end) {
        int mid = (init + end)/2;

        if(dats[mid] == val){//Existe la posibilidad de que el haya menores mas a la izq;
            int ubq = mid; //Guardamos la ubicacion actual
            mid--;//hacemos que mid disminuya para buscar hacia la izq
            
            for(int i = mid; i >= 0; i--){//revisamos hacia la izq, cuantos "val" quedan
                if(dats[mid] == val){ //si se encuentra cambiamos la ubq
                    ubq = mid;
                    mid--;
                }
                else break; //si es diferente rompemos el for y retornamos ubq sin cambiar
            }
            return ubq;
        }

        if(dats[mid] < val) init = mid+1; //si es mayor cambiamos el inicio a mid
        else end = mid-1;//si es mas pequeño que mid, entonces cambiamos el final a mid
    }
    return -1;
}