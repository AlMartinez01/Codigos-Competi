#include<bits/stdc++.h>
using namespace std;

/*
void mostrar_matriz(vector<vector<int>> matriz){
    for(auto i: matriz){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}
*/

int max_fil(vector<int> &,int ,int &); //Encuentra el maximo valor obtenible en las filas

int main(){
    int N, M;
    vector <int> memory;

    int val; //optimacion
    while(cin >> N >> M, N != 0){
        vector<vector<int>> matriz(N,vector<int> (M));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                cin >> val;
                matriz[i][j] = val;
            }
        }
        vector<int> punt_fil(N);

        for (int i = 0; i < N; i++){
            punt_fil[i] = max_fil(matriz[i],0,M);
        }
        memory.push_back(max_fil(punt_fil,0,N));
        //mostrar_matriz(matriz);
    }
    for (int i: memory) cout << i << endl;
    return 0;
}

int max_fil(vector<int> &lista,int t, int &len){
    if (t >= len)return 0;
    return max(lista[t] + max_fil(lista,t+2,len),max_fil(lista,t+1,len));
}