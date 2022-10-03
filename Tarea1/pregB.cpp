#include<bits/stdc++.h>

using namespace std;

int sorter(vector <int>,int);

int main(){
    int cant_rep;
    cin >> cant_rep;
    queue<int> buffer;
    for(int i = 0; i < cant_rep;i++){
        int can_num;
        cin >> can_num;
        buffer.push(can_num);
        for (int i = 0; i < can_num; i++){
            int val;
            cin >> val;
            buffer.push(val);
        }
    }
    for(int i = 0; i < cant_rep; i++){
        int can_num = buffer.front();
        buffer.pop();
        vector<int> arreglo;
        for(int j = 0; j < can_num; j++){
            arreglo.push_back(buffer.front());
            buffer.pop();
        }
        sorter(arreglo,can_num);
    }
    
    return 0;
}

int sorter(vector <int> arreglo, int cant_dat){
    for(int i = 0; i < cant_dat; i++){
        int val = i + 1;
        if (arreglo[i] == 0){
            cout << val + 1;
        }
        else{
            int result = val/arreglo[i];
            cout << result;
        }
    }
    //cout << endl;
    return 0;
}