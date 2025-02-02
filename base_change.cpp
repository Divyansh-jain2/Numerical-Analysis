#include<iostream>
#include<bits/stdc++.h>

// #include<string.h>
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

string fractional_part(string input, int curr_base, int required_base) {
    // Step 1: Convert to base 10
    double value = 0.0;
    for (int i = 0; i < input.size(); i++) {
        if(input[i]-'0'>=curr_base){
            value+=mp[input[i]-'A'].second*pow(curr_base,-(i+1));
        }
        else{
            value += (input[i] - '0') * pow(curr_base, -(i + 1));
        }
    }

    // Step 2: Convert to the required base
    string ans = "";
    int cnt = 0;
    while (cnt < 10 && value > 0) {
        value *= required_base;
        int digit = static_cast<int>(value);
        ans += to_string(digit);
        value -= digit;
        cnt++;
    }
    return ans;
}

int main() {
    string input;
    cout << "Enter any number: ";
    cin >> input;
    cout << "Enter the base of the input number: ";
    int curr_base;
    cin >> curr_base;
    cout << "Enter the base required: ";
    int required_base;
    cin >> required_base;

    if (input.find('.') != string::npos) {
        cout << int_part(input.substr(0, input.find('.')), curr_base, required_base) << ".";
        cout << fractional_part(input.substr(input.find('.') + 1, input.size() - input.find('.') - 1), curr_base, required_base) << endl;
    } else {
        cout << int_part(input, curr_base, required_base) << endl;
    }

    return 0;
}