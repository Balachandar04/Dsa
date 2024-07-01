#include<bits/stdc++.h>
using namespace std;
void brute_solve(vector<int> &vec , int len){
  sort(vec.begin(),vec.end());
}

void better_solve(vector<int> &vec ,int len){
  map<int,int> mp;
  for(int i=0;i<len;i++){
    mp[vec[i]]++;
  }

  int k = 0;
  int start =0;
  while(k<3){
    for(int i = start ;i<start+mp[k];i++){
      vec[i] = k;
    }
    start += mp[k];
    k++;
  }
}  
void optimal_solve(vector<int> &vec,int len){
  int left,mid,right,temp;
  left = mid =0;
  right= len-1;
  while(mid <= right){
    if(vec[mid]==1){
      mid++;
    }
    else if(vec[mid]==0){
      temp = vec[mid];
      vec[mid]= vec[left];
      vec[left] = temp;
      mid++;left++;
    }
    else if(vec[mid]== 2){
      temp = vec[mid];
      vec[mid] = vec[right];
      vec[right] = temp;
      right--;
    }
  }
// NOTE : always check what happens when swap values is performed and if conditions are used (use if else)
}

int main(){
  vector<int> vec = {1,2,1,1,2,2,0,0,0,1};
 // brute_solve(vec,10);
  //better_solve(vec,10);
  optimal_solve(vec,10);
  for(auto i : vec){
    cout<<i<<" ";
  }
  return 0;
}
