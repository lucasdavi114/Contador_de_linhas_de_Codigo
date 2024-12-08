#pragma once

#include <stdbool.h> // Usado pelo tipo bool.
#include <unistd.h> // Usado pelo getpid, fork

#define NUM_CARACTERES 30
#define EXTENSAO ".c"

/* Função principal do programa, realiza as chamadas de funções necessárias para o programa funcionar, 
   retorna EXIT_SUCCESS se houver parâmetros válidos, EXIT_FAILURE se não forem passados parâmetros
   ou forem passados parâmetros inválidos.
*/
int clsc(int argc, char *argv[]);

// Verifica se existe um arquivo com o nome e a extensão .c no diretório atual, retorna true se existir, false se não.
bool verificaNome(const char* nome, size_t tam);

// Cria um processo filho, exibe as somas das linhas no terminal.
pid_t processoPai();

// Realiza as somas de todos os tipos de linhas.
void processoFilho();