#include<bits/stdc++.h>
using namespace std;

int brute_solve(vector<int> arr,int len ,int k){
    pair<int,int> p ;
    p.first = p.second = -1;
    int sum = 0,sub_len = 0;
    for(int i =0;i<len;i++){
        sum = arr[i];
        if(sum == k){
            p.first=p.second=i;
            sub_len = 1; 
        }
        for(int j = i+1;j<len;j++){
            sum += arr[j];
            if(sum == k && sub_len < (j-i+1)){
                p.first = i;
                p.second = j;
                sub_len=j-i;
            }
            if(sum>k){
                break;
            }
        }
    }
    if(p.first==-1){
        return 0;
    }
    return p.second - p.first+1;
}

int better_solve(vector<int> arr,int len ,int k){
    int sum =0,sub_len=0;
    map<int,int> mp;
    for(int i=0;i<len;i++){
        sum+=arr[i];
        if(sum==k){
            sub_len=i+1;
        }
        int rem = sum - k;
        if(mp.find(rem) == mp.end()){
            mp[sum]= i;
        }
        else{
            sub_len =max(i-mp[rem],sub_len);
        }
    }
    return sub_len;
}

int optimal_solve(vector<int> arr,int len,int k){
    int i =0,j=0;
    int sum = arr[i],sub_len = 0;
    while(j<len){
      
      while(i<=j && sum>k){
        sum -= arr[i];
        i++;
      }
      if(sum == k ){
        sub_len = max(sub_len,(j-i+1));
      }
      j++;
      if(j<len){
        sum += arr[j];
      }
    }
    return sub_len;
}


int main(){
    vector<int> vec ;
    int len,k;
    vec = {4,3,2,1,1,2,7};
    len = vec.size();
    k = 6;
    cout<<brute_solve(vec,len,k);
}
