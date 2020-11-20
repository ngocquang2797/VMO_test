#include <iostream>
#include <algorithm>    // std::sort
#include <string>
#include <math.h>
using namespace std;


class Solution{
public:
	int S(int x, int n){
    if(n == 0) return x;
    else return S(x,n-1) + pow (x,n);
}
	
};

int main() {

    // freopen("F:\\Code\\C++\\VMO\\tst.txt", "r", stdin);
    int x,n;
    cin>>x>>n;
    Solution s;
    cout<<s.S(x,n)<<endl;

    return 0;
}