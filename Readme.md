### Funcionamento do Programa

1. O usuário digita na linha de comando do sistema operacional o nome do programa clsc e
passa como argumento o nome de um arquivo (p. ex., clsc.c) ou diretório que contém os
códigos-fontes, como no exemplo abaixo que usa o diretório SO.

    ./clsc SO

2. O programa clsc (processo pai) deve ler o nome do arquivo ou diretório, criar o processo filho
e aguardar até a contagem terminar. O processo filho deve criar uma thread para contar o
número de linhas vazias, comentários e instruções do código-fonte da Linguagem C. Para cada
arquivo do diretório deve-se criar uma thread. Se o diretório possui 20 arquivos .c então cria-
se 20 threads.