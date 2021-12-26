#include <stdio.h>

#include<string.h>

#include <stdlib.h>


int main(int argc, char * argv[]) {
  int cells;
  int generations;
  int wolfram;
  int count = 0;
  int * cellular;
  int * cellulart;
  int i;
  int tot;
  char *ptr;
  int h;
  if (atoi(argv[3]) < 1 || atoi(argv[2]) < 1 || atoi(argv[1]) < 1 || atoi(argv[3])>255 || argc!=4) {
    printf("err wrong value");
    return 1;
  }
  cells = atoi(argv[1]);
  generations = atoi(argv[2]);
  wolfram = atoi(argv[3]);

  cellular = (int * ) calloc(cells,sizeof(int));
  cellulart = (int * ) calloc(cells,sizeof(int));

  memset(cellular, 0, cells);
  memset(cellulart, 0, cells);
  cellular[(cells / 2)] = 1;

  strtol(argv[1],&ptr,10);
  if((strcmp(ptr,""))!=0){
      printf("ERRR");
      return 1;
  }

  while (count < generations) {
    if (count) {
      for (i = 0; i < cells; i++) {
        tot = 0;

        if (cellular[i]) {
          tot += 2;
        }

        if (i != 0 && i != cells - 1) {
          if (cellular[i - 1]) {
            tot += 4;
          }
          if (cellular[i + 1]) {
            tot++;
          }

        } else if (i == 0) {
          if (cellular[cells - 1]) {
            tot += 4;
          }
          if (cellular[i + 1]) {
            tot++;
          }
        } else {
          if (cellular[i - 1]) {
            tot += 4;
          }
          if (cellular[0]) {
            tot++;
          }
        }

        cellulart[i] = (wolfram >> tot) & 1;
        if (cellulart[i] == 1) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");

      for (i = 0; i < cells; i++) {
        cellular[i] = cellulart[i];
      }

    } else {

      for (i = 0; i < (cells / 2); i++) {
        printf(" ");
      }
      printf("*");
      if(cells%2){
          h=0;
      }else{
       h=1;
      }
      for (i = h; i < ((cells / 2)); i++) {
        printf(" ");
      }
      printf("\n");
    }
    count++;
  }
  free(cellular);
  free(cellulart);
  return 0;
}
