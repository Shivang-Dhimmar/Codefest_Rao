#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

bool logic(const vector<int> &a,const vector<int> &b){
    if(a[0]<b[0]) return true;
    if(b[0]<a[0]) return false;
    if(a[1]>b[1]) return true;
    if(b[1]>a[1]) return false;
    if(a[2]<=b[2]) return true;
    return false;

}

int main(){
    int t;
    ifstream in("TWSP_small.txt");
    in>>t;
    vector<vector<int>> input;
    int temp;
    vector<int> tempvec;
    int len = t ;
    while(t--){
        in>>temp;
        tempvec.push_back(temp);
        in>>temp;
        tempvec.push_back(temp);
        in>>temp;
        tempvec.push_back(temp);
        input.push_back(tempvec);
        tempvec.clear();
    }
    
    vector<vector<int>> arr=vector(input);
    for(int i=0;i<arr.size();i++){
        arr[i][0]=min(arr[i][0],5);
        arr[i][1]=min(arr[i][1],20);
        arr[i][2]=min(arr[i][2],5);
        arr[i].push_back(i);
    }
    sort(arr.begin(),arr.end(),logic);
    ofstream out("Output_1_Small.txt");

    for(auto temp: arr){
        out<<input[temp[3]][0]<<" "<<input[temp[3]][1]<<" "<<input[temp[3]][2]<<endl;
    }

    in.close();
    out.close();
    return 0;
}