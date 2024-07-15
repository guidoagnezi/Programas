#include <stdio.h>

int EhProduto(char prd);
int AcabaramOsProdutos(char prd);
int QdtProdutoMaisComprado();

int main (){

    int cliente, clientem;
    int prdm = 0, qtdprdm;

    while (1) {

        scanf("%d", &cliente);
        scanf("%*c");

        if (cliente == -1) {
            break;
        }
        qtdprdm = QdtProdutoMaisComprado();

        if (qtdprdm > prdm) {
            prdm = qtdprdm;
            clientem = cliente;
        }
    }
    printf("CLIENT:%d QTD:%d", clientem, prdm);
}

int QdtProdutoMaisComprado() {

    char produto;
    char produtoa;
    int cont = 1, mcont = 0;

    while(1) {
        
        scanf("%c", &produto);

        if (AcabaramOsProdutos(produto)) {
            break;
        }

        if (EhProduto(produto)) {
            if (produto == produtoa){
                cont++;
            }
            else {
                cont = 1;
            }
        }
        if (cont > mcont) {
            mcont = cont;
        }
        produtoa = produto;
    }
    return mcont;
}

int EhProduto(char prd) {
    if (prd >= 65 && prd <= 90) {
        return 1;
    }
    else {
        return 0;
    }
}

int AcabaramOsProdutos(char prd) {
    if (prd == '0') {
        return 1;
    }
    else {
        return 0;
    }
}