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
  long int cpf;
  int ativo;
  char nome[50];
  char sexo;
  data data;
} dados;



void invalido (){
  printf("*escolha invalida! escolha uma das opções do menu*\n");
}

void menugeral (){
  printf("*em que area quer entrar?*\n");
  printf("aluno - 1\nprofessor - 2\ndisciplina - 3\nsair - 0\n");
}

void menualunos (){
  printf("*o que quer fazer nessa area?*\n");
  printf("cadastrar - 1\nlistar - 2\natualizar - 3\nexcluir - 4\nvoltar - 0\n");  
}

int main(){

  int escolha,escolhaA, i, sair=0,sairA=0, limiteD=3, quantA=0, matricula,achou=0, j;
  dados aluno[limiteA], professor[limiteP];
  int matriculanova, nomenovo, dianovo, mesnovo, anonovo, cpfnovo, sexonovo; 

  while(sair!=1){
    menugeral();
    scanf("%d",&escolha);

    switch (escolha){
      case 0:{
        sair=1;
        break;
      }
      case 1:{
        printf("*menu aluno*\n");
        while(sairA!=1){
          menualunos();
          scanf("%d",&escolhaA);
          switch(escolhaA){
            case 0:{
              sairA=1;
              break;
            }
            case 1:{
              printf("*cadastrar aluno*\n\n");
              for(i=0;i<limiteA;i++){
                
                printf("digite a matricula do aluno %d:\n", i+1);
                scanf("%d",&aluno[i].matricula);
                getchar();
                printf("digite o nome do aluno %d:\n", i+1);
                fgets(aluno[i].nome,50,stdin);
                getchar();
                printf("digite o cpf do aluno %d:\n", i+1);
                scanf("%d",&aluno[i].cpf);
                getchar();
                printf("digite a data de nascimento do aluno %d (no formato dd mm aa):\n", i+1);
                scanf("%d",&aluno[i].data.dia);
                getchar();
                scanf("%d",&aluno[i].data.mes);
                getchar();
                scanf("%d",&aluno[i].data.ano);
                getchar();
                aluno[i].ativo=1;
                quantA++;
                
              }
              break;
            }
            case 2:{
              printf("*listar aluno*\n");
              if(quantA==0){
                printf("*sem cadastros disponiveis*\n");
              }
              else{
                for(i=0;i<quantA;i++){
                  if(aluno[i].ativo){
                    printf("matricula do aluno %d: %d\n", i+1, aluno[i].matricula);
                    printf("nome do aluno %d: %s",i+1, aluno[i].nome);
                    printf("cpf do aluno %d: %d\n", i+1, aluno[i].cpf);
                    printf("data de nascimento do aluno %d: %d/%d/%d\n", i+1, aluno[i].data.dia, aluno[i].data.mes, aluno[i].data.ano);
                  }
                }
              }
              break;
            }
            case 3:{
              printf("*atualizar aluno*\n");
              printf("*digite a matricula do aluno que quer atualizar*:\n");
              scanf("%d",&matricula);
              int achou=0;
              if(matricula<0){
                printf("matricula inválida\n");
              }
              else{
                for(i=0;i<limiteA;i++){
                if(matricula==aluno[i].matricula && aluno[i].ativo){
                  printf("*digite os novos dados\n*");
                  printf("qual será a nova matricula?\n");
                  scanf("%d",&matriculanova);
                  printf("qual será o novo cpf?\n");
                  scanf("%d",&cpfnovo);
                  printf("qual será a nova data de nascimento? (no formato dd mm aa):\n");
                  scanf("%d",&dianovo);
                  scanf("%d",&mesnovo);
                  scanf("%d",&anonovo);
                  aluno[i].matricula=matriculanova;
                  aluno[i].cpf=cpfnovo;
                  aluno[i].data.dia=dianovo;
                  aluno[i].data.mes=mesnovo;
                  aluno[i].data.ano=anonovo;
                  
                  achou=1;
                  break;
                  }
                }
              }
              
              if(achou){
                printf("*aluno atualizado*\n");
              }
              else{
                printf("*matricula inexistente, não pode ser excluida*");
              }
              break;
            }
            case 4:{
              printf("*excluir aluno*\n");
              printf("*digite a matricula do aluno que quer excluir*:\n");
              scanf("%d",&matricula);
              for(i=0;i<limiteA;i++){
                if(matricula==aluno[i].matricula){
                  aluno[i].ativo=-1;
                  for(j=i;j<quantA-1;j++){
                    aluno[j].matricula=aluno[j+1].matricula;
                    aluno[j].cpf=aluno[j+1].cpf;
                    aluno[j].data.dia=aluno[j+1].data.dia;
                    aluno[j].data.mes=aluno[j+1].data.mes;
                    aluno[j].data.ano=aluno[j+1].data.ano;
                    aluno[j].ativo=aluno[j+1].ativo;
                  }
                  quantA--;
                  achou=1;
                  break;
                }
              }
              if(achou){
                printf("*aluno excluido*\n");
              }
              else{
                printf("*matricula inexistente, não pode ser excluida*");
              }
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
        printf("*menu professor*\n");
        break;
      }
      case 3:{
        printf("*menu disciplina*\n");
        break;
      }
      default:{
        invalido();
        break;
      }
    }
  }
}
