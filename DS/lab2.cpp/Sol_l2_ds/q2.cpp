#include<iostream>
using namespace std;
int main(){
  int arr[7]={64,34,25,12,22,11,90};
  int temp;
  for (int i=0;i<7;i++){
    for(int j=i+1;j<7;j++){
      if(arr[i]>arr[j]){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        
      }
    }
  }
  for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
  }
  
  
  
}