#include<bits/stdc++.h>
using namespace std;

//either stop at perticular iteration or based on epsilon
#define MAX_ITER 1000000
#define EPSILON 0.001

// An example function whose solution is determined using
// Regular Falsi Method. The function is x^3 - x^2  + 2
double func(double x)
{
    return x*x - 4*x - 10;
}

// Prints root of func(x) in interval [a, b]
void regulaFalsi(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a;  // Initialize result

    // for (int i=0; i < MAX_ITER; i++)
    while(b-a>EPSILON)
    {
        // Find the point that touches x axis
        c = (a*func(b) - b*func(a))/ (func(b) - func(a));

        // Check if the above found point is root
        if (func(c)==0)
            break;

        // Decide the side to repeat the steps
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c<<endl;
}

// Driver program to test above function
int main()
{
    // The function is x^2 - 4*x  - 10
    double a =1, b=-4, c=-10;

    double upper =sqrt(((b/a)*(b/a))-(2*(c/a)));
    // cout<<upper<<endl;
    double lower =-upper;
    int s=static_cast<int>(2*upper)+1;
    vector<double>vec(s,0);//to store the value of the function at points btw lower and upper
    vec[0]=func(lower);

    for(int i=1;i<=(2*upper);i++){

        vec[i]=func(i+lower);//calling a function f

        if(vec[i]*vec[i-1]<0){  
            // cout<<"got a root"<<endl;
            regulaFalsi(i+lower-1,i+lower);
        }
    }
    
    return 0;
}
