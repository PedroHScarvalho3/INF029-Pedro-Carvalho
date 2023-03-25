#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define limiteA 3
#define limiteP 3
#define limiteD 3
#define CAD_SUCESSO -1
#define MATRICULA_INVALIDA -2

typedef struct birth {
  int dia;
  int mes;
  int ano;
} data;

typedef struct ficha_pessoa {
  int matricula;
  int cpf;
  int ativo;
  char nome[50];
  char sexo;
  data data;
} dados;

typedef struct disciplina {
  char nome[20];
  int code;
  int semestre;
  dados aluno[limiteA];
  dados professor[limiteP];
  int ativo;
  int quantAD;
  int quantPD;
  int alunoscadastrados;
} dis;

dados aluno[limiteA];
  dados professor[limiteP];
  dados copia;
  dados copiaP;
  int quantA = limiteA;
  char sexo;



void cadastroalunos();
void invalido();
void menulistas();
void menugeral();

void menualunos();
void menuprof();
void menudisc();



int main() {
  dados aluno[limiteA];
  dados professor[limiteP];
  dados copia;
  dados copiaP;
  int quantA = limiteA;


  
  int escolha, escolhaA, escolhaD, escolhaP, i,
      sair = 0, sairA = 0, sairP = 0, sairD = 0,quantP = limiteP,
      quantD = limiteD, matricula, code, achou = 0, j, k, mes = 0, mescount = 0, cont;
  dis dis[limiteD];
  int matriculanova, dianovo, mesnovo, anonovo, cpfnovo, sexonovo, codenovo,
      semestrenovo;
  char nomenovo[50], nomedisnovo[20], sexo, escolhaS, str[50];

  while (sair != 1) {
    menugeral();
    scanf("%d", &escolha);
    
    sairA = 0;
    sairD = 0;
    sairP = 0;

    switch (escolha) {
    case 0: {
      sair = 1;
      break;
    }
    case 1: {
      printf("*menu aluno*\n");
      while (sairA != 1) {
        menualunos();
        scanf("%d", &escolhaA);
        getchar();
        switch (escolhaA) {
        case 0: {
          sairA = 1;
          break;
        }
        case 1: {
          cadastroalunos();
          }
          
          break;
        }
        case 2: {
          printf("*listar aluno*\n");
          if (quantA == 0) {
            printf("*sem cadastros disponiveis*\n");
          } else {
            for (i = 0; i < quantA; i++) {
              if (aluno[i].ativo) {
                printf("matricula do aluno %d: %d\n", i + 1,
                       aluno[i].matricula);
                printf("nome do aluno %d: %s", i + 1, aluno[i].nome);
                printf("cpf do aluno %d: %d\n", i + 1, aluno[i].cpf);
                printf("sexo do aluno %d: %c\n", i + 1, aluno[i].sexo);
                printf("data de nascimento do aluno %d: %d/%d/%d\n", i + 1,
                       aluno[i].data.dia, aluno[i].data.mes, aluno[i].data.ano);
                printf("\n");
              }
            }
            for (i = 0; i < quantA; i++) {
            }
          }

          break;
        }
        case 3: {
          printf("*atualizar aluno*\n");
          printf("*digite a matricula do aluno que quer atualizar*:\n");
          scanf("%d", &matricula);
          int achou = 0;
          if (matricula < 0) {
            printf("matricula inválida\n");
          } else {
            for (i = 0; i < limiteA; i++) {
              if (matricula == aluno[i].matricula && aluno[i].ativo) {
                printf("*digite os novos dados\n*");
                printf("qual será a nova matricula?\n");
                scanf("%d", &matriculanova);
                getchar();
                printf("qual será o novo nome?");
                fgets(nomenovo, 50, stdin);
                getchar();
                printf("qual será o novo cpf?\n");
                scanf("%d", &cpfnovo);
                getchar();
                printf("qual será a nova data de nascimento? (no formato dd mm "
                       "aa):\n");
                scanf("%d", &dianovo);
                getchar();
                scanf("%d", &mesnovo);
                getchar();
                scanf("%d", &anonovo);
                getchar();
                aluno[i].matricula = matriculanova;
                strcpy(aluno[i].nome, nomenovo);
                getchar();
                aluno[i].cpf = cpfnovo;
                aluno[i].data.dia = dianovo;
                aluno[i].data.mes = mesnovo;
                aluno[i].data.ano = anonovo;

                achou = 1;
                break;
              }
            }
          }

          if (achou) {
            printf("*aluno atualizado*\n");
          } else {
            printf("*matricula inexistente, não pode ser excluida*");
          }
          break;
        }
        case 4: {
          printf("*excluir aluno*\n");
          printf("*digite a matricula do aluno que quer excluir*:\n");
          scanf("%d", &matricula);
          for (i = 0; i < limiteA; i++) {
            if (matricula == aluno[i].matricula) {
              aluno[i].ativo = -1;
              for (j = i; j < quantA - 1; j++) {
                aluno[j].matricula = aluno[j + 1].matricula;
                strcpy(aluno[j].nome, aluno[j + 1].nome);
                aluno[j].cpf = aluno[j + 1].cpf;
                aluno[j].data.dia = aluno[j + 1].data.dia;
                aluno[j].data.mes = aluno[j + 1].data.mes;
                aluno[j].data.ano = aluno[j + 1].data.ano;
                aluno[j].ativo = aluno[j + 1].ativo;
              }
              quantA--;
              achou = 1;
              break;
            }
          }
          if (achou) {
            printf("*aluno excluido*\n");
          } else {
            printf("*matricula inexistente, não pode ser excluida*");
          }
          break;
        }
        case 5: {
          printf("*aniversáriantes do mês*\n");
          if (quantA == 0) {
            printf("*sem cadastros disponiveis*\n");
          } else {
            printf("digite em que mês estamos(1-12):\n");
            scanf("%d", &mes);
            getchar();
            if ((mes < 0) || (mes > 12)) {
              printf("mes inválido");
            } else {
              printf("alunos do mês:\n");
              for (i = 0; i < quantA; i++) {
                if (aluno[i].data.mes == mes) {
                  printf("%d: %s\n", i + 1, aluno[i].nome);
                  mescount++;
                }
              }
              if (mescount <= 0) {
                printf("nenhum aluno faz aniversário esse mês\n");
              }
            }
          }

          break;
        }
        case 6: {
          printf("*listagem de alunos por nome*\n");
          for (j = 0; j < quantA; j++) {
            for (i = quantA; i > 0; i--) {
              copia = aluno[i - 1];
              if (strcmp(copia.nome, aluno[i].nome) > 0) {
                aluno[i - 1] = aluno[i];
                aluno[i] = copia;
              }
            }
          }
          for (i = 0; i < quantA; i++) {
            if (aluno[i].ativo) {
              printf("matricula do aluno %d: %d\n", i + 1, aluno[i].matricula);
              printf("nome do aluno %d: %s", i + 1, aluno[i].nome);
              printf("cpf do aluno %d: %d\n", i + 1, aluno[i].cpf);
              printf("sexo do aluno %d: %c\n", i + 1, aluno[i].sexo);
              printf("data de nascimento do aluno %d: %d/%d/%d\n", i + 1,
                     aluno[i].data.dia, aluno[i].data.mes, aluno[i].data.ano);
              printf("\n");
            }
          }
          break;
        }
        case 7: {
          printf("*listagem por sexo*\n");
          printf("qual sexo voce quer listar?(m=masculino/f=feminino)\n");
          scanf("%c", &escolhaS);
          if (escolhaS == 'm') {
            printf("*lista dos masculinos*\n");
            for (i = 0; i < quantA; i++) {
              if (aluno[i].sexo == escolhaS) {
                printf("aluno %d: %s\n", i + 1, aluno[i].nome);
              }
            }
          }
          if (escolhaS == 'f') {
            printf("*lista dos femininos*\n");
            for (i = 0; i < quantA; i++) {
              if (aluno[i].sexo == escolhaS) {
                printf("aluna %d: %s\n", i + 1, aluno[i].nome);
              }
            }
          }
          break;
        }
        case 8: {
          printf("*buscar aluno*\n");
          printf("digite o que quer procurar\n");
          fgets(str, 50, stdin);
          getchar();
          for (i = 0; i < quantA; i++) {
            cont = 0;
            for (j = 0; j < strlen(aluno[i].nome); j++) {
              for (k = 0; k < strlen(str); k++) {
                setbuf(stdin, 0);
                if (str[k] == aluno[i].nome[j]) {
                  cont++;
                  break;
                }
              }
            }
            if (cont > 2) {
              printf("- %s\n", aluno[i].nome);
            }
          }
          break;
        }
        case 9: {
          printf("*listagem de alunos por data de nascimento*\n");
          for (i = 0; i < quantA - 1; i++) {
            if (aluno[i].data.ano > aluno[i + 1].data.ano) {
              copia = aluno[i];
              aluno[i] = aluno[i + 1];
              aluno[i + 1] = copia;
            } else if (aluno[i].data.mes > aluno[i + 1].data.mes) {
              copia = aluno[i];
              aluno[i] = aluno[i + 1];
              aluno[i + 1] = copia;
            } else if (aluno[i].data.dia > aluno[i + 1].data.dia) {
              copia = aluno[i];
              aluno[i] = aluno[i + 1];
              aluno[i + 1] = copia;
            }
          }
          for (i = 0; i < quantA; i++) {
            if (aluno[i].ativo) {
              printf("matricula do aluno %d: %d\n", i + 1, aluno[i].matricula);
              printf("nome do aluno %d: %s", i + 1, aluno[i].nome);
              printf("cpf do aluno %d: %d\n", i + 1, aluno[i].cpf);
              printf("sexo do aluno %d: %c\n", i + 1, aluno[i].sexo);
              printf("data de nascimento do aluno %d: %d/%d/%d\n", i + 1,
                     aluno[i].data.dia, aluno[i].data.mes, aluno[i].data.ano);
              printf("\n");
            }
          }
          break;
        }
        default: {
          invalido();
          break;
        }
        }
      break;
      }
      case 2: {
      printf("*menu professor*\n");
      while (sairP != 1) {
        menuprof();
        scanf("%d", &escolhaP);
        getchar();
        switch (escolhaP) {
        case 0: {
          sairP = 1;
          break;
        }
        case 1: {
          printf("*cadastrar professor*\n\n");
          for (i = 0; i < limiteP; i++) {

            printf("digite a matricula do professor %d:\n", i + 1);
            scanf("%d", &professor[i].matricula);
            getchar();
            printf("digite o nome do professor %d:\n", i + 1);
            fgets(professor[i].nome, 50, stdin);
            getchar();
            printf("digite o cpf do professor %d:\n", i + 1);
            scanf("%d", &professor[i].cpf);
            getchar();
            printf("digite o sexo do professor %d(m=masculino/f=feminino):\n",
                   i + 1);
            scanf("%c", &sexo);
            getchar();
            if ((sexo == 'm') || (sexo == 'f')) {
              professor[i].sexo = sexo;
            } else {
              printf("sexo invalido!");
            }
            printf(
                "digite a data de nascimento do professor %d (no formato dd mm "
                "aa):\n",
                i + 1);
            scanf("%d", &professor[i].data.dia);
            getchar();
            scanf("%d", &professor[i].data.mes);
            getchar();
            scanf("%d", &professor[i].data.ano);
            getchar();
            professor[i].ativo = 1;
            quantP++;
          }
          break;
        }
        case 2: {
          printf("*listar professor*\n");
          if (quantP == 0) {
            printf("*sem cadastros disponiveis*\n");
          } else {
            for (i = 0; i < quantP; i++) {
              if (professor[i].ativo) {
                printf("matricula do professor %d: %d\n", i + 1,
                       professor[i].matricula);
                printf("nome do professor %d: %s", i + 1, professor[i].nome);
                printf("cpf do professor %d: %d\n", i + 1, professor[i].cpf);
                printf("sexo do professor %d: %c\n", i + 1, professor[i].sexo);
                printf("data de nascimento do professor %d: %d/%d/%d\n", i + 1,
                       professor[i].data.dia, professor[i].data.mes,
                       professor[i].data.ano);
                printf("\n");
              }
            }
            for (i = 0; i < quantP; i++) {
            }
          }

          break;
        }
        case 3: {
          printf("*atualizar professor*\n");
          printf("*digite a matricula do professor que quer atualizar*:\n");
          scanf("%d", &matricula);
          int achou = 0;
          if (matricula < 0) {
            printf("matricula inválida\n");
          } else {
            for (i = 0; i < limiteP; i++) {
              if (matricula == professor[i].matricula && professor[i].ativo) {
                printf("*digite os novos dados\n*");
                printf("qual será a nova matricula?\n");
                scanf("%d", &matriculanova);
                getchar();
                printf("qual será o novo nome?");
                fgets(nomenovo, 50, stdin);
                getchar();
                printf("qual será o novo cpf?\n");
                scanf("%d", &cpfnovo);
                getchar();
                printf("qual será a nova data de nascimento? (no formato dd mm "
                       "aa):\n");
                scanf("%d", &dianovo);
                getchar();
                scanf("%d", &mesnovo);
                getchar();
                scanf("%d", &anonovo);
                getchar();
                professor[i].matricula = matriculanova;
                strcpy(professor[i].nome, nomenovo);
                getchar();
                professor[i].cpf = cpfnovo;
                professor[i].data.dia = dianovo;
                professor[i].data.mes = mesnovo;
                professor[i].data.ano = anonovo;

                achou = 1;
                break;
              }
            }
          }

          if (achou) {
            printf("*professor atualizado*\n");
          } else {
            printf("*matricula inexistente, não pode ser excluida*");
          }
          break;
        }
        case 4: {
          printf("*excluirprofessor*\n");
          printf("*digite a matricula do professor que quer excluir*:\n");
          scanf("%d", &matricula);
          for (i = 0; i < limiteP; i++) {
            if (matricula == professor[i].matricula) {
              professor[i].ativo = -1;
              for (j = i; j < quantP - 1; j++) {
                professor[j].matricula = professor[j + 1].matricula;
                strcpy(professor[j].nome, professor[j + 1].nome);
                professor[j].cpf = professor[j + 1].cpf;
                professor[j].data.dia = professor[j + 1].data.dia;
                professor[j].data.mes = professor[j + 1].data.mes;
                professor[j].data.ano = professor[j + 1].data.ano;
                professor[j].ativo = professor[j + 1].ativo;
              }
              quantP--;
              achou = 1;
              break;
            }
          }
          if (achou) {
            printf("*professor excluido*\n");
          } else {
            printf("*matricula inexistente, não pode ser excluida*");
          }
          break;
        }
        case 5: {
          printf("*aniversáriantes do mês*\n");
          if (quantP == 0) {
            printf("*sem cadastros disponiveis*\n");
          } else {
            printf("digite em que mês estamos(1-12):\n");
            scanf("%d", &mes);
            getchar();
            if ((mes < 0) || (mes > 12)) {
              printf("mes inválido");
            } else {
              printf("professores do mês:\n");
              for (i = 0; i < quantP; i++) {
                if (professor[i].data.mes == mes) {
                  printf("%d: %s\n", i + 1, professor[i].nome);
                  mescount++;
                }
              }
              if (mescount <= 0) {
                printf("nenhum professor faz aniversário esse mês\n");
              }
            }
          }

          break;
        }
        case 6: {
          printf("*listagem de professor por nome*\n");
          for (j = 0; j < quantP; j++) {
            for (i = quantP; i > 0; i--) {
              copiaP = professor[i - 1];
              if (strcmp(copiaP.nome, professor[i].nome) > 0) {
                professor[i - 1] = professor[i];
                professor[i] = copiaP;
              }
            }
          }
          for (i = 0; i < quantP; i++) {
            if (professor[i].ativo) {
              printf("matricula do professor %d: %d\n", i + 1,
                     professor[i].matricula);
              printf("nome do professor %d: %s", i + 1, professor[i].nome);
              printf("cpf do professor %d: %d\n", i + 1, professor[i].cpf);
              printf("sexo do professor %d: %c\n", i + 1, professor[i].sexo);
              printf("data de nascimento do professor %d: %d/%d/%d\n", i + 1,
                     professor[i].data.dia, professor[i].data.mes,
                     professor[i].data.ano);
              printf("\n");
            }
          }
          break;
        }
        case 7: {
          printf("*listagem por sexo*\n");
          printf("qual sexo voce quer listar?(m=masculino/f=feminino)\n");
          scanf("%c", &escolhaS);
          if (escolhaS == 'm') {
            printf("*lista dos masculinos*\n");
            for (i = 0; i < quantP; i++) {
              if (professor[i].sexo == escolhaS) {
                printf("professor %d: %s\n", i + 1, professor[i].nome);
              }
            }
          }
          if (escolhaS == 'f') {
            printf("*lista dos femininos*\n");
            for (i = 0; i < quantP; i++) {
              if (professor[i].sexo == escolhaS) {
                printf("professora %d: %s\n", i + 1, professor[i].nome);
              }
            }
          }
          break;
        }
        case 8: {
          printf("*buscar professor*\n");
          printf("digite o que quer procurar\n");
          fgets(str, 50, stdin);
          getchar();
          for (i = 0; i < quantP; i++) {
            cont = 0;
            for (j = 0; j < strlen(professor[i].nome); j++) {
              for (k = 0; k < strlen(str); k++) {
                setbuf(stdin, 0);
                if (str[k] == professor[i].nome[j]) {
                  cont++;
                  break;
                }
              }
            }
            if (cont > 2) {
              printf("- %s\n", professor[i].nome);
            }
          }
          break;
        }
        default: {
          invalido();
          break;
        }
        }
      }
      break;
    }
    case 3: {
      printf("*menu disciplina*\n");
      while (sairD != 1) {
        menudisc();
        scanf("%d", &escolhaD);
        switch (escolhaD) {
        case 0: {
          sairD = 1;
          break;
        }
        case 1: {
          printf("*cadastrar disciplina*\n");
          for (i = 0; i < limiteD; i++) {

            printf("digite o codigo da disciplina %d:\n", i + 1);
            scanf("%d", &dis[i].code);
            getchar();
            printf("digite o nome da disciplina %d:\n", i + 1);
            fgets(dis[i].nome, 20, stdin);
            getchar();
            printf("digite o semestre da disciplina %d:\n", i + 1);
            scanf("%d", &dis[i].semestre);
            getchar();
            dis[i].ativo = 1;
            dis[i].alunoscadastrados = 0;
            quantD++;
          }
          break;
        }
        case 2: {
          printf("*listar disciplina*\n");
          if (quantD == 0) {
            printf("*sem disciplinas disponiveis*\n");
          } else {
            for (i = 0; i < quantD; i++) {
              if (dis[i].ativo) {
                printf("codigo da disciplina %d: %d\n", i + 1, dis[i].code);
                printf("nome da disciplina %d: %s\n", i + 1, dis[i].nome);
                printf("semestre da disciplina %d: %d \n", i + 1,
                       dis[i].semestre);
                for (j = 0; j < dis[i].quantAD; j++) {
                  if (dis[i].aluno[j].ativo != 0) {
                    printf("aluno %d: %s\n", j + 1, dis[i].aluno[j].nome);
                  }
                }
                for (j = 0; j < dis[i].quantPD; j++) {
                  if (dis[i].professor[j].ativo != 0) {
                    printf("professor %d: %s\n", j + 1,
                           dis[i].professor[j].nome);
                  }
                }
                printf("\n");
              }
            }
          }
          break;
        }
        case 3: {
          printf("*atualizar disciplina*\n");
          printf("*digite o codigo da disciplina que quer atualizar*:\n");
          scanf("%d", &code);
          int achou = 0;
          if (code < 0) {
            printf("matricula inválida\n");
          } else {
            for (i = 0; i < limiteD; i++) {
              if (code == dis[i].code && dis[i].ativo) {
                printf("*digite os novos dados\n*");
                printf("qual sera o novo código?\n");
                scanf("%d", &codenovo);
                getchar();
                printf("qual sera o novo nome?\n");
                fgets(nomedisnovo, 20, stdin);
                getchar();
                printf("qual será o novo semestre?\n");
                scanf("%d", &semestrenovo);
                dis[i].code = codenovo;
                strcpy(dis[i].nome, nomedisnovo);
                getchar();
                dis[i].semestre = semestrenovo;
                achou = 1;
                break;
              }
            }
          }

          if (achou) {
            printf("*disciplina atualizada*\n");
          } else {
            printf("*disciplina inexistente, não pode ser atualizada*");
          }
          break;
        }
        case 4: {
          printf("*excluir disciplina*\n");
          printf("*digite o codigo da disciplina que quer excluir*:\n");
          scanf("%d", &code);
          for (i = 0; i < limiteD; i++) {
            if (code == dis[i].code) {
              dis[i].ativo = -1;
              for (j = i; j < quantD - 1; j++) {
                dis[j].code = dis[j + 1].code;
                strcpy(dis[j].nome, dis[j + 1].nome);
                dis[j].semestre = dis[j + 1].semestre;
                dis[j].quantAD = dis[j + 1].quantAD;
              }
              quantD--;
              achou = 1;
              break;
            }
          }
          if (achou) {
            printf("*disciplina excluido*\n");
          } else {
            printf("*disciplina inexistente, não pode ser excluida*\n");
          }
          break;
        }
        case 5: {
          printf("*matricular alunos na disciplina*\n");
          printf("digite a matricula do aluno que você quer matricular em uma "
                 "disciplina\n");
          scanf("%d", &matricula);
          getchar();
          printf("digite a disciplina na qual você quer matricular o aluno\n");
          scanf("%d", &code);
          for (i = 0; i < quantD; i++) {
            if (code == dis[i].code) {
              for (j = 0; j < quantA; j++) {
                if (matricula == aluno[j].matricula) {
                  strcpy(dis[i].aluno[dis[i].quantAD].nome, aluno[j].nome);
                  dis[i].aluno[dis[i].quantAD].ativo++;
                  dis[i].quantAD++;
                  dis[i].alunoscadastrados++;
                }
              }
            }
          }
          break;
        }
        case 6: {
          printf("*matricular professores na disciplina*\n");
          printf(
              "digite a matricula do professor que você quer matricular em uma "
              "disciplina\n");
          scanf("%d", &matricula);
          getchar();
          printf(
              "digite a disciplina na qual você quer matricular o professor\n");
          scanf("%d", &code);
          for (i = 0; i < quantD; i++) {
            if (code == dis[i].code) {
              for (j = 0; j < quantP; j++) {
                if (matricula == professor[j].matricula) {
                  strcpy(dis[i].professor[dis[i].quantPD].nome,
                         professor[j].nome);
                  dis[i].professor[dis[i].quantPD].ativo++;
                  dis[i].quantPD++;
                }
              }
            }
          }
          break;
        }
        case 7: {
          printf("*excluir alunos da disciplina*\n");
          for (i = 0; i < limiteA; i++) {
            dis[i].aluno[dis[i].quantAD].ativo = 0;
          }
          break;
        }
        case 8: {
          printf("*excluir professores da disciplina*\n");
          for (i = 0; i < limiteA; i++) {
            dis[i].professor[dis[i].quantPD].ativo = 0;
          }
          break;
        }
        case 9: {
          printf("*listar disciplinas com 40+ alunos*\n");
          for (i = 0; i < quantD; i++) {
            if (dis[i].alunoscadastrados >= 40) {
              printf("disciplina: %d: %s\n", i + 1, dis[i].nome);
              for (j = 0; j < dis[i].quantPD; j++) {
                if (dis[i].professor[j].ativo != 0) {
                  printf("professor: %s\n", dis[i].professor[j].nome);
                }
              }
            }
          }
          break;
        }
        default: {
          invalido();
          break;
        }
        }
      }
      break;
    }
    default: {
      invalido();
      break;
    }
    }
    
    }
  }



