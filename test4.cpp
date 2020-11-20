#include <iostream>
#include <algorithm>    // std::sort
#include <string>
#include <math.h>
#include <vector>

using namespace std;

bool sortbysec(const pair<int,int> &a,
               const pair<int,int> &b)
{
    return (a.first < b.first);
}

class ArrIntManager{
public:
//    a
    int Tong(int arrInt[], int size){
        int sum =0;
        for(int i =0; i< size ;i++){
            sum += arrInt[i];
        }
        return sum;
    }
//    b
    bool isPrime(int num){
        bool flag=true;
        for(int i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                flag = false;
                break;
            }
        }
        return flag;
    }
    int sumPrime(int arrInt[], int size){
        int sum = 0;
        for(int i=0;i<size;i++){
            if(isPrime(arrInt[i])){
                sum += arrInt[i];
            }
        }
        return sum;
    }
//    c
    void threeNumber(int arrInt[], int size){
        int flag = 0;
        if(size >3){
            for(int i=0; i<size-2; i++){
                if(arrInt[i]+arrInt[i+1] == arrInt[i+2]){
                    flag =1;
                    cout<<arrInt[i]<<" "<<arrInt[i+1]<<" "<<arrInt[i+2]<<endl;
                }
            }
        }
        if(flag ==0) cout<<"NO ARR"<<endl;
    }
//    d
    void subArr(int arrInt[], int size, int S){
        vector< pair <int,int> > vect;
        for (int i = 0; i < size; i++){
            int sum = 0;
            for (int j = i; j < size; j++)
            {
                sum += arrInt[j];

                if (sum == S)
                    vect.push_back( make_pair(i, j - i));
            }
        }
        sort(vect.begin(), vect.end(), sortbysec);
        for(int i = vect.at(vect.size()-1).first; i<= vect.at(vect.size()-1).first+vect.at(vect.size()-1).second; i++){
            cout<<arrInt[i]<<" ";
        }
        cout<<endl;

    }
    // e
    void longestArr(vector<int>& a) {
        int ret = 0;
        pair<int,int> p;
        int n = a.size();
        int j;
        for(int i = 0; i < n; i = j + 1){
            j = i;
            bool down = false;
            bool up = false;
            while(j + 1 < n && a[j + 1] > a[j]) {
                up = true;
                j++;
            }
            while(up && j + 1 < n && a[j + 1] < a[j]){
                down = true;
                j++;
            }
            if(up && down){
                if(j-i+1>ret){
                    ret = j-i+1;
                    p.first = i;
                    p.second = j;
                }
                j--;
            }
        }
        for(int i=p.first; i<=p.second; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        // cout<<ret<<endl;
   }


};
int main() {

    // freopen("F:\\Code\\C++\\VMO\\tst.txt", "r", stdin);
    int arr[] = {9, 4, 20, 3, 10, 5};
    ArrIntManager a;

    cout<<"4a "<<a.Tong(arr,6)<<endl;
    cout<<"4b "<<a.sumPrime(arr,6)<<endl;

    cout<<"4c "<<endl;

    a.threeNumber(arr, 6);

    cout<<"4d "<<endl;

    a.subArr(arr, 6, 33);
    
    vector<int> v = {2,1,4,7,3,2,5};
    cout<<"4e "<<endl;
    a.longestArr(v);

    return 0;
}