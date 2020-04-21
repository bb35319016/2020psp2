#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int N);
extern double var_online(double val,double var,double a,int N);

int main(void){

    double a;
    double var;
    double ave;
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int N=0;

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
        N=N+1;
        ave=ave_online(val,ave,N);
        var=var_online(val,var,a,N);
        a=val;

    }
    printf("average:%lf\nvariance:%lf\n",ave,var);
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    return 0;


}

extern double ave_online(double val,double ave,int N){
   ave=(((N-1)*ave)/N)+(val/N);
   return(ave);
}

extern double var_online(double val,double var,double a,int N){
    var=((((N-1)*a*a)/N)+((val*val)/N))-pow((((a*(N-1))/N)+(val/N)),2);
    return(var);
}

