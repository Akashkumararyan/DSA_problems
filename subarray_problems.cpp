#include <iostream>

int main() {
  int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size(),sum=0;
        for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
              for(int k=i;k<=j;k++){
                  if((j-i)%2==0)
                  sum += arr[k];
              }
          }
        }
        return sum;
    }
}
