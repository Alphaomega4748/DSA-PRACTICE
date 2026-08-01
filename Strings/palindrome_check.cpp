#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(string s){
     int left = 0;
     int right = s.size()-1;

     while(left < right){

        while(left < right && !isalnum(s[left])){
            left++;
        }

        while(left < right && !isalnum(s[right])){
            right--;
        }
        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }
     }
     return true;
    }

    int main(){
        string s;

        cout<< " Enter String :";

        getline(cin, s);

        if(isPalindrome(s)){
            cout<<"String is a palindrome!"<<endl;
        }else{
            cout<<"Not Plindrome!";
        }
        

    }