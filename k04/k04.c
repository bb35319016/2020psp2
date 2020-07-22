#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct data
{
    int ID;
    int gender;
    double heights;
};

int num=15;

int main(void)
{
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int i=0, j=0, k=0, ID, gen, ID2;
    double hei;
    struct data sample[num];

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    printf("the filename of sample: %s\n",fname);

    fp=fopen(fname,"r");
    if(fp==NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    while(fgets(buf,sizeof(buf),fp)!=NULL)
    {
        sscanf(buf,"%d,%lf",&gen,&hei);

        sample[i-1].gender=gen;
        sample[i-1].heights=hei;

        i=i+1;
    }

    if(fclose(fp)==EOF)
    {
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("input the filename of sample ID ?:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1]='\0';
    printf("the filename of sample ID:%s\n",fname);

    fp=fopen(fname,"r");
    if(fp==NULL)
    {
        fputs("File open error\n",stderr );
        exit(EXIT_FAILURE);

    }

    i=0;

    while(fgets(buf,sizeof(buf),fp)!=NULL)
    {
        sscanf(buf,"%d",&ID);

        sample[i].ID=ID;

        i=i+1;
    }

     if(fclose(fp)==EOF)
    {
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

printf("Which ID's date do you want? :");
scanf("%d",&ID2);

while (j<=num)
{
    if(sample[j].ID==ID2)
    {
        if(sample[j].gender==1)
        {
            printf("---\nID : %d\ngender : Male\nheights * %.2lf\n",sample[j].ID,sample[j].heights);
        }
        else
        {
            printf("---\nID : %d\ngender : Female\nheights : %.2f\n",sample[j].ID,sample[j].heights);
        }  
    }
    else
    {
        k=k+1;
    }

    j=j+1;

}

if(k==j)
{
    printf("---\nNO date");
}

return 0;

}