#include<iostream>
#include<math.h>
#include<iomanip>
#define FLOAT double
#define g (FLOAT) 9.8

using namespace std;



int main(){
  
  int N=400000;
  double h=0.0001;
  FLOAT x0=10;
  FLOAT t0=0;
  FLOAT v0=0;
  FLOAT m=5;
  FLOAT MIUk=0.1;
  FLOAT MIUe=0.2;
  FLOAT k=20;
  FLOAT wo=sqrt(k/m);
  FLOAT v,ff,a,x;
  FLOAT P=m*v0;
  
  for(int i=0;i<=N;i++){

    cout<<t0<<"\t"<<x0<<"\t"<<v0<<"\t"<<a<<"\t"<<P<<endl;
    if(v0==0){
      ff=MIUe*g;
    }
    a=-wo*wo*x0+ff;
    x=x0+h*(v0);
    v=v0+h*(a);
    P=m*v0;
    if(v0<0){
      ff=MIUk*g;
    }
    if(v0>0){
      ff=-MIUk*g;
    }
    
    if(v0*v<0){
      ff=MIUe*g;
      if(fabs(ff*m)>fabs(k*x0)){
	i=N;
	cout<<t0<<"\t"<<x0<<"\t"<<v0<<"\t"<<a<<"\t"<<P<<endl;	
      }
    }
    
    x0=x;
    v0=v;
    t0=t0+h;
  }
  
  
  
  return 0;
}
