#include<bits/stdc++.h>
using namespace std;

int brute_solve(vector<int> nums){
  int sum,maxsum = 0;
  int len = nums.size();
  for(int i=0;i<len;i++){
    sum = 0;
    for(int j=i;j<len;j++){
      sum += nums[j];
      maxsum = max(sum,maxsum);
    }
  }
  return maxsum;

}

int optimal_solve(vector<int> nums){
  int maxsum = INT_MIN;
  int len = nums.size();
  int sum = 0;
  for(int i =0;i<len;i++){
    sum += nums[i];
    maxsum = max(maxsum,sum);
    if(sum < 0){
      sum = 0;
    }
  }
  return maxsum;
}

int main(){
  vector<int> nums = {1,2,-1,4,2,6,-7,1};
  int result; 
  //result = brute_solve(nums);
  //result = better_solve(vec);
  result = optimal_solve(nums);
  cout<<result;
  return 0;

}
