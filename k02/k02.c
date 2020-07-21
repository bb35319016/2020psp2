#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define myPI (4*atan(1))

extern double p_stdnorm(double z);
double z;
int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;
    double h_a=170.8,h_b=169.7,b_a=pow(5.43,2),b_b=pow(5.5,2);
    double z_a,z_b;
    
    
    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);

        z_a=(val-h_a)/b_a;
        z_b=(val-h_b)/b_b;

       L1=L1*p_stdnorm(z_a);

       L2=L2*p_stdnorm(z_b);


    }




    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",L1);
    printf("L_B: %f\n",L2);

    return 0;


}

double p_stdnorm(double z)
{
    double ret;
    ret=1/sqrt(2*myPI)*exp(-z*z/2);
    return ret;
}

