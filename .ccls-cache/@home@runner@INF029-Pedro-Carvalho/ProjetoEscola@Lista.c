#include <stdio.h>
typedef struct birth{
    int dia;
    int mes;
    int ano;
  } data;

typedef struct ficha_pessoas{
    int matricula;
    char nome[50];
    char sexo;
    data data;
    int cpf;
  } dados;
int main(){
  int limite,limiteP, i, escolha,escolha2, d;
  dados aluno[limite];

  while(escolha==0){
    printf("em que area quer entrar?:\n");
    printf("Aluno - 1\nprofessor - 2\nsair - 0\n");

    scanf("%d",&escolha);
  
      
      if(escolha==1){  
        printf("o que quer fazer nessa area:\n");
        printf("cadastrar - 1\n listar - 2\n excluir - 3\n voltar - 0");
        scanf("%d",&escolha);
          
          if(escolha2==1){
            printf("quantos alunos existem???????\n");
            scanf("%d",&limite);
            
    
            for(i=0;i<limite;i++){
            printf("digite o número de matricula do(a) aluno(a) %d:\n", i+1);
            scanf("%d",&aluno[i].matricula);
            printf("digite o nome do(a) aluno(a) %d:\n", i+1);
            scanf("%s", &aluno[i].nome);
            printf("digite o sexo biológico do(a) aluno(a) %d (m=macho/f=femea)",i+1);
            scanf("%c",&aluno[i].sexo);
            
            printf("qual a data de nascimento do(a) aluno(a) %d? *dia/mes/ano*\n", i+1);
            scanf("%d",&aluno[i].data.dia);
            scanf("%d",&aluno[i].data.mes);
            scanf("%d",&aluno[i].data.ano);
            }
          }
        
      }
    
  
      if(escolha==2){
        printf("quantos professores existem?\n");
        scanf("%d",&limiteP);
        dados professor[limite];
  
        for(i=0;i<limite;i++){
        printf("digite o número de matricula do(a) professor(a) %d:\n", i+1);
        scanf("%d",& aluno[i].matricula);
        printf("digite o nome do(a) professor(a) %d:\n", i+1);
        scanf("%s", & aluno[i].nome);
        printf("digite o sexo biológico do(a) professor(a) %d (m=macho/f=femea)",i+1);
        scanf("%c",& aluno[i].sexo);
        
        printf("qual a data de nascimento do(a) professor(a) %d? *dia/mes/ano*\n", i+1);
        scanf("%d",&aluno[i].data.dia);
        scanf("%d",&aluno[i].data.mes);
        scanf("%d",&aluno[i].data.ano);

      
      
        }    
  
  
  
    
    
  
      }
  }
}