#include<iostream>
using namespace std;

int main(){
    int n,h;
    cout << "Enter the number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the number of hours: " << endl;  
    cin >> h;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int k=h%n;
    cout << k <<endl;
    for(int i=k;i<n;i++){
        cout << arr[i] << " ";
    }
    for(int i=0;i<k;i++){
        cout << arr[i] << " ";
    }

    return 0;
}