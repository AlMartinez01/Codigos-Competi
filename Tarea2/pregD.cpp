#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;

int main(){
    int leng_string;
    cin >> leng_string;
    vector<int> data(leng_string,0);
    
    int mount_distinct_letters = 0;
    int val;
    for(int i = 0; i < leng_string; i++){
        cout << "? " << "2 " << "1 " << i+1 << endl;
        cin >> val;
        if (val == 0) return 1;
        if (val != mount_distinct_letters){
            mount_distinct_letters++;
            data[i] = mount_distinct_letters;
        }
        else{
            if (mount_distinct_letters == 1){
                data[i] = mount_distinct_letters;
            }
        }
    }

    for(int i = 1; i < leng_string; i++){
        if (data[i]==0){
            int t = i - 1;
            int dist_letters = 1;
            while(t >= 0){
                cout << "? " << "2 " << t+1 << " " << i+1 << endl;
                cin >> val;
                if (val == 0) return 1;
                if (val == dist_letters){
                    data[i] = data[t];
                    break;
                }
                else{
                    dist_letters++;
                }
                t--;
            }
        }
    }

    vector<char> letters(mount_distinct_letters);
    char valC;
    int i = 1;
    for(int j = 0; j < leng_string; j++){
        if(data[j] == i){
            cout << "? " << "1 " << j+1 << endl;
            cin >> valC;
            if (valC == 0) return 1;
            letters[i-1] = valC;
            i++;
        }
    }

    cout << "! ";
    for(auto i: data){
        cout << letters[i-1];
    }
    cout << endl;
}