#include <iostream>
#include <vector>
using namespace std;

vector<int> delta(int val, vector<int> v){
    vector<int> delta_vect;

    for(int i=0; i<v.size(); i++){
        int diff = abs(val-v[i]);
        delta_vect.push_back(diff);
    }

    return delta_vect;
}

int getMaxIndex(vector<int> a){
    int max_val=-1;
    int max_ind=-1;
    for(int i=0; i<a.size(); i++){
        if(a[i]>max_val){
            max_val=a[i];
            max_ind=i;
        }
    }

    return max_ind;
}

vector<int> deleteVal(int a, vector<int> v){
    vector<int> new_v;

    for(int i=0; i<v.size(); i++){
        if(v[i]!=a){
            new_v.push_back(v[i]);
        }
    }
    return new_v;
}



void partialDigest(){
    vector<int> L = {0,1};

    return;
}

int main(){

    cout << "hello world";

    return 0;
}