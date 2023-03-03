#include <stdio.h>
int main() {
  int i, limite, soma = 0;
  float media;
  printf("digire o limite de alunos: ");
  scanf("%d", &limite);
  int aluno[limite];

  printf("por favor digite as idadese os nomes dos alunos respectivamente.\n");
  for (i = 0; i < limite; i++) {
    scanf("%d", &aluno[i]);
    soma += aluno[i];
  }
  media = soma / limite;
  printf("%f", media);
  for (i = 0; i < limite; i++) {
    if (aluno[i] < media) {
      printf("o aluno com a idade %d está abaixo da média\n", aluno[i]);
    }
    if (aluno[i] > media) {
      printf("o aluno com a idade %d está acima da média\n", aluno[i]);
    }
  }
}