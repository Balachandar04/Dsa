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

int main(){
    vector<int> vec ;
    int len,temp;
    cin>>len;
    for(int i=0;i<len;i++){
        cin>>temp;
        vec.push_back(temp);
    }
    cout<<brute_solve(vec,len,9);
}