void cadastroalunos() {
  printf("*cadastrar aluno*\n\n");
  for (int i = 0; i < limiteA; i++) {
    printf("digite a matricula do aluno %d:\n", i + 1);
    scanf("%d", &aluno[i].matricula);
    getchar();
    printf("digite o nome do aluno %d:\n", i + 1);
    fgets(aluno[i].nome, 50, stdin);
    getchar();
    printf("digite o cpf do aluno %d:\n", i + 1);
    scanf("%d", &aluno[i].cpf);
    getchar();
    printf("digite o sexo do aluno %d(m=masculino/f=feminino):\n", i + 1);
    scanf("%c", &sexo);
    getchar();
    if ((sexo == 'm') || (sexo == 'f')) {
      aluno[i].sexo = sexo;
    } else {
      printf("sexo invalido!");
    }
    printf("digite a data de nascimento do aluno %d (no formato dd mm "
           "aa):\n",
           i + 1);
    scanf("%d", &aluno[i].data.dia);
    getchar();
    scanf("%d", &aluno[i].data.mes);
    getchar();
    scanf("%d", &aluno[i].data.ano);
    getchar();
    aluno[i].ativo = 1;
    quantA++;
  }
}

void invalido() {
  printf("*escolha invalida! escolha uma das opções do menu*\n");
}

