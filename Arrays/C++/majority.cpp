#include<bits/stdc++.h>
using namespace std;

int brute_solve(vector<int> &vec,int len){
  int count = 0,element=INT_MIN;
  for(int i=0;i<len ;i++){
    count =0;
    for(int j = i+1;j<len;j++){
      if (vec[i] == vec[j]){
        count++;
      }
    }
    if(count > len/2){
      element = vec[i];
      break;
    }
  }
  return element;
}




int better_solve(vector<int> &vec,int len){
  map<int,int> mp;
  for(int i=0;i<len;i++){
    mp[vec[i]]++;
  }
  for(auto i : mp){
    if(i.second > len/2){
      return i.first;
    }
  }
  return INT_MIN;
}

int optimal_solve(vector<int> vec,int len){
  int count = 0;
  int element = vec[0];

  for(int i=0;i<len;i++){
    if(element==vec[i]){
      count ++;
    }
    else{
      count--;
    }
    if(count ==0){
      element = vec[i];
      count = 1;
    }
  }
  count=0;
  for(int i =0;i<len;i++){
    if(element == vec[i]){
      count ++;
    }
  }
  if(count > len/2){
    return element;
  }
return INT_MIN;
}


int main(){
  vector<int> vec = {1,2,1,2,3,3,3,3,3,3};
  int result;
  //result = brute_solve(vec,vec.size());
  //result = better_solve(vec,vec.size());
  result = optimal_solve(vec,vec.size());
  cout<<result;
  return 0;
}
