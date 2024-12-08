#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clsc.h"

int main(int argc, char* argv[]) {
    return clsc(argc, argv);
}

/* Função principal do programa, realiza as chamadas de funções necessárias para o programa funcionar, 
   retorna EXIT_SUCCESS se houver parâmetros válidos, EXIT_FAILURE se não forem passados parâmetros
   ou forem passados parâmetros inválidos.
*/
int clsc(int argc, char *argv[]){

    if(argv[1] != NULL){
        bool palavraValida = verificaNome(argv[1], NUM_CARACTERES);

        // Verifico se o parâmetro digitado é válido.
        if(palavraValida){

        }
        return EXIT_SUCCESS;
    }
    printf("Não existe parametro\n");
    return EXIT_FAILURE;
}

// Verifica se existe um arquivo com o nome e a extensão .c no diretório atual, retorna true se existir, false se não.
bool verificaNome(char* nome, size_t tam){

    return false;

}