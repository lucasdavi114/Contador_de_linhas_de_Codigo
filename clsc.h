#pragma once

#include <stdbool.h> // Usado pelo tipo bool.
#include <unistd.h> // Usado pelo getpid, fork

#define NUM_CARACTERES 30
#define EXTENSAO_C ".c"

/*  Struct para armazenar a soma das linhas,
    Soma as linhas em branco, linhas de codigo, e linhas de comentario.
*/
typedef struct {
    unsigned linhasEmBranco;
    unsigned linhasDeCodigo;
    unsigned linhasDeComentarios;
}SomaLinhas;

/*  Estrutura diretório armazena a quantidade de arquivos,
    E um vetor de estruturas do tipo SomaLinhas.
*/
typedef struct {
    unsigned numArquivos;
    SomaLinhas *linhas;
}Diretorio;

/*  Estrutura para guardar os tempos da execução do programa.
*/
typedef struct {
    time_t tempoInicio;
    time_t tempoFinal;
    clock_t tempoDeExecucao;
}TempoExecucao;

/* Função principal do programa, realiza as chamadas de funções necessárias para o programa funcionar, 
   retorna EXIT_SUCCESS se houver parâmetros válidos, EXIT_FAILURE se não forem passados parâmetros
   ou forem passados parâmetros inválidos.
*/
int clsc(int argc, char *argv[]);

// Cria um processo filho, exibe as somas das linhas no terminal.
pid_t processoPai();

// Verifica se existe um arquivo com o nome e a extensão .c no diretório atual, retorna true se existir, false se não.
bool verificaNome(const char* strNome, size_t tam);

// Verifica se e um arquivo de codigo fonte C (.c), retorna true se for, false se não. 
bool verificaExtensao(const char* strNome);

// Verifica se é um diretório, retorna true ou false.
bool isDirectory(const char* string);

// Realiza as somas de todos os tipos de linhas.
void processoFilho();

/* Função para somar as linhas do codigo fonte, soma as linhas em branco, linhas de codigo e linhas em branco, 
   recebe a Struct SomaLinhas.
   Retorna a soma de todas as linhas
*/
unsigned somaLinhas(SomaLinhas tiposLinhas);

// Exibe o prompt de saida padrao.
void saidaPadrao(TempoExecucao t);

SomaLinhas* alocaMemoriaArquivos(Diretorio d);