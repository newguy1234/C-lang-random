#include "rpn.h"

#include <string.h>

#include "stack.h"

#include "queue.h"

#include <stdio.h>

#include <ctype.h>

/* convert an infix expression to postfix (rpn) using the */
/* shunting yard algorithm. */
/* return a queue containing the postfix expression. */
/* if an error occurs during evaluation, return silently with NULL. */
int is_operator(char a) {
  if (a == '*' || a == '/' || a == '+' || a == '-' || a == '^') {
    return 1;
  } else {
    return 0;
  }
}

int is_left_associative(char a) {
  if (a == '^') {
    return 0;
  } else {
    return 1;
  }
}

int test_precedence(char a, char b) {
  int num1;
  int num2;
  if (a == '^') {
    num1 = 4;
  }
  if (b == '^') {
    num2 = 4;
  }

  if (a == '*' || a == '/') {
    num1 = 3;
  }
  if (b == '*' || b == '/') {
    num2 = 3;
  }

  if (a == '+' || a == '-') {
    num1 = 2;
  }

  if (b == '+' || b == '-') {
    num2 = 2;
  }

  if (num1 > num2) {
    return 1;
  } else if (num1 < num2) {
    return 0;
  } else if (num1 == num2) {
    return 2;
  } else {
    return 3;
  }
}

Queue * check(Queue * qer) {
    void * p;
    Queue *qe = initialise_queue();
    int d=0;
    char * hes;
    char ass[30];
    while(peek_queue(qer)){
       hes=(char*)pop_queue(qer);
       d=1;
       while(hes[d]){
          if(is_operator(hes[d]) || hes[d]=='('){
           hes[d]='\0';

          }
           d++;
       }
       d=0;
       memcpy(ass," ",30);
      while(hes[d]){
       ass[d]=hes[d];
       d++;
      }

     d=0;
     while(ass[d]){
         if(!(isdigit(ass[d])) && ! is_operator(ass[d]) && ass[d]!='.'){
          ass[d]='\0';
         }
         d++;
     }

      p=&ass;
      push_queue(qe,p,sizeof(p));
}

return qe;
}

Queue * infix_to_postfix(char * expr) {
  int a;
  int cnt;
  Queue * q ;
  Stack * op;
  void * p;
  char wrd[15] = "  ";
  int nr1 = 0;
  int nr2 = 0;
  int i;
  char item;
  char x;
  char * exprr;
  for (i = 0; i < strlen(expr); i++) {
    if (isalpha(expr[i])) {
      return 0;
    }
    if (expr[i] == '(') {
      nr1++;
    }
    if (expr[i] == ')') {
      nr2++;
    }
  }

  if (nr1 != nr2) {
    return 0;
  }
   op = initialise_stack();
   q=initialise_queue();
  exprr = (char * ) malloc((strlen(expr) + 1) * sizeof(char));

  for (i = 0; i < strlen(expr); i++) {
    exprr[i] = expr[i];
  }
  item = '(';
  p = & item;
  push_stack(op, p, sizeof(p));
  strcat(exprr, ")");

  i = 0;
  item = exprr[i];

  while (item != '\0') {
    if (item == '(') {
      p = & item;
      push_stack(op, p, sizeof(p));
    }
    if (is_operator(exprr[i]) && isdigit(exprr[i + 1]) && !(isdigit(exprr[i - 1])) && expr[i - 1] != ')') {
      memcpy(wrd, " ", 9);
      wrd[0] = exprr[i];
      wrd[1] = exprr[i + 1];
      if (isdigit(exprr[i + 2])) {
        wrd[2] = exprr[i + 2];
      }
      if (exprr[i + 2] == '.') {
        a = i + 3;
        cnt = 3;
        wrd[2] = exprr[i + 2];
        while (isdigit(exprr[a])) {
          wrd[cnt] = exprr[a];
          a++;
          cnt++;
        }
        i = a;

      } else if (exprr[i + 3] == '.') {
        a = i + 4;
        cnt = 4;
        wrd[3] = exprr[i + 3];
        while (isdigit(exprr[a])) {
          wrd[cnt] = exprr[a];
          a++;
          cnt++;
        }
        i = a - 1;

      } else {
        i++;
      }
      p = & wrd;
      if(wrd[strlen(wrd)]!='('){
      push_queue(q, p, sizeof(p));
      }
    } else if (isdigit(item)) {
      if (exprr[i + 1] == '.') {
        memcpy(wrd, " ", 9);
        a = i + 2;
        cnt = 2;
        wrd[0] = exprr[i];
        wrd[1] = exprr[i + 1];
        while (isdigit(exprr[a])) {
          wrd[cnt] = exprr[a];
          cnt++;
          a++;
        }
        i = a - 1;
        p = & wrd;
           if(wrd[strlen(wrd)]!='('){
        push_queue(q, p, sizeof(p));
           }
      } else if (isdigit(exprr[i]) && isdigit(exprr[i + 1]) && exprr[i + 2] == '.') {
        memcpy(wrd, " ", 9);
        a = i + 3;
        cnt = 3;
        wrd[0] = exprr[i];
        wrd[1] = exprr[i + 1];
        wrd[2] = exprr[i + 2];
        while (isdigit(exprr[a])) {
          wrd[cnt] = exprr[a];
          cnt++;
          a++;
        }
        i = a - 1;
        p = & wrd;
           if(wrd[strlen(wrd)]!='('){
        push_queue(q, p, sizeof(p));
           }
      } else {
        p = & item;
           if(item!='('){
        push_queue(q, p, sizeof(p));
           }
      }
    } else if (is_operator(item) == 1 && !(isdigit(item))) {
      x = * ((char * ) pop_stack(op));
      while (is_operator(x) == 1 && test_precedence(x, item) >= 1 && x != '(') {
        p = & x;
        if(x!='('){
        push_queue(q, p, sizeof(p));
        }
        x = * ((char * ) pop_stack(op));
      }
      p = & x;
      push_stack(op, p, sizeof(p));

      p = & item;
      push_stack(op, p, sizeof(p));
    } else if (item == ')') {
      x = * ((char * ) pop_stack(op));
      while (x != '(') {
        p = & x;
        if(x!='('){
        push_queue(q, p, sizeof(p));
        }
        x = * ((char * ) pop_stack(op));
      }
    }

    i++;
    item = exprr[i];
  }
free_stack(op);




  return check(q);

  free(exprr);
}
