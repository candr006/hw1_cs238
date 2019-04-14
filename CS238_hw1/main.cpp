#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> delta(int val, vector<int> v){
    vector<int> delta_vect;

    for(int i=0; i<v.size(); i++){
        int diff = abs(val-v[i]);
        delta_vect.push_back(diff);
    }

    return delta_vect;
}

bool containedWithin(vector<int> a, vector<int> b){
    bool completelyContained=true;

    for(int i=0; i<a.size(); i++){

        //if a[i] is not in b, then a is not completely contained in b
        if(b.end() == find(b.begin(), b.end(), a[i])){
            completelyContained=false;
        }
    }

    return completelyContained;
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
        }else{
            a=-1;
        }
    }
    return new_v;
}

vector<int> deleteVectfromVect(vector<int> a, vector<int> b){
    vector<int> new_v;
    for(int i=0; i<b.size(); i++){
        //if b[i] is not in a, then add to new vect
        if(a.end() == find(a.begin(), a.end(), b[i])){
            new_v.push_back(b[i]);
        }else{
            a= deleteVal(b[i],a);
        }
    }

    return new_v;
}

void printVect(vector<int> a, string message){
    cout <<message << ": {";
    for(int i=0; i<a.size(); i++){
        cout<< a[i];

        if(i!=(a.size()-1)) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

void place(vector<int> l, vector<int> x){
    printVect(l,"L");
    if(l.empty()){
        printVect(x, "Resulting X");
        return;
    }

    int y = l[getMaxIndex(l)];
    vector<int> delta_y_x= delta(y,x);

    if(containedWithin(delta_y_x,l)){
        x.push_back(y);
        l=deleteVectfromVect(delta_y_x, l);


        return;
    }

}

void partialDigest(){
    vector<int> L = {2,2,3,3,4,5,6,7,8,10};

    int width= L[getMaxIndex(L)];
    L= deleteVal(width,L);
    vector<int> X = {0, width};
    place(L,X);

    return;
}

int main(){

    partialDigest();

    return 0;
}