#include<iostream>
using namespace std;

void linearSearch(int arr[], int n, int x){
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            cout << "Element found at index " << i;
            return;
        }
    }
    cout << "Element not found";
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;
    linearSearch(arr, n, x);
}