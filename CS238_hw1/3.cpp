#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <map> 

using namespace std;

int main(int argc, char *argv[]){
  int l = stoi(argv[1]);
  ifstream ifs(argv[2]);
  string input_text((istreambuf_iterator<char>(ifs) ),(istreambuf_iterator<char>()));
  
  map<string,int> l_mer_count;
  map<string,int>::iterator it;
  
  map<int,int> freq;
  
  for (int i=0; i<=(input_text.size()-l);i++){
    string l_mer=input_text.substr(i,l);
    it = l_mer_count.find(l_mer);
    
    if (l_mer_count.count(l_mer)==0){
      l_mer_count[l_mer]=1;
    }else{
      int prev=l_mer_count[l_mer];
      l_mer_count[l_mer] = prev+1;
    }
  }


  for(auto val : l_mer_count){
     //cout << val.first << " " << val.second << endl;
     
    if (freq.count(val.second)==0){
      freq[val.second]=1;
    }else{
      int prev=freq[val.second];
      freq[val.second] = prev+1;
    }
  }
  
  for(auto val : freq){
     cout << val.first << "," << val.second << endl;
  }
  

}