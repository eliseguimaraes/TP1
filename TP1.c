#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP1.h"

PGM* LePGM(char* entrada) {
    FILE *arquivo;
    PGM imagem;
    int j,i;
    arquivo = fopen(entrada, "r"); // abre o arquivo em modo de leitura
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo: "); // imprime o erro
        exit(-1);
    }
    //lê arquivo
    char *buffer = "";
    fscanf(arquivo, "%s", buffer); //lê a primeira linha do arquivo
    if (strcmp(buffer, "P2")) {
        puts("Arquivo com formato incorreto");
        exit(-1);
    }
    // lê número de linhas e colunas e tamanho máximo
    fscanf(arquivo, "%d", &(imagem.c));
    fscanf(arquivo, "%d", &(imagem.l));
    fscanf(arquivo, "%hhu", &(imagem.maximo));
    // aloca os espaços na matriz dinamicamente
    imagem.dados = (unsigned char**)malloc(imagem.l*sizeof(unsigned char*));
    for (j=0; j<imagem.l; j++) {
        imagem.dados[j] = (unsigned char*)malloc(imagem.c*sizeof(unsigned char));
    }
    for (i=0; i<imagem.l; i++) {
        for (j=0; j<imagem.c; j++) {
            fscanf(arquivo, "%hhu", &(imagem.dados[i][j]));
        }
    }
    fclose(arquivo); // fecha o arquivo

    return &imagem;
}

int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p) {
    int correlacao = 0;
    int i, j;
    for (i=0; i<obj->l; i++) {
        for (j=0; j<obj->c; j++) {
            correlacao += cena->dados[i+p.y][j+p.x]*obj->dados[i][j];
        }
    }
    return correlacao;
}

Ponto JanelaDeslizante(PGM *cena, PGM *obj) {
    Ponto p, aux;
    int maior = 0;
    int i,j;
    //calcula a correlacao ao longo da cena, respeitando o limite máximo
    for (i=0; i<cena->l - obj->l + 1; i++) {
        for (j=0; j<cena->c - obj->c + 1; j++) {
            aux.x = j;
            aux.y = i;
            if (CorrelacaoCruzada(cena, obj, p) > maior) {
                p.x = aux.x;
                p.y = aux.y;
            }
        }
    }
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
    objeto = LePGM(argv[2]);
    Ponto p = JanelaDeslizante(cena, objeto); //calcula o ponto em que a correlacao cruzada tem seu maior valor
    saida = fopen(argv[3], "w"); // cria o arquivo de saida em modo de escrita
    fprintf(arquivo, "%d %d", p.x, p.y);
    fclose(saida); //fecha o arquivo de saida
    return 0;
}
