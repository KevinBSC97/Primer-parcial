#include<iostream>
#include<cmath>
 
using namespace std; 

double F(double x)
{
    return -25182*x-90*pow(x,2)+44*pow(x,3)-8*pow(x,4)+0.7*pow(x,5);
    //return 4*pow(x,2)-5*x;
}

int comprobacion(int x1, int x2){
	float comp1;
	float comp2;

	comp1= -25182*x1-90*pow(x1,2)+44*pow(x1,3)-8*pow(x1,4)+0.7*pow(x1,5);
	comp2= -25182*x2-90*pow(x2,2)+44*pow(x2,3)-8*pow(x2,4)+0.7*pow(x2,5);
	//comp1 = 4*pow(x1,2)-5*x1;;
	//comp2 = 4*pow(x2,2)-5*x2;;
	 
	 if((comp1>0 &&comp2<0)||((comp2>0 &&comp1<0))){
	 	return 1;
	 }
	 else{
	 	return 0;
	 }
} 

double biseccion(double xl,double xu,int iteraciones,double critconver,double EX){
    int i=1;
    double xr;
    double fxr;
	while(i<iteraciones)
	{
        xr=(xl+xu)/2;
        fxr=F(xr);
        if(abs(xu-xl)<critconver)
            return xr;
        if(abs(fxr)<EX)
            return xr;
        if(F(xl)*fxr<0)
            xu=xr;
        if(fxr*F(xu)<0)
            xl=xr;
        i=i+1;
    }
    return xr;
} 

int main (int argc, char *argv[]) {
    float x1,x2;
    cin>>x1;
    cin>>x2;
    
    comprobacion(x1,x2);
    
	if(comprobacion(x1,x2)){
		cout<<biseccion(15,17,100,0.0005,0.00005);
	}
	else{
		cout<<"El ejercicio no se puede resolver porque no tiene raices";
	}
    return 0; 
}
