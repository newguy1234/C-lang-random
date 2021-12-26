#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(int argc,char *argv[])
{
  FILE *fp;
  FILE *fp2;
 char text [15];
 char text2 [15];
long double num =0.0;
  long double num1 =0.0;
  double total =0.0;
  int a =0;
    double sd2 =0.0;
 double sd =0.0;
int *ok;

if(argc>3){
    printf("ERR");
 return 1;
}


 if(!(fp = fopen(argv[1] , "r"))) {
 printf("error opening %s\n", argv[1] );
 return 1;
 }
 num=-1;

memset(text,' ',15);

  fgets(text,15,fp);
while(fscanf(fp , "%s", text)!= EOF){
num++;
}

 if(!(fp2 = fopen(argv[2] , "r"))) {
 printf("error opening %s\n", argv[2] );
 return 1;
 }
 num1=-1;
while(fscanf(fp2 , "%s", text2)!= EOF){
    if(num1>-1){;
a=strlen(text2);
text2[2]='a';
text2[1]=text2[a-1];
text2[0]=text2[a-2];
if(text2[0]== ','){
    text2[0]=text2[a-1];
text2[1]='a';
}
if(text2[a-3]=='1' &&text2[a-2]=='0'&& text2[a-1]=='0'){
    text2[3]='a';
    text2[2]=text2[a-1];
    text2[1]=text2[a-2];
text2[0]=text2[a-3];
}

sd+=atoi(text2);
sd2+=atoi(text2)*atoi(text2);
total+= atoi(text2);
    }
num1++;
}
total=total/(num);

sd=(sd2/num)-((sd/num)*(sd/num));
sd=sqrt(sd);

printf("total students = %0.Lf\n",num);
printf("absent students = %0.0Lf\n", (num-num1));
num1=0;
num=0;
printf("grade mean = %0.2f\n",total);
total=0;
printf("grade sd = %0.2f\n",sd);

ok=(int*)malloc(10*sizeof(int));
ok[1]=1;
total=ok[1];

free(ok);
fclose(fp);
fclose(fp2);
return 0;
}
