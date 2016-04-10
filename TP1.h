#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED

typedef struct {
    int c;                  // n�mero de colunas na imagem
    int l;                  // n�mero de linhas na imagem
    unsigned char maximo;   // valor m�ximo para cada pixel
    unsigned char **dados;  //vari�vel para armazenar os pixels da imagem (matriz)
} PGM;

typedef struct {
    int x;  // coluna
    int y;  // linha
} Ponto;

PGM* LePGM(char* entrada);
/*---------------------------------------------------------------
Prot�tipo: PGM *LePGM(char* entrada)
Fun��o: L� o arquivo entrada e o traduz como uma vari�vel do tipo PGM
Entrada: Arquivo de entrada
Sa�da: Imagem (PGM) resultante da leitura do arquivo de entrada
----------------------------------------------------------------*/

int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p);
/*---------------------------------------------------------------
Prot�tipo: CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p)
Fun��o: Calcular a correla��o cruzada entre a imagem "cena" e o objeto "obj", com a cena na posi��o p = (x,y)
Entrada: Estruturas contendo a imagem da cena (PGM *cena), a imagem do objeto (PGM *obj) e o ponto de c�lculo da correla��o (Ponto p)
Sa�da: Resultado inteiro (int) do c�lculo da correla��o cruzada
----------------------------------------------------------------*/

Ponto JanelaDeslizante(PGM *cena, PGM *obj);
/*---------------------------------------------------------------
Prot�tipo: Ponto JanelaDeslizante(PGM *cena, PGM *obj);
Fun��o: Percorre a imagem da cena, calculando a correla��o cruzada em todos os pontos x e y e retornando a posi��o onde houve maior valor
Entrada: Estruturas contendo a imagem da cena (PGM *cena) e a imagem do objeto (PGM *obj)
Sa�da: Posi��o (Ponto) onde houve o maior valor de correla��o cruzada
----------------------------------------------------------------*/


#endif // TP1_H_INCLUDED
