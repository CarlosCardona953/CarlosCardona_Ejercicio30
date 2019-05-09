#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;



int main(){
    ofstream outfile;
    float l=1;
    float tmax=2;
    float dx=0.01;
    float dt=0.01;
    int x=l/dx;
    int t=tmax/dt;
    float c=0.2;
    float beta=c*dt/dx;
    double u[x];
    double u_new[x];
    
    for(int i=0;i<x;i++){
        u[i]=sin(4*M_PI*i*dx)/2;
    }
    
    
    
   outfile.open("lax.dat");
        
    for (int j=0;j<t;j++){
        for(int i=1;i<x-1;i++){
           //u_new[j]=(1-beta*beta)*u[j]-(0.5*beta)*(1-beta)*u[j+1] + (0.5*beta)*(1 + beta )*u[j-1];
            
            
            u_new[i]=u[i]- (beta/4)*(pow(u[i+1],2)-pow(u[i-1],2)) +(pow(beta,2)/8)*( (u[i+1]+u[i])*(pow(u[i+1],2)-pow(u[i],2)) -(u[i]+u[i-1])*(pow(u[i],2)-pow(u[i-1],2)));
        
        }

       
        for(int i=0;i<x;i++){
        outfile << u[i] << " ";
        }
        outfile << "\n";

        for(int i=1;i<x-1;i++){
            u[i]=u_new[i];
        }
        
    }
    outfile.close();
    return 0;
}

