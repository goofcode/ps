#include <iostream>

using namespace std;

#define TRI(n) (((n)*(n+1))/2)

int tri(int n){
    for(int i=1;TRI(i)<n; i++){
        for(int j =1;TRI(j)<n;j++){
            for (int k =1 ;TRI(k)<n ;k++){
                if (n == TRI(i)+ TRI(j)+TRI(k))
                    return 1;
            }
        }
    }
    return 0;
}

int main() {

    int T; cin>> T;
    for (int t=0;t<T;t++){
        int n ; cin >> n;

        cout << tri(n)<<endl;

    }

    return 0;
}