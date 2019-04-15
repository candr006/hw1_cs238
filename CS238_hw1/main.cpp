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

void place(vector<int> l, vector<int> x, int width){


    if(l.empty()){
        printVect(x, "X");
        return;
    }

    int y = l[getMaxIndex(l)];
    vector<int> delta_y_x= delta(y,x);

    if(containedWithin(delta_y_x,l)) {
        x.push_back(y);
        sort(x.begin(), x.end());

        l = deleteVectfromVect(delta_y_x, l);
        sort(l.begin(), l.end());

        place(l, x, width);

        x = deleteVal(y, x);
        sort(x.begin(), x.end());

        l.insert(l.end(), delta_y_x.begin(), delta_y_x.end());
        sort(l.begin(), l.end());
    }

    int w = width - y;
    vector<int> delta_w_x = delta(w, x);

    if(containedWithin(delta_w_x,l)){
        x.push_back(w);
        sort(x.begin(),x.end());

        l= deleteVectfromVect(delta_w_x,l);
        sort(l.begin(),l.end());

        place(l,x,width);

        x=deleteVal(w,x);
        sort(x.begin(),x.end());

        delta_w_x= delta(w,x);
        l.insert(l.end(), delta_w_x.begin(), delta_w_x.end());
        sort(l.begin(),l.end());

    }

        return;


}

vector<int> addIntToVect(int num, int duplicity, vector<int> v){
    while(duplicity>0){
        v.push_back(num);
        duplicity--;
    }
    return v;
}

void partialDigest(){
    vector<int> L0 = {2,2,3,3,4,5,6,7,8,10};
    //1(9), 2(8), 3(7), 4(6), 5(5), 6(4), 7(3), 8(2), 9(1)
    vector<int> L1 = {1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,5,6,6,6,6,7,7,7,8,8,9};

    //1(1), 2(1), 3(2), 4(1), 5(2), 6(1), 7(1), 9(2), 10(1), 12(1), 14(1), 15(1)
    vector<int> L2 = {1,2,3,3,4,5,5,6,7,9,9,10,12,14,15};

    //1(16), 2(15), 3(14), 4(13), 5(12), 6(11), 7(10), 8(9), 9(8),
    //          10(9), 11(8), 12(7), 13(6), 14(5), 15(4), 16(3), 17(2), 18(1)
    vector<int> L3;
    L3 = addIntToVect(1,16,L3);
    L3 = addIntToVect(2,15,L3);
    L3 = addIntToVect(3,14,L3);
    L3 = addIntToVect(4,13,L3);
    L3 = addIntToVect(5,12,L3);
    L3 = addIntToVect(6,11,L3);
    L3 = addIntToVect(7,10,L3);
    L3 = addIntToVect(8,9,L3);
    L3 = addIntToVect(9,8,L3);
    L3 = addIntToVect(10,9,L3);
    L3 = addIntToVect(11,8,L3);
    L3 = addIntToVect(12,7,L3);
    L3 = addIntToVect(13,6,L3);
    L3 = addIntToVect(14,5,L3);
    L3 = addIntToVect(15,4,L3);
    L3 = addIntToVect(16,3,L3);
    L3 = addIntToVect(17,2,L3);
    L3 = addIntToVect(18,1,L3);


    vector<int>L=L3;

    int width= L[getMaxIndex(L)];
    L= deleteVal(width,L);
    vector<int> X = {0, width};
    place(L,X,width);

    return;
}

int main(){

    partialDigest();

    return 0;
}