#include<bits/stdc++.h>
using namespace std;
vector<pair<char,int>>mp={{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15}};
string int_part(string input, int curr_base, int required_base) {
    // Step 1: Convert the input number to base 10
    int value = 0;
    for (int i = 0; i < input.size(); i++) {
        if(input[i]-'0'>=curr_base){
            value+=mp[input[i]-'A'].second*pow(curr_base,input.size()-i-1);
        }
        else{
            value += (input[i] - '0') * (pow(curr_base, input.size() - i - 1));
        }
    }

    // Step 2: Change the base of the number to the required base
    string ans = "";
    while (value > 0) {
        ans += to_string(value % required_base);
        value /= required_base;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string num1, num2;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;
    int base1,base2;
    cout<<"Enter the base of the two numbers: ";
    cin>>base1>>base2;
    cout<<"Enter the base of the output number: ";
    int output_base;    
    cin>>output_base;

    string int1 = int_part(num1,base1,output_base);
    string int2 = int_part(num2,base2,output_base);

    //return product of the two numbers in the base requored by the user

    int product = stoi(int1)*stoi(int2);
    string ans = "";
    while(product>0){
        ans+=to_string(product%output_base);
        product/=output_base;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}