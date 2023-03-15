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

int main(){

  int i, limiteA, limiteP, escolha1, escolha2, d;
  dados aluno[limiteA], professor[limiteP];

  printf("quantos alunos existem?\n");
  scanf("%d",&limiteA);

  while(escolha1==0){
    
    
    printf("em que area quer entrar?\n");
    printf("aluno - 1\nprofessor - 2\nsair - 0\n");
    scanf("%d",&escolha1);

      
      if((escolha1<0)||(escolha1>2)){
        printf("escolha invalida! escolha uma das opcoes disponibilizadas no menu.\n");
        escolha1=0;
      }
      if(escolha1==1){
        while(escolha2==0){
          printf("o que quer fazer nessa area?\n");
          printf("cadastrar - 1\nlistar - 2\nexcluir - 3\nvoltar - 0\n");
          scanf("%d",&escolha2);
            
          if((escolha2<0)||(escolha2>3)){
          printf("escolha invalida! escolha uma das opcoes disponibilizadas no menu.\n");
          escolha2=0;
          }
          if(escolha2==1){
              
            for(i=0;i<limiteA;i++){
                
              printf("digite o numero de matricula do aluno %d\n", i+1);
              scanf("%d",& aluno[i].matricula);
              printf("digite o nome do aluno %d\n", i+1);
  
              printf("digite a data de nascimento do aluno %d (no formato dd mm aa)\n", i+1);
              scanf("%d",&aluno[i].data.dia);
              scanf("%d",&aluno[i].data.mes);
              scanf("%d",&aluno[i].data.ano);
              printf("digite o cpf do aluno %d\n",i+1);
              scanf("%d",&aluno[i].cpf);
            }
            escolha2=0;
          }
          if(escolha2==2){
            printf("vamos listar os alunos cadastrados:\n");
            for(i=0;i<limiteA;i++){
              printf("");
              printf("matricula do aluno %d: %d\n",i+1, aluno[i].matricula);
              printf("cpf do aluno %d: %d\n",i+1, aluno[i].cpf);
              printf("dia do nascimento do aluno %d: %d\n",i+1, aluno[i].data.dia);
              printf("dia do mes do aluno %d: %d \n",i+1, aluno[i].data.mes);
              printf("dia do ano do aluno %d: %d \n",i+1, aluno[i].data.ano);
            }
              
          }
          if(escolha2==0){
            escolha1=0;
            escolha2++;
              
          }
          
        }  
        
          
      
      }
      if(escolha1==2){
        printf("o que quer fazer nessa area?\n");
        printf("cadastrar - 1\nlistar - 2\nexcluir - 3\nvoltar - 0\n");
        scanf("%d",&escolha2);
      }
  }
}
