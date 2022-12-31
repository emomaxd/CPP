#include <iostream>
#include <math.h>

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

bool test(double x,double y,double z){
    double sum=x+y+z;
        
            if(sum!=x+z+y||sum!=y+x+z||sum!=y+z+x||sum!=z+x+y||sum!=z+y+x){
                return false;
            }

    return true;
}

int main(){
    double x,y,z;
    
    for(int i=0;i<10000;i++){
        x=fRand(0,99999);
        y=fRand(0,99999);
        z=fRand(0,99999);

        std::cout<<test(x,y,z)<<std::endl;
    }
    

    return 0;
}

