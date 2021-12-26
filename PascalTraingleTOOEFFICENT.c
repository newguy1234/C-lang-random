#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
   int rows = atoi(argv[1]);
   int i;
   int j;
   unsigned long int number = 1;
   if(rows>20 || rows <1 || argv[2]){
       return 1;
   }
   for(i= 0; i < rows; i++){
       for(j=0; j<rows-i; j++){
           if(j>0){
               number = number*(rows-j-i)/(j);
           }
       printf("%lu",number);
        printf(" ");
       }
       number =1;
       printf("\n");
   }
    return 0;
}
