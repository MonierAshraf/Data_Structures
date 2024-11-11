// Author: Ahmed Khaled, 6 oct 24.
#include <iostream>
using namespace std;
int main(){

    // Dynamic Memory Allocation ? pointers.
    int size;
    cout<<"How big the data structure you want at runtime ? ";
    cin>>size;

    int* nodes = new int[size];//4

    for (int i = 0; i < size; i++) {
        nodes[i] = (i + 1* 10);
        //cout << "Element " << i << ": " << nodes[i] << endl;

    }

    for (int i = 0; i < size; i++) {
        cout << "Element " << i << ": " << nodes[i] << endl;
    }

    delete[] nodes;
    
    return 0;
}

