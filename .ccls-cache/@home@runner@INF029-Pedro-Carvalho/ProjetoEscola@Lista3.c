#include <stdio.h>

typedef struct birth{
  int dia;
  int mes;
  int ano;
} data;

typedef struct ficha_pessoa{
  int matricula;
  int cpf;
  char nome[50];
  char sexo;
  data data;
} dados;



void menuGeral(){
  printf("em que area quer entrar?\n");
  printf("aluno - 1\nprofessor - 2\nsair - 0\n");
}
void menuAlunos(){
  printf("o que quer fazer nessa area?\n");
  printf("cadastrar - 1\nlistar - 2\nexcluir - 3\nvoltar - 0\n");
}

int main(){
  int i, limiteA, limiteP, escolha1=0, escolha2=1, d;
  dados aluno[limiteA], professor[limiteP];
  printf("quantos alunos existem?\n");
  scanf("%d",&limiteA);
  printf("quantos professores existem?\n");
  scanf("%d",&limiteP);

  
  while(escolha1==0){
    printf("====================\n====================\n");
    
    menuGeral();
    scanf("%d",&escolha1);
    switch(escolha1){
      case 1:
        
        while(escolha2!=0){
          printf("====================\n====================\n");
          menuAlunos();
          scanf("%d",&escolha2);
          
          
          switch(escolha2){
            case 1:
              printf("====================\n====================\n");
              for(i=0;i<limiteA;i++){
                
              printf("digite o numero de matricula do aluno %d\n", i+1);
              scanf("%d",& aluno[i].matricula);
              printf("digite o nome do aluno %d\n", i+1);
              fgets(aluno[i].nome,20,stdin);
              printf("digite a data de nascimento do aluno %d (no formato dd mm aa)\n", i+1);
              scanf("%d",&aluno[i].data.dia);
              scanf("%d",&aluno[i].data.mes);
              scanf("%d",&aluno[i].data.ano);
              printf("digite o cpf do aluno %d\n",i+1);
              scanf("%d",&aluno[i].cpf);
              }
              escolha2=1;
              break;
            case 2:
              printf("vamos listar os alunos cadastrados:\n");
            for(i=0;i<limiteA;i++){
              printf("nome do aluno %d: %s\n", i+1, aluno[i].nome);
              printf("genero do aluno %d: %c\n", i+1, aluno[i].sexo);
              printf("matricula do aluno %d: %d\n",i+1, aluno[i].matricula);
              printf("cpf do aluno %d: %d\n",i+1, aluno[i].cpf);
              printf("dia do nascimento do aluno %d: %d\n",i+1, aluno[i].data.dia);
              printf("dia do mes do aluno %d: %d \n",i+1, aluno[i].data.mes);
              printf("dia do ano do aluno %d: %d \n",i+1, aluno[i].data.ano);
              }
              escolha2=1;
              break;
            case 3:
              break;
            case 0:
              escolha2=0;
              break;
            default:
              printf("escolha invalida! escolha uma das opcoes do menu.");
              escolha2=1;
              break;
          }
        }
        escolha1=0;
        break;
      case 2:
        break;
      case 0:
        escolha1++;
        break;
      default:
        break;
    }
  }
}