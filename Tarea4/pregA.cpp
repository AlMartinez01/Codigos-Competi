#include<bits/stdc++.h>
using namespace std;

int printPir(vector<vector<int>> piramide){
    for(vector<int> i: piramide){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 1;
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> data_or;
    int val;

    for(int i = 0; i < pow(2,n); i++){
        cin >> val;
        data_or.push_back(val);
    }

    vector<vector<int>> data(n+1);

    data[n] = data_or;

    for(int i = n-1; i >= 0; i--){
        data[i] = vector<int> (pow(2,i));
    }



    int log = 0;

    for (int i = n-1; i >= 0; i--){
        if (log == 0){
            int sizeD = data[i].size();
            log = 1;
            for(int j = 0; j < sizeD; j++){
                data[i][j] = data[i+1][j*2] | data[i+1][j*2 + 1];
            }
        }
        else{
            int sizeD = data[i].size();
            log = 0;
            for(int j = 0; j < sizeD; j++){
                data[i][j] = data[i+1][j*2] ^ data[i+1][j*2 + 1];
            }
        }
    }

    //printPir(data);

    int val1, val2;
    for(int i = 0; i < m; i++){
        cin >> val1 >> val2;
        val1--;
        data[n][val1] = val2;
        val1 = val1/2;
        int log = 0;
        for(int j = n-1; j >= 0; j--){
            if (log == 0){
                data[j][val1] = data[j+1][val1*2] | data[j+1][val1*2 + 1];
                log = 1;
            }
            else{
                data[j][val1] = data[j+1][val1*2] ^ data[j+1][val1*2 + 1];
                log = 0;
            }
            val1 = val1/2;
        }
        cout << data[0][0] << endl;

    }
    //printPir(data);
    return 0;
}

