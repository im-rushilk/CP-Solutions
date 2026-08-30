#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int k;
        cin >> k;

        vector<int> v(n);

        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        bool present = false;

        for(int i = 0; i < n; i++){
            if(v[i] == k){
                present = true;
            }
        }

        if(present){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}