#include <stdio.h>

typedef struct ficha_pessoas{
    int matricula;
    char nome[50];
    char sexo;
    int data[3];
    int cpf;
  } dados;
int main(){
  int limite, i;
  printf("quantos alunos existem???????\n");
  scanf("%d",&limite);
  dados aluno[limite];

  for(i=0;i<limite;i++){
    printf("digite o número de matricula do aluno %d:\n", i+1);
    scanf("%d",&aluno[i].matricula);
    printf("digite o nome do aluno %d:\n", i+1);
    scanf("%s", &aluno[i].nome);
    printf("digite o sexo biológico do aluno %d: (m=macho/f=fêmea)\n", i+1);
    scanf("%c",&aluno[i].sexo);
      if((aluno[i].sexo=='m')||(aluno[i].sexo=='f')){
        
      }
    
    
  }
  
    
    
  
}