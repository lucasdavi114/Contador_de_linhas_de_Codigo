#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <sys/wait.h> // Usando pelo waitpid
#include <time.h> // Requerido para ver o tempo de execução.
#include "clsc.h"

int main(int argc, char* argv[]) {
    return clsc(argc, argv);
}

/* Função principal do programa, realiza as chamadas de funções necessárias para o programa funcionar, 
   retorna EXIT_SUCCESS se houver parâmetros válidos, EXIT_FAILURE se não forem passados parâmetros
   ou forem passados parâmetros inválidos.
*/
int clsc(int argc, char *argv[]){

    setlocale(LC_ALL, "pt-BR");

    if(argc == 2){
        bool palavraValida = verificaNome(argv[1], NUM_CARACTERES);

        // Verifico se o parâmetro digitado é válido.
        if(palavraValida){
            printf("Processo Pai %d Inicia...\n", getpid());
            
            // Chamada de função do processoPai que cria o processo filho e exibe o prompt final.
            processoPai();
        }else{
            printf("Não existe um arquivo com esse nome!!\n");
        }
        return EXIT_SUCCESS;
    }else if(argc > 2){
        printf("\nParâmetros demais sendo executados!\n");
    }
    printf("\nÉ necessário passar o nome do Arquivo ou um diretório válido!\n");
    return EXIT_FAILURE;
}

// Verifica se existe um arquivo com o nome e a extensão .c no diretório atual, retorna true se existir, false se não.
bool verificaNome(const char* strNome, size_t tam){

    FILE *arq;
    arq = fopen(strNome, "r");
    if(arq){
        fclose(arq);
        return true;
    }   
    return false;
}

// Verifica se e um arquivo de codigo fonte C (.c), retorna true se for, false se não. 
bool verificaExtensao(const char* strNome);

// Cria um processo filho, exibe as somas das linhas no terminal.
pid_t processoPai(){

    TempoExecucao t;

    pid_t pid = fork();
    time_t tempoInicio, tempoFinal;
    if(pid == 0){
        processoFilho();
    }else{
        tempoInicio = time(NULL);
        int status;
        waitpid(pid, &status, 0);
        tempoFinal = time(NULL);
        saidaPadrao(t);
        exit(EXIT_SUCCESS);
    }
}

// Realiza as somas de todos os tipos de linhas.
void processoFilho(){
    
    pid_t pidFilho = getpid();
    printf("\tProcesso Filho %d inicia...\n", pidFilho);
    printf("\tProcesso Filho %d finaliza...\n", pidFilho);
    
    exit(EXIT_SUCCESS);
}

// Exibe o prompt de saida padrao.
void saidaPadrao(TempoExecucao t) {

    t.tempoDeExecucao = clock();

    printf("\n- Código Fonte C:\n");
    printf("\tNº de arquivos = \n");
    printf("\tLinhas vazias = \n");
    printf("\tLinhas de comentários = \n");
    printf("\tLinhas de instruções = \n");

    printf("\n- Tempo:\n");
    printf("\tInício.....: \n");
    printf("\tTérmino: \n");
    t.tempoDeExecucao = clock() - t.tempoDeExecucao;
    printf("\tDuração: %.0lf Segundos\n\n", ((double)t.tempoDeExecucao)/((CLOCKS_PER_SEC/1000)));
}