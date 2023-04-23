// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Pedro Henrique Santos de Carvalho
//  email: huenrique73@gmail.com
//  Matrícula: 20222160005
//  Semestre: 2023.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "PedroCarvalho20222160005.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i;
  int k;

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
    for(k=0;k<i;k++){
      if((sDia[k]<'0')||(sDia[k]>'9')){
        dq.valido=0;
        return dq;
      }
    }
	}else {
		dq.valido = 0;
    return dq;
  }
  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

  

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;                                    
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
    for(k=0;k<i;k++){
      if((sMes[k]<'0')||(sDia[k]>'9')){
        dq.valido=0;
        return dq;
      }
    }
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}
  
	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
    for(k=0;k<i;k++){
      if((sAno[k]<'0')||(sDia[k]>'9')){
        dq.valido=0;
        return dq;
      }
    }
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

  if(i==2){
    dq.iAno=dq.iAno+2000;
  }

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida;
  
  //quebrar a string data em strings sDia, sMes, sAno

  //DataQuebrada dataQuebrada = quebraData(data);
  //if (dataQuebrada.valido == 0) return 0;

  //printf("%s\n", data);
  
  DataQuebrada dataQuebrada = quebraData(data);
  
  
  if (dataQuebrada.valido == 0){
      return 0;
  }
  datavalida=validar(dataQuebrada.iDia,dataQuebrada.iMes,dataQuebrada.iAno);
  if(datavalida){
    return 1;
  }
    return 0;
  
}

int validar (int dia, int mes, int ano){
  int MaxDias;
  int QuantDias;
  if((dia<0)||(ano<0)||(mes<0)||(mes>12))
    return 0;
  if(mes==2){
    if(((ano%4==0)&&(ano%100!=0))||(ano%400==0)){
      QuantDias=29;
    } else {
      QuantDias=28;
    }
  } else {
    switch (mes){
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        QuantDias=31;
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        QuantDias=30;
        break;
    }
   
  }
   MaxDias=QuantDias;
    printf("%d",MaxDias);
  if(dia>MaxDias){
    return 0;
  }
  return 1;
}





/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }

    DataQuebrada dma1 = quebraData(datainicial);
    DataQuebrada dma2 = quebraData(datafinal);

    if((dma1.iAno > dma2.iAno) || (dma1.iAno == dma2.iAno && dma1.iMes > dma2.iMes) ||(dma1.iAno==dma2.iAno && dma1.iMes == dma2.iMes && dma1.iDia > dma2.iDia)){
      dma.retorno = 4;
      return dma;
    }
    else{
      int mes = quantidadeDias(dma1.iMes, dma1.iAno);
      dma.retorno = 1;


    }
      
      //verifique se a data final não é menor que a data inicial
      
      //calcule a distancia entre as datas


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    
    
}

int quantidadeDias(int mes, int ano) {
  switch (mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:{
      if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) {
        return 29;
      } else {
        return 28;
      }
    }
  }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.0
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias = 0;
  for(int i=0;texto[i]!='\0';i++){
    if(isCaseSensitive == 1){
      if(c==texto[i])
        qtdOcorrencias++;
    }
    else{
      if((c==texto[i])||(c+32==texto[i])||(c-32==texto[i]))
        qtdOcorrencias++;
    }
  }
  return qtdOcorrencias;
}



/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias = 0;
  int i,j,x,t,c,index=0,acento=0;

  for(i=0;strTexto[c]!='\0';c++){
    if(strTexto[c]==-61){
      for(i=c;strTexto[i]!='\0';i++){
        strTexto[i]=strTexto[i+1];
      }
    }
  }

  for(i=0;strBusca[c]!='\0';c++){
    if(strBusca[c]==-61){
      for(i=c;strBusca[i]!='\0';i++){
        strBusca[i]=strBusca[i+1];
      }
    }
  }

  for(i=0;strTexto[i]!='\0';i++){
    if(strBusca[0]==strTexto[i]){
      for(j=i+1,x=1,t=1;strBusca[x]!='\0';j++,x++){
        if(strBusca[x]==strTexto[j]){
          t++;
        }
        else{
          break;
        }
      }
      if(strlen(strBusca)==t){
        c=acento/2;
        qtdOcorrencias++;
        posicoes[index]=i+1;
        index++;
        posicoes[index]=i+t;
        index++;
        i++;
      }
    }
  }
  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
int n, numaux, base = 10;
  int tam = quantcasas(num);
  numaux = num;
  num = 0;
  for (int i = tam; i > 0; i--) {
    n = numaux % base;
    numaux /= base;
    n *= pow(10, i - 1);
    num += n;
  }

  return num;
}

int quantcasas(int num) {
  int count = 1;
  while (num / 10 != 0) {
    count++;
    num /= 10;
  }
  return count;
};


/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  if (numerobusca > numerobase)
    return 0;

  int qtdOcorrencias = 0;

  int numerobaseT = quantcasas(numerobase);
  int numerobuscaT = quantcasas(numerobusca);

  int base = pow(10, numerobaseT - numerobuscaT);
  int t = pow(10, numerobaseT - 1);
  int a = pow(10, numerobuscaT - 1);

  int num = numerobase;

  for (; base; base /= 10) {
    int aux = num / base;
    if (aux == numerobusca){
      qtdOcorrencias++;
      t /= a;
      base /= a;
    }
    num %= t;
    t /= 10;
  }
  return qtdOcorrencias;
}