#include<bits/stdc++.h>

using namespace std;

int mcd(int,int,int &);
int musicEnd(vector<int> &,int);

int main(){
    vector<int> tra = {5, 9, 2, 10, 15};
    musicEnd(tra ,5);

    
    /*
    int a, b;
    int resultado = 0;
    cin >> a;
    cin >> b;
    if(mcd(a,b,resultado) == 1) cout << resultado << endl;
    else cout << "no tiene mcd (solo 1) \n";
    */

    return 1; 
}

//funcion que busca el valor del minimo como un divisor de x e y
//se guarda en resultado
//Retorna 1 si se encontro uno y retorna un 0 si no.
int mcd(int x,int y,int &resultado){
    if (x < y){
        return mcd(y,x,resultado);
    }
    while (y != 0){
        int tmp_b = x % y;
        x = y;
        y = tmp_b;
    }
    if (x == 1) return 0; //Este es el caso de que no tenga aparte de 1;
    resultado = x;
    return 1;
}


int musicEnd(vector<int> &a,int cant){
    int last_music = a[0];//Cancion en la que "se esta"
    int last_change = 0; //Cancion antes del cambio (suponemos a a[0] cambiado) en forma indice
    int cant_vec = cant-1;
    int i = (1)%cant_vec;

    queue<int> orden;

    int resultado; // DATO INUTIL
    int music_erased = 0;
    if (1 == mcd(last_music,a[i],resultado)){
        last_music = a[i]; //La ultima cancion reproducida es a[i]
        i = (i+1)%cant_vec;
    }
    else{
        music_erased++;
        orden.push(i+1);
        a[i] = 0;
        i = (i+1)%cant_vec; //Busca la siguiente cancion
        last_music = a[i]; //La escucha (Como olvido la anterior no importa)
        last_change = i; //implantamos que last_change fue anterior a last_music
        i = (i+1)%cant_vec;
        }
    while(last_change != i-1){
        if (1 == mcd(last_music,a[i],resultado)){
            last_music = a[i]; //La ultima cancion reproducida es a[i]
            i = (i+1)%cant_vec;
            while (a[i] == 0) i = (i+1)%cant_vec; //hacemos que a[i] siempre apunte a un dato util (los 0 son datos "borrados")
        }
        else{
            music_erased++;
            orden.push(i+1);
            a[i] = 0;
            while (a[i] == 0) i = (i+1)%cant_vec; //Busca la siguiente cancion
            last_music = a[i]; //La escucha (Como olvido la anterior no importa)
            last_change = i; //implantamos que last_change fue anterior a last_music
            i = (i+1)%cant_vec;
            while (a[i] == 0)  i = (i+1)%cant_vec;
        }
    }
    cout << music_erased;
    for(int i = 0; i < music_erased; i++){
        cout << orden.front();
        orden.pop();
    }
    cout << endl;
    return 1;
}