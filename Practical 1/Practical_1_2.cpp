#include <iostream>
using namespace std;

int book_count[100];

int main()
{
    int n;
    cout << "Enter number of records: ";
    cin >> n;

    cout << "Enter book id:";
    for(int i=0; i<n; i++){
        int id;
        cin >> id;
        book_count[id]++;
    }

    cout << "Books borrowed more than once are:";
    for(int i=0; i<100; i++){
        if(book_count[i]>1){
            cout << i << " ";
        }
    }
    return 0;
}