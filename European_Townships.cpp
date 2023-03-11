#include<iostream>
#include<fstream>
#include<cmath>
#include<sstream>

using namespace std;

int main(){
    
    ifstream in("ET_small.txt");
    int t,n;
    long long r=3,s=4,h=6;
    in>>t;
    int no=1;
    string temp,temp2;
    ofstream out("Output_2_Small.txt");
    while(t--){
        in>>n;
        int arr[n][4];
        long long wall = 0 ;
        for(int i=0;i<n;i++){
            in>>temp;
            stringstream stemp(temp);
            getline(stemp,temp2,','); 
            arr[i][0]=stoi(temp2);
            getline(stemp,temp2,',');
            arr[i][1]=stoi(temp2);
            getline(stemp,temp2,',');
            arr[i][2]=stoi(temp2);
            getline(stemp,temp2);
            arr[i][3]=stoi(temp2);
            wall += (arr[i][1]*r) + (arr[i][2]*s) + (arr[i][3]*h);
        }

	    double ac = ( wall *1.0) / 3  ;
	    double rc = ( wall *2.0) / 3  ;
	    double time = ac*2.5 + rc*3.25  ;
	    double acq = ac*1.5 ; 
	    double rcq = rc*2.25 ; 
		
	    time=(round(time*100))/100;
        acq=(round(acq*100))/100;
        rcq=(round(rcq*100))/100;
        
        out<<"Case #"<<no<<": "<<time<<", "<<acq<<", "<<rcq<<endl;
        no++;
    }
    
	in.close();	
    out.close();
    return 0;
}


