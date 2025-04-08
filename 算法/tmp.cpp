#include<iostream>
using namespace std;

int main(){
    int k;
    string s;
    cin >> k;
    getline(cin, s);
    int l=0,r=s.size()-1;
    while(l<r){
        swap(s[l++],s[r++]);
    }
    l=0;r=k-1;
    while(l<r){
        swap(s[l++],s[r++]);
    }
    l=k;r=s.size()-1;
    while(l<r){
        swap(s[l++],s[r++]);
    }
    cout << s;
}