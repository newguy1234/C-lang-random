#include <stdio.h>
#include<stdlib.h>
#include<string.h>
float drake_equations(float n[]);

int main() {
    /* dynamicall alocation of strin*/
    float auto *n = (float*)malloc(8*sizeof(float));
    /*memcpy(n, (float [8]){1.0,1.0,0.2,1.0,1.0,1.0,0.1,1000}, 8*sizeof(float));this command dosen't work in older versions of C*/

    /*set 1 */
    n[0] =1.0 ;
    n[1] =1.0;
    n[2] =0.2;
    n[3] = 1.0;
    n[4] = 1.0;
    n[5] = 1.0;
    n[6] = 0.1;
    n[7] = 1000;

    n[0]=drake_equations(n);
printf ("N=%0.0f R*=%0.1f fp=%0.1f ne=%0.0f fl=%0.1f fi=%0.1f fc=%0.1f L=%0.0f\n" , n[0] ,n[1],n[2],n[3],n[4],n[5],n[6],n[7]);
  memset(n, 0, 8);

     n[0] =1.0 ;
    n[1] =1.0;
    n[2] =0.5;
    n[3] = 5;
    n[4] = 1.0;
    n[5] = 1.0;
    n[6] = 0.2;
    n[7] = 1000000000;
 /*set 2 */
/*memcpy(n, (float [8]){1.0,1.0,0.5,5,1.0,1.0,0.2,1000000000}, 8*sizeof(float)); this command dosen't work in older versions of C*/
n[0]=drake_equations(n);
printf ("N=%0.0f R*=%0.1f fp=%0.1f ne=%0.0f fl=%0.1f fi=%0.1f fc=%0.1f L=%0.0f\n" , n[0] ,n[1],n[2],n[3],n[4],n[5],n[6],n[7]);
memset(n, 0,8);

n[0] =1.0 ;
    n[1] =1.5;
    n[2] =1.0;
    n[3] = 3;
    n[4] = 1.0;
    n[5] = 0.0001;
    n[6] = 0.001;
    n[7] = 304;
 /*set 3*/
 /*memcpy(n, (float [8]){1.0,1.5,1.0,3,1.0,0.0001,0.001,304}, 8*sizeof(float)); this command dosen't work in older versions of C*/
n[0]=drake_equations(n);
printf ("N=%0.0f R*=%0.1f fp=%0.1f ne=%0.0f fl=%0.1f fi=%0.1f fc=%0.1f L=%0.0f\n" , n[0] ,n[1],n[2],n[3],n[4],n[5],n[6],n[7]);
memset(n, 0,8);

n[0] =1.0 ;
    n[1] =3;
    n[2] =1.0;
    n[3] = 5;
    n[4] = 1.0;
    n[5] = 1;
    n[6] = 0.1;
    n[7] = 10000000;
/*set 4 */
/*memcpy(n, (float [8]){1.0 , 3.0 , 1.0 , 5 , 1.0 , 1.0 , 0.1 , 10000000}, 8*sizeof(float)); this command dosen't work in older versions of C*/
n[0]=drake_equations(n);
printf ("N=%0.0f R*=%0.1f fp=%0.1f ne=%0.0f fl=%0.1f fi=%0.1f fc=%0.1f L=%0.0f\n" , n[0] ,n[1],n[2],n[3],n[4],n[5],n[6],n[7]);
memset(n, 0, 8);


free(n);
    return 0;
}
/*takes in array and multiplies everything together*/
float drake_equations(float n[]){
    int i;
    for(i=1; i<8;i++){
    n[0]*= n[i];
}

    return n[0];
}
