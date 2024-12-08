#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Usado pelo getpid, fork
#include <sys/wait.h> // Usando pelo waitpid
#include "clsc.h"

int main(int argc, char* argv[]) {
    return clsc(argc, argv);
}

/* Função principal do programa, realiza as chamadas de funções necessárias para o programa funcionar, 
   retorna EXIT_SUCCESS se houver parâmetros válidos, EXIT_FAILURE se não forem passados parâmetros
   ou forem passados parâmetros inválidos.
*/
int clsc(int argc, char *argv[]){
    int pid;
    if(argc > 1){
        bool palavraValida = verificaNome(argv[1], NUM_CARACTERES);

        printf("Existem Parametros!!\n");

        // Verifico se o parâmetro digitado é válido.
        if(palavraValida){
            printf("Existe um arquivo com esse nome!!\n");
            printf("Processo Pai %d Inicia...\n", getpid());
            pid = fork();
            if(pid == 0){
                printf("\tProcesso Filho %d inicia...\n", getpid());
                exit(EXIT_SUCCESS);
            }else{
                int status;
                waitpid(pid, &status, 0);
                printf("\tProcesso Filho finalizado...\n");
                printf("Processo Pai %d Continua...\n", getpid());
                printf("Processo Pai %d Finaliza...\n", getpid());
                sleep(10);
                exit(EXIT_SUCCESS);
            }
        }else{
            printf("Não existe um arquivo com esse nome!!\n");
        }
        return EXIT_SUCCESS;
    }
    printf("Não existe parametro\n");
    return EXIT_FAILURE;
}

// Verifica se existe um arquivo com o nome e a extensão .c no diretório atual, retorna true se existir, false se não.
bool verificaNome(char* nome, size_t tam){

    FILE *arq;
    if(arq = fopen(nome, "r")){
        fclose(arq);
        return true;
    }
    fclose(arq);
    return false;

}