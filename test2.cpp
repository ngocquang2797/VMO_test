#include <iostream>
#include <algorithm>    // std::sort
using namespace std;


class DrawAnyShape{
public:
    void drawShape(int height){
        if(height%2 == 0){
            int toph = int(height/2);
            for(int i = 1; i <= toph; i++)
            {
                for(int j = 1; j < i; j++){
                    cout << " ";
                }
                for(int j = 1; j <= (toph*2 -(2*i-1)); j++){
                    cout << "*";
                }
                cout << endl;
            }
            for(int i = 1; i <= toph; i++) {
                for(int j = i; j < toph; j++) {
                    cout << " ";
                }
                for(int j = 1; j <= (2*i-1); j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
        else{
            int toph = int(height/2)+1;
            for(int i = 1; i <= toph; i++)
            {
                for(int j = 1; j < i; j++){
                    cout << " ";
                }
                for(int j = 1; j <= (toph*2 -(2*i-1)); j++){
                    cout << "*";
                }
                cout << endl;
            }
            for(int i = 2; i <= toph; i++) {
                for(int j = i; j < toph; j++) {
                    cout << " ";
                }
                for(int j = 1; j <= (2*i-1); j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
    }
};

int main() {

    // freopen("F:\\Code\\C++\\VMO\\tst.txt", "r", stdin);
    int n; cin>>n;
    DrawAnyShape a;
    a.drawShape(n);

    return 0;
}