void menulistas() {
  printf("*como você quer listar?*\n");
  printf("normalmente - 1\nalfabeticamente - 2\nem ordem de nascimento - "
         "3\nsair - 0\n");
}

void menugeral() {
  int escolha;
  printf("*em que area quer entrar?*\n");
  printf("aluno - 1\nprofessor - 2\ndisciplina - 3\nsair - 0\n");
}

void menualunos() {
  int escolhaA;
  printf("*o que quer fazer nessa area?*\n");
  printf(
      "cadastrar - 1\nlistar - 2\natualizar - 3\nexcluir - 4\nver "
      "aniversariantes do mês - 5\nlistar por nome - 6\nlistar por sexo - "
      "7\nbuscar aluno - 8\nlistar por data de nascimento - 9\nvoltar - 0\n");
}

void intmenuprof() {
  printf("*o que quer fazer nessa area?*\n");
  printf("cadastrar - 1\nlistar - 2\natualizar - 3\nexcluir - 4\nver "
         "aniversariantes do mês - 5\nlistar por nome - 6\nlistar por sexo - "
         "7\nbuscar aluno - 8\nvoltar - 0\n");
}

void menudisc() {
  printf("*o que quer fazer nessa area?*\n");
  printf("cadastrar - 1\nlistar - 2\natualizar - 3\nexcluir - 4\nmatricular "
         "alunos - 5\nmatricular professor - 6\nexcluir aluno da disciplina - "
         "7\nexcluir professor da disciplina - 8\nlistar disciplinas com 40 "
         "vagas - 9\nvoltar - 0\n");
}