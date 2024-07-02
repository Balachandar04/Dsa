#include<bits/stdc++.h>
using namespace std;

void brute_solve(vector<int> &nums,int len){
  vector<int> pos;
  vector<int> neg;

  for(int i=0;i<len;i++){
    if(nums[i]>=0){
      pos.push_back(nums[i]);
    }
    else{
      neg.push_back(nums[i]);
    }
  }


  for(int i =0;i<len;i=i+2){
    nums[i] = pos[i/2];
  }
  for(int i =1;i<len;i+=2){
    nums[i] = neg[i/2];
  }
}
 

void better_solve(vector<int> &nums,int len){
///no better method
}

void optimal_solve(vector<int> &nums,int len){
  vector<int> arr(len,0);
  int posIdx=0,negIdx=1;

  for(int i=0;i<len;i++){
    if(nums[i]<0){
      arr[negIdx] = nums[i];
      negIdx+=2;
    }
    else{
      arr[posIdx] = nums[i];
      posIdx+=2;

    }
  }

  nums = arr;
}

int main(){
  vector<int> vec = {1,2,-3,4,-5,-8};
  //brute_solve(vec,vec.size());
  //better_solve(vec,vec.size());
  optimal_solve(vec,vec.size());
  for(auto i : vec){
    cout<<i<<" ";
   }
}
