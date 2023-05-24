#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"


array  vetorPrincipal[TAM];


/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/


int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    if(posicao<1||posicao>TAM){
      return POSICAO_INVALIDA;
    }

    else if(vetorPrincipal[posicao-1].auxiliar!=NULL){
      return JA_TEM_ESTRUTURA_AUXILIAR;
    }
  
    else if(tamanho<1){
      return TAMANHO_INVALIDO;
    }

    vetorPrincipal[posicao-1].auxiliar = (int*) malloc(tamanho * sizeof(int));
    vetorPrincipal[posicao-1].size=tamanho;
    vetorPrincipal[posicao-1].qtdElement=0;

    if(!vetorPrincipal[posicao-1].auxiliar){
      return SEM_ESPACO_DE_MEMORIA;
    }

    return SUCESSO;

    

    
  
    
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
  int p=posicao-1;
  int retorno = 0;

  if(posicao < 11 && posicao > 0){
    if(vetorPrincipal[p].auxiliar!=NULL && vetorPrincipal[p].size > 0){
      if(vetorPrincipal[p].qtdElement < vetorPrincipal[p].size){
        vetorPrincipal[p].auxiliar[vetorPrincipal[p].qtdElement]=valor;
        vetorPrincipal[p].qtdElement++;

        retorno=SUCESSO;
      }
      else{
        retorno = SEM_ESPACO;
      }
    }
    else{
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }
  else{
    retorno = POSICAO_INVALIDA;
  }
  
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  int j=posicao-1;
  int retorno;
  if(j < 10 && j >= 0) {
    if(vetorPrincipal[j].auxiliar != NULL && vetorPrincipal[j].size > 0) {
      if(vetorPrincipal[j].qtdElement > 0) {
        vetorPrincipal[j].qtdElement--;
        return SUCESSO;
      } else 
          retorno = ESTRUTURA_AUXILIAR_VAZIA;

    } else 
        retorno = SEM_ESTRUTURA_AUXILIAR;
    
  } else 
      retorno = POSICAO_INVALIDA;

  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  int p=posicao-1;
  int retorno;

  if(p<10 && p>=0){
    if(vetorPrincipal[p].auxiliar!=NULL && vetorPrincipal[p].size > 0){
      if(vetorPrincipal[p].qtdElement>0){
        int achou=0;
        for(int i=0;i<vetorPrincipal[p].qtdElement;i++){
          if(vetorPrincipal[p].auxiliar[i]==valor){
            ++achou;
            for(int j=i-1;j<vetorPrincipal[p].qtdElement;j++){
              vetorPrincipal[p].auxiliar[j]=vetorPrincipal[p].auxiliar[j+1];
            }
            vetorPrincipal[p].qtdElement--;
            retorno=SUCESSO;
          }
        }
        if(achou==0)
          retorno = NUMERO_INEXISTENTE;
      }
      else{
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
      }
    }
    else{
      retorno=SEM_ESTRUTURA_AUXILIAR;
    }
  }
  else{
    retorno=POSICAO_INVALIDA;
  }

  return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;
    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno=0;
  int p=posicao-1;

  if(vetorAux==NULL)
    return POSICAO_INVALIDA;
  
  if(p<10 && p>=0){
    if(vetorPrincipal[p].auxiliar != NULL && vetorPrincipal[p].size > 0){
      if(vetorPrincipal[p].qtdElement > 0){
        for(int i=0;i<vetorPrincipal[p].qtdElement;i++){
          vetorAux[i]=vetorPrincipal[p].auxiliar[i];
        }
        retorno=SUCESSO;
      }
      else{
        retorno=ESTRUTURA_AUXILIAR_VAZIA;
      }
    }
    else{
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }
  else{
    retorno = POSICAO_INVALIDA;
  }
  
  return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

void selectionsort (int vetor[], int tamVetor) {
  int i, j, menorValor, temporario;
  for (i = 0; i < tamVetor - 1; i++) {
    menorValor = i;
    for (j = i + 1; j < tamVetor; j++) {
      if (vetor[j] < vetor[menorValor]) {
        menorValor = j;
      }
    }
    temporario = vetor[menorValor];
    vetor[menorValor] = vetor[i];
    vetor[i] = temporario;
  }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

  int retorno=0;
  int p=posicao-1;

  if(vetorAux==NULL)
    return POSICAO_INVALIDA;
  
  if(p<10 && p>=0){
    if(vetorPrincipal[p].auxiliar != NULL && vetorPrincipal[p].size > 0){
      if(vetorPrincipal[p].qtdElement > 0){
        int tamVector=0;
        for(int i=0;i<vetorPrincipal[p].qtdElement;i++){
          vetorAux[i]=vetorPrincipal[p].auxiliar[i];
          ++tamVector;
        }
        selectionsort(vetorAux, tamVector);
        retorno=SUCESSO;
      }
      else{
        retorno=ESTRUTURA_AUXILIAR_VAZIA;
      }
    }
    else{
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }
  else{
    retorno = POSICAO_INVALIDA;
  }
  
  return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    
  int retorno = 0;
  int SIZE, vecPosition=0,j=0;

  if(vetorAux==NULL)
    return SEM_ESPACO_DE_MEMORIA;

  for(int i=0;i<TAM;i++){
    if (vetorPrincipal[i].auxiliar != NULL && vetorPrincipal[i].qtdElement > 0 && vetorPrincipal[i].size > 0){
      for(int x=0;x<vetorPrincipal[i].qtdElement; x++){
        vetorAux[vecPosition]=vetorPrincipal[i].auxiliar[x];
        vecPosition++;
      }
      j++;
      
    }
  }
  if(j==0){
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

  int retorno = 0;
  int SIZE, vecPosition=0,j=0;

  if(vetorAux==NULL)
    return SEM_ESPACO_DE_MEMORIA;

  for(int i=0;i<TAM;i++){
    if (vetorPrincipal[i].auxiliar != NULL && vetorPrincipal[i].qtdElement > 0 && vetorPrincipal[i].size > 0){
      for(int x=0;x<vetorPrincipal[i].qtdElement; x++){
        vetorAux[vecPosition]=vetorPrincipal[i].auxiliar[x];
        vecPosition++;
      }
      j++;
      
    }
  }
  if(j==0){
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
  
  return SUCESSO;

}



/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
  for(int i=0;i<TAM;i++){
    
    
    vetorPrincipal[i].auxiliar=NULL;
    vetorPrincipal[i].qtdElement=0;
    //vetorPrincipal[i]= NULL;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}