#include <stdio.h>

int troca(int *a, int *b){

    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}

int main(){
  int a, b, aux;
  int *a_ptr;
  int *b_ptr;
  int *aux_ptr;

  
  printf("type the value of a\n");
  scanf("%d", &a);

  printf("type the value of b\n");
  scanf("%d", &b);
  
  //criar ponteiros e inverter o valor de a com b através dos ponteiros
  

  printf("value of a: %d\n", a);
  printf("value of b: %d\n", b);

  troca(&a,&b);

  printf("value of a: %d\n", a);
  printf("value of b: %d\n", b);

  

}

int troca(int *a, int *b);