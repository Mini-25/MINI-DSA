#include<iostream>
using namespace std;
void binarySearch(int arr[], int n, int x){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == x){
            cout << "Element found at index " << mid;
            return;
        }
        else if(arr[mid] > x){
            end = mid - 1;
        }
        else{
            start = mid + 1;
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
    binarySearch(arr, n, x);
}