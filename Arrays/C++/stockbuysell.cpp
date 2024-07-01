#include<bits/stdc++.h>
using namespace std;

int optimal_solve(vector<int> vec){
  int len = vec.size();
  int min = vec[0],profit=0,maxprofit =0;
  for(int i =0;i<len;i++){
    if(min>vec[i]){
      min = vec[i];
    }
    profit = vec[i] - min;
    if(maxprofit<profit){
      maxprofit=profit;
    }
    
  }
  return maxprofit;
}

int main(){
  vector<int> price = {7,2,4,5,6,7,3,1};
  cout<< optimal_solve(price);
}
