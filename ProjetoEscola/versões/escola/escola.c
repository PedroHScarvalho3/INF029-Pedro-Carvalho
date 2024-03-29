#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define limiteA 3
#define limiteP 3
#define limiteD 3

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
int quantA = limiteA,quantP = limiteP,quantD = limiteD, mes=0, mescount=0, matricula, code, achou=0;
char sexo, escolhaS;
dis disc[limiteD];
int matriculanova, dianovo, mesnovo, anonovo, cpfnovo, sexonovo, codenovo,semestrenovo;
char nomenovo[50], nomedisnovo[20],str[50];

void cadastroalunos();
void cadastroprofessor();
void listagemalunos(dados aluno[],int quantA);
void listagemprofessor(dados professor[],int quantP);
void aniversariantesA();
void aniversariantesP();
void atualizaraluno();
void excluiraluno();
void excluirprofessor();
void atualizarprofessor();
void listagemporsexoA();
void listagemporsexoP();
void listagemnascimentoA();
void cadastrardisciplinas();
void listardisciplinas();
void atualizardisciplinas();
void excluirdisciplina();
void matricularalunoD();
void matricularprofessorD();
void quarentaalunos();

void menugeral();
void menualunos();
void menuprof();
void menudisc();
void invalido();

int main() {

  int escolha, escolhaA, escolhaD,escolhaP, i, sair = 0, sairA = 0,sairP=0, sairD = 0,quantP=0, quantD = 0, code, j,k,cont;
  
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
          break;
        }
        case 2: {
          listagemalunos(aluno,quantA);

          break;
        }
        case 3: {
          atualizaraluno();
          break;
        }
        case 4: {
          excluiraluno();
          break;
        }
        case 5: {
          aniversariantesA();
          break;
        }
        case 6: {
          printf("*listagem de alunos por nome*\n");
          for(j=0;j<quantA;j++){
            for(i=quantA;i>0;i--){
              copia=aluno[i-1];
              if(strcmp(copia.nome,aluno[i].nome)>0){
                aluno[i-1]=aluno[i];
                aluno[i]=copia;
              }
            }
          }
          listagemalunos(aluno,quantA);
          break;
        }
        case 7: {
          listagemporsexoA();
          break;
        }
        case 8:{
          printf("*buscar aluno*\n");
          printf("digite o que quer procurar\n");
          fgets(str,50,stdin);
          getchar();
          for(i=0;i<quantA;i++){
            cont=0;
            for(j=0;j<strlen(aluno[i].nome);j++){
              for(k=0;k<strlen(str);k++) {
                setbuf(stdin, 0);
                if(str[k] == aluno[i].nome[j]) {
                  cont++;
                  break;
                }
              }
            }
            if(cont > 2) { 
              printf("- %s\n", aluno[i].nome);
            }
          }
          break;
        }
          case 9:{
            printf("*listagem de alunos por data de nascimento*\n");
            for(i=0;i<quantA-1;i++){
              if(aluno[i].data.ano>aluno[i+1].data.ano){
                copia=aluno[i];
                aluno[i]=aluno[i+1];
                aluno[i+1]=copia; 
              }
              else if(aluno[i].data.mes>aluno[i+1].data.mes){
                      copia=aluno[i];
                      aluno[i]=aluno[i+1];
                      aluno[i+1]=copia; 
              }
              else if(aluno[i].data.dia>aluno[i+1].data.dia){
                      copia=aluno[i];
                      aluno[i]=aluno[i+1];
                      aluno[i+1]=copia; 
              }
            }
            listagemalunos(aluno,quantA);
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
          cadastroprofessor();
          break;
        }
        case 2: {
          listagemprofessor(professor,quantP);
          break;
        }
        case 3: {
          atualizarprofessor();
          break;
        }
        case 4: {
          excluirprofessor();
          break;
        }
        case 5: {
          aniversariantesP();
          break;
        }
        case 6: {
          printf("*listagem de professor por nome*\n");
          for(j=0;j<quantP;j++){
            for(i=quantP;i>0;i--){
            copiaP=professor[i-1];
            if(strcmp(copiaP.nome,professor[i].nome)>0){
              professor[i-1]=professor[i];
              professor[i]=copiaP;
              }
            }
          }
          listagemprofessor(professor,quantP);
          break;
        }
        case 7: {
          void listagemporsexoP();
          break;
        }
        case 8:{
          printf("*buscar professor*\n");
          printf("digite o que quer procurar\n");
          fgets(str,50,stdin);
          getchar();
          for(i=0;i<quantP;i++){
            cont=0;
            for(j=0;j<strlen(professor[i].nome);j++){
              for(k=0;k<strlen(str);k++) {
                setbuf(stdin, 0);
                if(str[k] == professor[i].nome[j]) {
                  cont++;
                  break;
                }
              }
            }
            if(cont > 2) { 
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
          cadastrardisciplinas();
          break;
        }
        case 2: {
          listardisciplinas();
          break;
        }
        case 3: {
          void atualizardisciplinas();
          break;
        }
        case 4: {
          excluirdisciplina();
          break;
        }
        case 5: {
          matricularalunoD();
          break;
        }
        case 6: {
          matricularprofessorD();
          break;
        }
        case 7: {
          printf("*excluir alunos da disciplina*\n");
          for(i=0;i<limiteA;i++){
            disc[i].aluno[disc[i].quantAD].ativo=0;
          }
          break;
        }
        case 8: {
          printf("*excluir professores da disciplina*\n");
          for(i=0;i<limiteA;i++){
            disc[i].professor[disc[i].quantPD].ativo=0;
          }
          break;
        }
          case 9:{
            quarentaalunos();
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

void cadastroprofessor(){
  printf("*cadastrar professor*\n\n");
          for (int i = 0; i < limiteP; i++) {

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
            printf("digite a data de nascimento do professor %d (no formato dd mm "
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
}

void listagemalunos(dados aluno[],int quantA){
  printf("*listar aluno*\n");
          if (quantA == 0) {
            printf("*sem cadastros disponiveis*\n");
          } else {
            for (int i = 0; i < quantA; i++) {
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
            for (int i = 0; i < quantA; i++) {
            }
          }
}

void listagemprofessor(dados professor[],int quantP){
  printf("*listar professor*\n");
          if (quantP == 0) {
            printf("*sem cadastros disponiveis*\n");
          } else {
            for (int i = 0; i < quantP; i++) {
              if (professor[i].ativo) {
                printf("matricula do professor %d: %d\n", i + 1,
                       professor[i].matricula);
                printf("nome do professor %d: %s", i + 1, professor[i].nome);
                printf("cpf do professor %d: %d\n", i + 1, professor[i].cpf);
                printf("sexo do professor %d: %c\n", i + 1, professor[i].sexo);
                printf("data de nascimento do professor %d: %d/%d/%d\n", i + 1,
                       professor[i].data.dia, professor[i].data.mes, professor[i].data.ano);
                printf("\n");
              }
            }
            for (int i = 0; i < quantP; i++) {
            }
          }

}

void menugeral() {
  printf("*em que area quer entrar?*\n");
  printf("aluno - 1\nprofessor - 2\ndisciplina - 3\nsair - 0\n");
}

void menualunos() {
  printf("*o que quer fazer nessa area?*\n");
  printf("cadastrar - 1\nlistar - 2\natualizar - 3\nexcluir - 4\nver "
         "aniversariantes do mês - 5\nlistar por nome - 6\nlistar por sexo - "
         "7\nbuscar aluno - 8\nlistar por data de nascimento - 9\nvoltar - 0\n");
}

void aniversariantesA(){
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
              for (int i = 0; i < quantA; i++) {
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
}

void aniversariantesP(){
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
              for (int i = 0; i < quantP; i++) {
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

}

void atualizaraluno(){
  printf("*atualizar aluno*\n");
          printf("*digite a matricula do aluno que quer atualizar*:\n");
          scanf("%d", &matricula);
          int achou = 0;
          if (matricula < 0) {
            printf("matricula inválida\n");
          } else {
            for (int i = 0; i < limiteA; i++) {
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
}

void excluiraluno(){
  printf("*excluir aluno*\n");
          printf("*digite a matricula do aluno que quer excluir*:\n");
          scanf("%d", &matricula);
          for (int i = 0; i < limiteA; i++) {
            if (matricula == aluno[i].matricula) {
              aluno[i].ativo = -1;
              for (int j = i; j < quantA - 1; j++) {
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
}

void excluirprofessor(){
  printf("*excluirprofessor*\n");
          printf("*digite a matricula do professor que quer excluir*:\n");
          scanf("%d", &matricula);
          for (int i = 0; i < limiteP; i++) {
            if (matricula == professor[i].matricula) {
              professor[i].ativo = -1;
              for (int j = i; j < quantP - 1; j++) {
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
}

void atualizarprofessor(){
  printf("*atualizar professor*\n");
          printf("*digite a matricula do professor que quer atualizar*:\n");
          scanf("%d", &matricula);
          int achou = 0;
          if (matricula < 0) {
            printf("matricula inválida\n");
          } else {
            for (int i = 0; i < limiteP; i++) {
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
}

void listagemporsexoA(){
  printf("*listagem por sexo*\n");
          printf("qual sexo voce quer listar?(m=masculino/f=feminino)\n");
          scanf("%c", &escolhaS);
          if (escolhaS == 'm') {
            printf("*lista dos masculinos*\n");
            for (int i = 0; i < quantA; i++) {
              if (aluno[i].sexo == escolhaS) {
                printf("aluno %d: %s\n", i + 1, aluno[i].nome);
              }
            }
          }
          if (escolhaS == 'f') {
            printf("*lista dos femininos*\n");
            for (int i = 0; i < quantA; i++) {
              if (aluno[i].sexo == escolhaS) {
                printf("aluna %d: %s\n", i + 1, aluno[i].nome);
              }
            }
          }
}

void listagemporsexoP(){
  printf("*listagem por sexo*\n");
          printf("qual sexo voce quer listar?(m=masculino/f=feminino)\n");
          scanf("%c", &escolhaS);
          if (escolhaS == 'm') {
            printf("*lista dos masculinos*\n");
            for (int i = 0; i < quantP; i++) {
              if (professor[i].sexo == escolhaS) {
                printf("professor %d: %s\n", i + 1, professor[i].nome);
              }
            }
          }
          if (escolhaS == 'f') {
            printf("*lista dos femininos*\n");
            for (int i = 0; i < quantP; i++) {
              if (professor[i].sexo == escolhaS) {
                printf("professora %d: %s\n", i + 1, professor[i].nome);
              }
            }
          }
}

void listagemnascimentoA(){
  printf("*listagem de alunos por data de nascimento*\n");
            for(int i=0;i<quantA-1;i++){
              if(aluno[i].data.ano>aluno[i+1].data.ano){
                copia=aluno[i];
                aluno[i]=aluno[i+1];
                aluno[i+1]=copia; 
              }
              else if(aluno[i].data.mes>aluno[i+1].data.mes){
                      copia=aluno[i];
                      aluno[i]=aluno[i+1];
                      aluno[i+1]=copia; 
              }
              else if(aluno[i].data.dia>aluno[i+1].data.dia){
                      copia=aluno[i];
                      aluno[i]=aluno[i+1];
                      aluno[i+1]=copia; 
              }
            }
            for (int i = 0; i < quantA; i++) {
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
}

void menuprof() {
  printf("*o que quer fazer nessa area?*\n");
  printf("cadastrar - 1\nlistar - 2\natualizar - 3\nexcluir - 4\nver "
         "aniversariantes do mês - 5\nlistar por nome - 6\nlistar por sexo - "
         "7\nbuscar aluno - 8\nlistar por data de nascimento - 9\nvoltar - 0\n");
}

void menudisc() {
  printf("*o que quer fazer nessa area?*\n");
  printf("cadastrar - 1\nlistar - 2\natualizar - 3\nexcluir - 4\nmatricular "
         "alunos - 5\nmatricular professor - 6\nexcluir aluno da disciplina - 7\nexcluir professor da disciplina - 8\nlistar disciplinas com 40 vagas - 9\nvoltar - 0\n");
}

void cadastrardisciplinas(){
  printf("*cadastrar disciplina*\n");
          for (int i = 0; i < limiteD; i++) {

            printf("digite o codigo da disciplina %d:\n", i + 1);
            scanf("%d", &disc[i].code);
            getchar();
            printf("digite o nome da disciplina %d:\n", i + 1);
            fgets(disc[i].nome, 20, stdin);
            getchar();
            printf("digite o semestre da disciplina %d:\n", i + 1);
            scanf("%d",&disc[i].semestre);
            getchar();
            disc[i].ativo = 1;
            disc[i].alunoscadastrados=0;
            quantD++;
          }
}

void listardisciplinas(){
  printf("*listar disciplina*\n");
          if (quantD == 0) {
            printf("*sem disciplinas disponiveis*\n");
          } else {
            for (int i = 0; i < quantD; i++) {
              if (disc[i].ativo) {
                printf("codigo da disciplina %d: %d\n", i + 1, disc[i].code);
                printf("nome da disciplina %d: %s\n", i + 1, disc[i].nome);
                printf("semestre da disciplina %d: %d \n", i+1, disc[i].semestre);
                for (int j = 0; j < disc[i].quantAD; j++) {
                  if (disc[i].aluno[j].ativo != 0) {
                    printf("aluno %d: %s\n", j + 1, disc[i].aluno[j].nome);
                  }
                }
                for (int j = 0; j < disc[i].quantPD; j++) {
                  if (disc[i].professor[j].ativo != 0) {
                    printf("professor %d: %s\n", j + 1, disc[i].professor[j].nome);
                  }
                }
                printf("\n");
              }
            }
          }
}

void atualizardisciplinas(){
  printf("*atualizar disciplina*\n");
          printf("*digite o codigo da disciplina que quer atualizar*:\n");
          scanf("%d", &code);
          int achou = 0;
          if (code < 0) {
            printf("matricula inválida\n");
          } else {
            for (int i = 0; i < limiteD; i++) {
              if (code == disc[i].code && disc[i].ativo) {
                printf("*digite os novos dados\n*");
                printf("qual sera o novo código?\n");
                scanf("%d", &codenovo);
                getchar();
                printf("qual sera o novo nome?\n");
                fgets(nomedisnovo, 20, stdin);
                getchar();
                printf("qual será o novo semestre?\n");
                scanf("%d",&semestrenovo);
                disc[i].code = codenovo;
                strcpy(disc[i].nome, nomedisnovo);
                getchar();
                disc[i].semestre=semestrenovo;
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
}

void excluirdisciplina(){
  printf("*excluir disciplina*\n");
          printf("*digite o codigo da disciplina que quer excluir*:\n");
          scanf("%d", &code);
          for (int i = 0; i < limiteD; i++) {
            if (code == disc[i].code) {
              disc[i].ativo = -1;
              for (int j = i; j < quantD - 1; j++) {
                disc[j].code = disc[j + 1].code;
                strcpy(disc[j].nome, disc[j + 1].nome);
                disc[j].semestre = disc[j+1].semestre;
                disc[j].quantAD = disc[j + 1].quantAD;
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
}

void matricularalunoD(){
  printf("*matricular alunos na disciplina*\n");
          printf("digite a matricula do aluno que você quer matricular em uma "
                 "disciplina\n");
          scanf("%d", &matricula);
          getchar();
          printf("digite a disciplina na qual você quer matricular o aluno\n");
          scanf("%d", &code);
          for (int i = 0; i < quantD; i++) {
            if (code == disc[i].code) {
              for (int j = 0; j < quantA; j++) {
                if (matricula == aluno[j].matricula) {
                  strcpy(disc[i].aluno[disc[i].quantAD].nome, aluno[j].nome);
                  disc[i].aluno[disc[i].quantAD].ativo++;
                  disc[i].quantAD++;
                  disc[i].alunoscadastrados++;
                  
                }
              }
            }
          }
}

void matricularprofessorD(){
  printf("*matricular professores na disciplina*\n");
          printf("digite a matricula do professor que você quer matricular em uma "
                 "disciplina\n");
          scanf("%d", &matricula);
          getchar();
          printf("digite a disciplina na qual você quer matricular o professor\n");
          scanf("%d", &code);
          for (int i = 0; i < quantD; i++) {
            if (code == disc[i].code) {
              for (int j = 0; j < quantP; j++) {
                if (matricula == professor[j].matricula) {
                  strcpy(disc[i].professor[disc[i].quantPD].nome, professor[j].nome);
                  disc[i].professor[disc[i].quantPD].ativo++;
                  disc[i].quantPD++;
                  
                }
              }
            }
          }
}

void quarentaalunos(){
  printf("*listar disciplinas com 40+ alunos*\n");
            for(int i=0;i<quantD;i++){
              if(disc[i].alunoscadastrados>=40){
                printf("disciplina: %d: %s\n",i+1,disc[i].nome);
                for (int j = 0; j < disc[i].quantPD; j++) {
                  if (disc[i].professor[j].ativo != 0) {
                    printf("professor: %s\n", disc[i].professor[j].nome);
                  }
                }
              }
            }
}

void invalido() {
  printf("*escolha invalida! escolha uma das opções do menu*\n");
}