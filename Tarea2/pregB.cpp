#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll busqbin(ll,vector<ll> &, ll);

int main(){
    ll cant_rep;
    cin >> cant_rep;

    ll cant_dat;
    ll val;
    
    queue<ll> memory;

    for(int i = 0; i < cant_rep; i++){
        cin >> cant_dat;
        vector<ll> datos;
        vector<ll> indices;
        int elims = 0;
        for (int j = 1; j <= cant_dat; j++)
        {
            cin >> val;
            datos.push_back(val);
            if (val < j) //filtramos la informacion
            {
                indices.push_back(j);
            }
            else elims++;
        }

        ll count = 0;
        int opti = cant_dat-elims;

        for(ll t: indices) count += busqbin(datos[t-1],indices,opti);
        
        memory.push(count);
    }
    for(int i = 0; i < cant_rep; i++){
        cout << memory.front() << endl;
        memory.pop();
    }
}

ll busqbin(ll val,vector<ll> &dats,ll len){
    ll init = 0;
    ll end = len-1;
    ll mid = (init + end) / 2;
    while(init < end){
        if(dats[mid] == val){
            return mid;
        }
        if (dats[mid] < val){
            init = mid + 1;
        }
        else{
            end = mid;
        }
        mid = (init + end) / 2;
    }
    return mid;
}