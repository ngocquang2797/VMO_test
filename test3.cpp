#include <iostream>
#include <algorithm>    // std::sort
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <set>

using namespace std;

bool sortbysecdesc(const pair<char,int> &a,
                   const pair<char,int> &b)
{
       return a.second<b.second;
}

class MyString{
private:
    string myString;
public:
    MyString(string s){
        myString = s;
    }
    // a
    int tong(){
        int sum = 0;
        for(int i=0; i<myString.length(); i++){
            sum += myString.at(i);
        }
        return sum;
    }
    // b
    int Tong(){
        int sum = 0;
        for(int i=0; i<myString.length(); i++){
            if(isupper(myString.at(i))){
                sum += myString.at(i);
            }
        }
        return sum;
    }
// c
    void printFrequency(string str, int n){
        map <char, int> M;

        for (int i = 0; str[i]; i++) {

            if (M.find(str[i]) == M.end()) {
                M.insert(pair<char,int>(str[i], 1));
            }

            else{
                M[str[i]]++;
            }
        }
        

        std::vector<pair<char, int>> v;
        
        for (auto& it : M) {
            v.push_back(make_pair(it.first,it.second));
        }
        sort(v.begin(), v.end(), sortbysecdesc);

        int mmm = v.at(0).second;
        for (auto& it : v) {
            if(it.second == mmm){
                cout<<"'"<<it.first<<"'"<<" ";
            }
            else{
                cout<<":"<<mmm<<endl;
                mmm = it.second;
                cout<<"'"<<it.first<<"'"<<" ";
            }
        }
        cout<<":"<<mmm<<endl;
    } 

    // d
    string LCS(string X, string Y, int m, int n)
    {
        int maxlen = 0;
        int endingIndex = m;


        int lookup[m + 1][n + 1];

        memset(lookup, 0, sizeof(lookup));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (X[i - 1] == Y[j - 1])
                {
                    lookup[i][j] = lookup[i - 1][j - 1] + 1;

                    if (lookup[i][j] > maxlen)
                    {
                        maxlen = lookup[i][j];
                        endingIndex = i;
                    }
                }
            }
        }
        return X.substr(endingIndex - maxlen, maxlen);
    }
};

int main() {

    // freopen("F:\\Code\\C++\\VMO\\tst.txt", "r", stdin);
    MyString a = MyString("abcAdef");
    cout<<"3 a"<<endl;
    cout<<a.tong()<<endl;
    cout<<"3 b"<<endl;
    cout<<a.Tong()<<endl;

    string X = "ABBSAHelloworldAJNSKJSN";
    string Y = "jbasdnkjnduwHelloworldkjnndw";

    int m = X.size();
    int n = Y.size();
    cout<<"3 d"<<endl;

    cout<<"Longest substring: "<<a.LCS(X, Y, m, n)<<endl;

    cout<<"3 c"<<endl;

    a.printFrequency(X, 2);

    return 0;
}