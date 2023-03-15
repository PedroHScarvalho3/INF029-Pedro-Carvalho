#include <stdio.h>

int soma(int n1, int n2){
  return n1 + n2;
}

int main(){
  int n1,n2, sum;
  printf("digite dois numeros para serem somados");
  scanf("%d",&n1);
  scanf("%d",&n2);

  sum=soma(n1,n2);
  printf("%d", sum);
}