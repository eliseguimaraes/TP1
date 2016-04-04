#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP1.h"

PGM LePGM(char* entrada) {
    FILE *arquivo;
    arquivo = fopen(entrada, "r"); // abre o arquivo em modo de leitura
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo: "); // imprime o erro
        exit(-1);
    }
    fclose(arquivo); // fecha o arquivo
    PGM imagem;
    return imagem;
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
    PGM cena, objeto;
    FILE *saida;

    cena = LePGM(argv[1]);
    objeto = LePGM(argv[2]);
    saida = fopen(argv[3], "w");
    fclose(saida);
    return 0;
}
