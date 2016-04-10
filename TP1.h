#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED

typedef struct {
    int c;                  // número de colunas na imagem
    int l;                  // número de linhas na imagem
    unsigned char maximo;   // valor máximo para cada pixel
    unsigned char **dados;  //variável para armazenar os pixels da imagem (matriz)
} PGM;

typedef struct {
    int x;  // coluna
    int y;  // linha
} Ponto;

PGM* LePGM(char* entrada);
/*---------------------------------------------------------------
Protótipo: PGM *LePGM(char* entrada)
Função: Lê o arquivo entrada e o traduz como uma variável do tipo PGM
Entrada: Arquivo de entrada
Saída: Imagem (PGM) resultante da leitura do arquivo de entrada
----------------------------------------------------------------*/

int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p);
/*---------------------------------------------------------------
Protótipo: CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p)
Função: Calcular a correlação cruzada entre a imagem "cena" e o objeto "obj", com a cena na posição p = (x,y)
Entrada: Estruturas contendo a imagem da cena (PGM *cena), a imagem do objeto (PGM *obj) e o ponto de cálculo da correlação (Ponto p)
Saída: Resultado inteiro (int) do cálculo da correlação cruzada
----------------------------------------------------------------*/

Ponto JanelaDeslizante(PGM *cena, PGM *obj);
/*---------------------------------------------------------------
Protótipo: Ponto JanelaDeslizante(PGM *cena, PGM *obj);
Função: Percorre a imagem da cena, calculando a correlação cruzada em todos os pontos x e y e retornando a posição onde houve maior valor
Entrada: Estruturas contendo a imagem da cena (PGM *cena) e a imagem do objeto (PGM *obj)
Saída: Posição (Ponto) onde houve o maior valor de correlação cruzada
----------------------------------------------------------------*/


#endif // TP1_H_INCLUDED
