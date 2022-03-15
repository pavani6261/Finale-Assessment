#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    FILE *f;
    f = fopen("SourceText.txt","r");
    OpenFile(f);
    char *maxW,*a[100],line[1000],word[1000]="" ;
    int ret;
    while(ret=fscanf(f,"%s",line))
        {
            if(ret==EOF)
            {
                break;
            }
            strcat(word,line);  //strng concatination
            strcat(word,"\n");
        }
    fclose(f);
//    printf("%s",word);

    int i=0,j=0,k,count=0,max=0;
    char w[10]="such"; // word  to searched
    char *tok=strtok(word,"\n ,.\t");  //delimiters are \n , . \t
    while(tok!=NULL)
    {
        a[i]=tok;
        i++;
        tok=strtok(NULL,"\n ,.\t");
    }
    k=i;
//    for(i=0;i<k;i++)
//    {
//        printf("%s\n",a[i]);
//    }
    for(i=0;i<k;i++)
    {
        if(strcmp(a[i],w)==0)   //string comparison
        {
            count++;
        }
    }
    printf("count of %s is %d\n",w,count);
    count = 0;
    for(i=0;i<k;i++)
    {
         for(j=0;j<k;j++)
        {
            if(strcmp(a[i],a[j])==0) //string comparison
            {
                count++;
            }
        }
        if(count>max)
            {
                max=count;
                maxW = a[i];
            }
    }
    printf("%s is repeated maximum",maxW);

}
void OpenFile(FILE *f)
{
    if(f == NULL)
    {
        printf("Failed to create or open file\n");
        exit(0);
    }
}








