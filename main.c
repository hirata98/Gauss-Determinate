#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int posicao=0, ordem=0, contadorD=0, pivo=0;

void print_matriz(float matriz[][ordem]){
    for (int i = 0; i < ordem; ++i) {
        for (int j = 0; j < ordem; ++j)printf("%.2f  ", matriz[i][j]);
        printf("\n");
    }
}
void leitura(float matriz[][ordem]){
    for (int i = 0; i < ordem; ++i) {
        for (int j = 0; j < ordem; ++j) {
            printf("Entre com %d VALOR da LINHA %d: ", j+1, i+1);
            scanf(" %f", &matriz[i][j]);
        }
    }
}
void pivotacao(float matriz[][ordem]) {
    float aux[ordem];
    int cont=0;
    for (int i = posicao; i < ordem; ++i) {
        if (fabsf(matriz[posicao][posicao]) < fabsf(matriz[i][posicao])){
            printf("TROCA linha %d pela linha %d\n\n", posicao+1, i+1);
            for (int j = 0; j < ordem; ++j) {
                aux[j] = matriz[posicao][j];
                matriz[posicao][j] =  matriz[i][j];
                matriz[i][j] = aux[j];
            }
            //cont =1;
            contadorD++;
            print_matriz(matriz);
        }
    }
    //if (cont == 1) contadorD++;
   // cont=0;
    posicao++;
}
void contas(float matriz[][ordem]){
    float A;
    for (int i = 0; i < ordem-1; ++i) {
        if (i+posicao >= ordem){
        }else {
            A = -(matriz[i + posicao][pivo] / matriz[pivo][pivo]);
            printf("A = -(%.2f/%2.f)\n", matriz[i + posicao][pivo], matriz[pivo][pivo]);
            printf("L%d = A*L%d + L%d\n\n", i + posicao + 1, pivo + 1, i + posicao + 1);
            for (int j = 0; j < ordem; ++j) matriz[i + posicao][j] = (A * matriz[pivo][j]) + matriz[i + posicao][j];
            print_matriz(matriz);
        }
    }
    pivo++;
    pivotacao(matriz);
}
int main(){
    printf("ENTRE COM A ORDEM: ");
    scanf("%d", &ordem);
    while (ordem >10){
        printf("Maior ordem e 10\n");
        scanf("%d", &ordem);
    }
    float determinate[ordem], D=1;
    int n=0;
    float matriz[ordem][ordem];
    for (int i = 0; i < ordem; ++i) {
        determinate[i]=0;
        for (int j = 0; j < ordem; ++j) {
            matriz[i][j] = 0;
        }
    }
    leitura(matriz);
    print_matriz(matriz);
    pivotacao(matriz);
    while (n < ordem){
        contas(matriz);
        n++;
    }
    for (int i = 0; i < ordem; ++i) {
        determinate[i] = matriz[i][i];
        D = D*determinate[i];
    }
    if (contadorD%2 != 0) D = D*(-1);
    printf("DETERMINATE VALE: %.2f\n", D);

    return 0;
}

