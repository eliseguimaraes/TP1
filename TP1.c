#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP1.h"

PGM* LePGM(char* entrada) {
    FILE *arquivo;
    PGM imagem;
    int j;
    unsigned char dado;
//    arquivo = fopen("exemplo_cena.pgm","w");
//    fprintf(arquivo, "%s", "P2\n");
    arquivo = fopen(entrada, "r"); // abre o arquivo em modo de leitura
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo: "); // imprime o erro
        exit(-1);
    }
    //lê arquivo
    char *buffer;
    fscanf(arquivo, "%s", buffer); //lê a primeira linha do arquivo
    if (strcmp(buffer, "P2")) {
        puts("Arquivo com formato incorreto");
        exit(-1);
    }
    // lê número de linhas e colunas e tamanho máximo
    fscanf(arquivo, "%d", &(imagem.c));
    fscanf(arquivo, "%d", &(imagem.l));
    fscanf(arquivo, "%hhu", &(imagem.maximo));
    // aloca os espaços na matriz
    imagem.dados = (unsigned char**)malloc(imagem.l*sizeof(unsigned char*));
    for (j=0; j<imagem.l; j++) {
        imagem.dados[j] = (unsigned char*)malloc(imagem.c*sizeof(unsigned char));
    }
    dado = 1;
    printf("%d", imagem.c);
    int i = 0;
    for (i=0; i<imagem.c; i++) {
        printf("\n%d", i);
    }
//    for (i=0; i<imagem.l; i++) {
//        for (j=0; j<imagem.l; j++) {
////            fscanf(arquivo, "%hhu", &dado);
//            printf("%hhu\n", dado);
////            imagem.dados[i][j] = dado;
//        }
//    }
    fclose(arquivo); // fecha o arquivo

    return &imagem;
}

int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p) {
    int correlacao;
    return correlacao;
}

Ponto JanelaDeslizante(PGM *cena, PGM *obj) {
    Ponto p;
    return p;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("%d argumentos informados. 3 argumentos sao necessarios.", argc - 1);
        return 1;
    }
    PGM *cena, *objeto;
    FILE *saida;

    cena = LePGM(argv[1]);
    //objeto = LePGM(argv[2]);
    saida = fopen(argv[3], "w"); // cria o arquivo de saída em modo de escrita
    fclose(saida); //fecha o arquivo de saída
    return 0;
}
