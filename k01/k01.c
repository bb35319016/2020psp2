#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int N);
extern double var_online(double val,double var,double ave,double ave2,int N);

int main(void){

    double ave2=0;
    double var=0;
    double ave=0;
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
    N++;
        var=var_online(val,var,ave,ave2,N);
        ave=ave_online(val,ave,N);
        ave2=ave_online(pow(val,2),ave2,N);
        
    }
    printf("average:%lf\nvariance:%lf\nsuitei average:%lf\nsuitei variance%lf\n",ave,var,ave,(N*var)/(N-1));
    
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


    return 0;


}

extern double ave_online(double val,double ave,int N){
   ave=((N-1)*ave)/N+val/N;
   return ave;
}

extern double var_online(double val,double var,double ave,double ave2,int N){
    var=((N-1)*ave2)/N+pow(val,2)/N-pow(((N-1)*ave)/N+val/N,2);
    return var;
}

