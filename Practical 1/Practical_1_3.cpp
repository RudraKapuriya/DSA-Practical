#include <iostream>
#include <string>
using namespace std;

int main(){
string current_string[100];
string longest_string;
int n;
cout << "Enter number of string: ";
cin >> n;   

for(int i=0;i<n;i++){
    cin >> current_string[i];
}
longest_string = current_string[0];
for(int i=1;i<n;i++){
    if(current_string[i].length() > longest_string.length()){
        longest_string = current_string[i];
    }
}
cout << "Longest string is: " << longest_string;
return 0;
}