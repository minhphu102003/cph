#include<bits/stdc++.h>
#define ll long long

using namespace std;

int lengthNum  (int num ){
    int length = 0;
    while (num > 0)
    {
        num /= 10;
        length++;
    }
    return length;
}

string singleToRoman(int valueCurrent, int length){
    string result = "";
    if (length == 4){
        for (int  i = 0; i < valueCurrent; i++)
        {
            result += "M";
        }
        
    }else if(length == 3){
        if (valueCurrent == 9){
            result += "CM";
        }else if(valueCurrent == 4){
            result += "CD";
        }
        else if(valueCurrent >= 5){
            result += "D";
            for (int  i = 0; i < valueCurrent - 5; i++)
            {
                result += "C";
            }
        }
        else{
            for (int  i = 0; i < valueCurrent; i++)
            {
                result += "C";
            }
            
        }
    }
    else if (length == 2){
        if (valueCurrent == 9){
            result +="XC";
        }else if (valueCurrent == 4){
            result += "XL";
        }else if (valueCurrent >= 5){
            result += "L";
            for (int  i = 0; i < valueCurrent - 5; i++)
            {
                result += "X";
            }
        }else{
            for (int  i = 0; i < valueCurrent; i++)
            {
                result += "X";
            }
        }
    }else if (length == 1){
        if (valueCurrent == 9){
            result += "IX";
        }else if (valueCurrent == 4){
            result += "IV";
        }else if (valueCurrent >= 5){
            result += "V";
            for (int  i = 0; i < valueCurrent - 5; i++)
            {
                result += "I";
            }
        }else{
            for (int  i = 0; i < valueCurrent; i++)
            {
                result += "I";
            }
        }
    }
    return result;
}

string intToRoman(int num) {
    int lenght = lengthNum(num);
    string toNum = to_string(num);
    string result = "";
    int i = 0;
    while (lenght > 0)
    {
        result += singleToRoman(toNum[i] - '0', lenght);
        i++;
        lenght--;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n;
    cin>>n;
    cout<<intToRoman(n);
    return 0;
}