#include<stdio.h>
#include <ctype.h>

#define MAXVAL 100

int getch(void);
void ungetch(int);
int getdouble(int *pn);

int sp = 0; 
double val[MAXVAL]; 
char buf = '\0'; /* buffer for ungetch */

int main(void){

    /*Test code here*/

    return 0;
}


/* getint: get next double from input into *pn */
int getdouble(int *pn){
    int c, sign;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){

        if(!isdigit(c = getch())){
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    if (c == '.'){
        int i;
        for (i = 1; (c = getch()) && isdigit(c); ++i){
            *pn += (c - '0') / (pow(10, i));
        }
  }
    
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
        
    return c;

}

int getch(void){
    return (buf != '\0') ? buf : getchar();
}

void ungetch(int c){
    if(buf != '\0')
        buf = c;
    else
        printf("\tBuffer is full.\n");
}    