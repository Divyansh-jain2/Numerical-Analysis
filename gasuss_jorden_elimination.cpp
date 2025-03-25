
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<bitset>
#include <cstdint>
#include <iomanip>

using namespace std;
//gauss jorden elimination method
int main(){
    int n=3;
    vector<vector<double>>a(n,vector<double>(n+1));

    a={{5,10,1,28},
       {1,1,1,6},
       {4,8,3,29}};
    for(int j=0;j<n;j++){
        if (a[j][j] == 0) { // Check for zero pivot
            cout << "Divide by zero error" << endl;
            return -1;
        }
        for(int i=j+1;i<n;i++){
            double factor=a[i][j]/a[j][j];
            for(int k=j;k<=n;k++){
                a[i][k]-=(factor*a[j][k]);
            }
        }
    }
    //back substitution
    vector<double> x(n);
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1]; // Last variable solution
    for (int i = n - 2; i >= 0; i--) { // Start from n-2
        x[i] = a[i][n]; 
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i]; 
    }
    cout<<setprecision(6)<<fixed;
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }
    

    return 0;
}
