#include <stdio.h>
#define limiteA 3
#define limiteP 3


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

void listaCHEIA (){
  printf("lista cheia!");
}

void invalido (){
  printf("escolha invalida! escolha uma das opções do menu");
}

void menugeral (){
  printf("em que area quer entrar?\n");
  printf("aluno - 1\nprofessor - 2\nsair - 0\n");
}

void menualunos (){
  printf("o que quer fazer nessa area?\n");
  printf("cadastrar - 1\nlistar - 2\nexcluir - 3\nvoltar - 0\n");  
}

int main(){
  int escolha,escolhaA, i, sair=0,sair2=0, limiteD=3, quantA;
  dados aluno[limiteA+1], professor[limiteP+1];

  while(sair!=1){
    menugeral();
    scanf("%d",&escolha);

    switch(escolha){
      case 1:{
        menualunos();
        scanf("%d",&escolhaA);
        while(sair2!=1){
          
          switch(escolhaA){
            
            case 1:
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
            break;
            case 2:{

              printf("vamos listar os alunos cadastrados.\n");
              i=0;

              while(i<3){
                
                printf("o nome do aluno %d é: %s;\n", i+1, aluno[i].nome);

                printf("o numero de matricula do aluno %d é: %d;\n", i+1, aluno[i].matricula);

                printf("o cpf do aluno %d é: %d;\n", i+1, aluno[i].cpf);

                printf("o genero do aluno %d é: %c;\n", i+1, aluno[i].sexo);

                i++;
              }
              break;
            }
            case 3:{
              break;
            }
            case 0:{
              sair2=1;
              break;
            }
            default:{
              invalido();
              break;
            }
            
          }
          
        }
        
        
        break;
      }
      case 2:{
        menualunos();
        scanf("%d",&escolhaA);
        while(sair2!=1){
          
          switch(escolhaA){
            
            case 1:
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
            break;
            case 2:{

              printf("vamos listar os alunos cadastrados.\n");
              i=0;

              while(i<3){
                
                printf("o nome do aluno %d é: %s;\n", i+1, aluno[i].nome);

                printf("o numero de matricula do aluno %d é: %d;\n", i+1, aluno[i].matricula);

                printf("o cpf do aluno %d é: %d;\n", i+1, aluno[i].cpf);

                printf("o genero do aluno %d é: %c;\n", i+1, aluno[i].sexo);

                i++;
        break;
      }
      case 3:{
        break;
      }
      case 0:{
        sair=1;
        break;
      }
      default:{
        invalido();
        break;
      }
      
    }
    
  }
  
}