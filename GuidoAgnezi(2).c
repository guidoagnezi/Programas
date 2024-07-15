#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//componentes do jogo (structs) -----------------------------------------------------------------------------------------

typedef struct {

    int x;      //coordenadas
    int y;

} player;

typedef struct {

    int x;  //coordenadas
    int y;
    int fileira; //parametros de leitura;
    int indice;
    int iteMorte; //numero da iteracao quando morreu
    int linMorte; //linha quando morreu
    int vivo;   //se esta vivo
    

} inimigo;

typedef struct{

    int x;  //coordenadas
    int y;
    int existe; //se esta ativo

} tiro;

typedef struct {

    int x;  //tamanho do mapa
    int y;
    player player;
    inimigo inimigos[50];
    char desenho[3][9];
    tiro tiro;
    int qtdinimigos; 
    int animacao;   //flag para ativar animacao
    int direcao; //esquerda ou direita
    int condicao; //condicao para vencer = ter 0 inimigos
    int pontos;
    int rodadas; //iteracoes 
    //contadores para estatisticas e outros
    int contM, contTE, contNE, contD; //contadores de movimentos, tiros efetivos, nao efetivos e decidas
    //heatmap
    int heatmap[100][200]; 
    

} mapa;

//funcoes ---------------------------------------------------------------------------------------

mapa MudancaMapa(mapa mapa, char *argv[]);

/*
atualiza as posicoes, estados, eventos e recebe os comandos da entrada padrao
registra atualizacoes do resumo
*/

mapa DefineMapa(FILE *arq, FILE *arq2, mapa mapa);

/*
recebe os parametros dos arquivos mapa e inimigo.txt para dar inicio ao jogo
*/

void DesenhaMapa(mapa mapa);

/*
imprime a tela do jogo com as informacoes atualizadas de MudancaMapa()
*/

void MensagemFinal(mapa mapa, int i);

/*
imprime a mensagem de vitoria ou derrota no fim do jogo
*/

int FinalizarJogo(mapa mapa);

/*
verifica se as condicoes para encerrar o jogo foram cumpridas, e o encerra caso sim
*/

void CriarArquivosDeSaida(char *argv[]);

/*
cria os arquivos de saida na pasta de saida para serem modificados com o passar do jogo
*/

void GerarInicializacao(mapa mapa, char *argv[]);

/*
cria inicializacao.txt e imprime a tela inicial do jogo no arquivo
*/

void RegistrarResumo(mapa mapa, inimigo inimigo, tiro tiro, int evento, char *argv[]);

/*
atualiza o arquivo de saida resumo.txt a partir de eventos determinados
a funcao recebe uma flag de evento correspondente aos 5 eventos possiveis no jogo
*/

void GerarEstatisticas(mapa mapa, char *argv[]);

/*
atualiza o arquivo de saida estatistacas.txt com as informacoes registradas pelo mapa
*/

void GerarRanking(mapa mapa, char *argv[]);

/*
gera o arquivo ranking e organiza a patente de morte de cada inimigo derrotado
*/

mapa GerarHeatmap(mapa mapa, char *argv[]);

/*
atualiza o mapa de calor do player com o passar do jogo
*/

//main -----------------------------------------------------------------------------------------------

int main(int argc, char *argv[]){

    FILE *arq, *arq2;
    mapa mapa;
    char endereco[1000];

    //abre os arquivos de configuracao

    if (argc != 2) {
        printf("ERRO: Informe o diretorio com os arquivos de configuracao.\n");
        exit(1);
    }

    strcpy(endereco, argv[1]);
    strcat(endereco, "/mapa.txt");

    //mapa
    arq = fopen (endereco, "r");

        if (arq == NULL) {
            printf("ERRO: Nao foi possivel abrir o arquivo '%s'.\n", endereco);
            exit(1);
        }

    strcpy(endereco, argv[1]);
    strcat(endereco, "/inimigo.txt");

    //inimigos
    arq2 = fopen (endereco, "r");

        if (arq2 == NULL) {
            printf("ERRO: Nao foi possivel abrir o arquivo '%s'.\n", endereco);
            exit(1);
        }

    mapa = DefineMapa(arq, arq2, mapa); //CONFIGURAÇÕES INICIAIS

    fclose(arq2);

    fclose(arq);

    //realiza o jogo

    GerarInicializacao(mapa, argv);

    CriarArquivosDeSaida(argv);

    mapa = GerarHeatmap(mapa, argv);

    DesenhaMapa(mapa);

    while(1){

    if (FinalizarJogo(mapa) == 1 || FinalizarJogo(mapa) == 0) {

        MensagemFinal(mapa, FinalizarJogo(mapa));
        break;
    }

    mapa = MudancaMapa(mapa, argv);
    mapa = GerarHeatmap(mapa, argv);
    DesenhaMapa(mapa);
        
    }

    GerarEstatisticas(mapa, argv);
    GerarRanking(mapa, argv);

    return 0;
    
}

//funções ---------------------------------------------------------------------------------------------

mapa DefineMapa(FILE *arq, FILE *arq2, mapa mapa){

int i = 0;
int fileira = 0;
int indice = 1;
char c;

//definicoes iniciais (inicializacao de parametros)
mapa.qtdinimigos = 0;
mapa.direcao = 0;
mapa.tiro.existe = 0;
mapa.pontos = 0;
mapa.rodadas = 0;
mapa.contD = 0;
mapa.contM = 0;
mapa.contNE = 0;
mapa.contTE = 0;
    
    //le mapa e player

    fscanf(arq, "%d %d\n(%d %d)", &mapa.y, &mapa.x, &mapa.player.y, &mapa.player.x);

    mapa.x = mapa.x + 2;
    mapa.y = mapa.y + 2;

    //le mapa e inimigo

    while (fscanf(arq, "%c", &c) == 1){
        
        if (c == '('){

            indice++;
            fscanf(arq, "%d %d)", &mapa.inimigos[i].y, &mapa.inimigos[i].x); //le as coordenadas

            //inicializa parametros dos inimigos

            mapa.inimigos[i].vivo = 1;
            mapa.inimigos[i].iteMorte = 0;
            mapa.inimigos[i].linMorte = 0;
            mapa.inimigos[i].fileira = fileira;
            mapa.inimigos[i].indice = indice;
            mapa.qtdinimigos++;
            i++;

        }
        if (c == '\n'){ 
            fileira++;
            indice = 0;
        }
    }
    
    //define desenho do inimigos

    int j = 0, k = 0; 

    fscanf(arq2, "%d", &mapa.animacao);

        for (k = 0; k < 3; k++){

            for (j = 0; j < 9; j++) {
            
            fscanf(arq2, "%c", &c);

            if (c != '\n'){

                mapa.desenho[k][j] = c;

            }
            else {

                j = j - 1;

            }
        }
    }


    mapa.condicao = mapa.qtdinimigos; //atribui a quantidade de inimigos como meta para cumprir a condicao

    //zera o heatmap

    for (i = 0; i <= 100; i++){
        for (j = 0; j <= 200; j++){
            mapa.heatmap[i][j] = 0;
        }
    }

    return mapa;
}

void DesenhaMapa(mapa mapa){

    int i = 0, j = 0, k = 0;
    int vazio = 0;

    printf("Pontos: %d | Iteracoes: %d\n", mapa.pontos, mapa.rodadas);

    for (i = 0; i < mapa.x; i++){
        
        for (j = 0; j < mapa.y; j++){
            
            vazio = 0;

            //bordas
            
            if (i == 0 || i == mapa.x - 1) {

                if (j == mapa.y - 1 || j == 0) {
                    vazio = 1;
                    printf("+");
                }
                else {
                    vazio = 1;
                    printf("-");
                }
            }

            else if (j == 0 || j == mapa.y - 1){

                if (i == mapa.x - 1 || i == 0){
                    vazio = 1;
                    printf("+");
                }

                else if (i == mapa.player.x - 2) {
                    vazio = 1;
                    printf("-");
                }

                else {
                    vazio = 1;
                    printf("|");
                }
            }

            //printa tiro

            if (mapa.tiro.existe && vazio == 0) {

                if (mapa.tiro.x == i && mapa.tiro.y == j) {
                    printf("o");
                    vazio = 1;
                }
            }
            

           
            

            //printa inimigos
            if (mapa.animacao == 0){
            
                for (k = 0; k < mapa.qtdinimigos; k++) { // s/ animação

                    if (vazio == 0 && mapa.inimigos[k].vivo){

                    if (i == mapa.inimigos[k].x - 1 && j == mapa.inimigos[k].y - 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[0][0]);
                    }
                    else if (i == mapa.inimigos[k].x - 1 && j == mapa.inimigos[k].y){
                    vazio = 1;
                    printf("%c", mapa.desenho[0][1]);
                    }
                    else if (i == mapa.inimigos[k].x - 1 && j == mapa.inimigos[k].y + 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[0][2]);
                    }
                    else if (i == mapa.inimigos[k].x && j == mapa.inimigos[k].y - 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[0][3]);
                    }
                    else if (i == mapa.inimigos[k].x && j == mapa.inimigos[k].y){
                    vazio = 1;
                    printf("%c", mapa.desenho[0][4]);
                    }
                    else if (i == mapa.inimigos[k].x && j == mapa.inimigos[k].y + 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[0][5]);
                    }
                    else if (i == mapa.inimigos[k].x + 1 && j == mapa.inimigos[k].y - 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[0][6]);
                    }
                    else if (i == mapa.inimigos[k].x + 1 && j == mapa.inimigos[k].y){
                    vazio = 1;
                    printf("%c", mapa.desenho[0][7]);
                    }
                    else if (i == mapa.inimigos[k].x + 1 && j == mapa.inimigos[k].y + 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[0][8]);
                    }  
                }
                }
            }

            if (mapa.animacao == 1){
            
                for (k = 0; k < mapa.qtdinimigos; k++) { // c/ animação

                    if (vazio == 0 && mapa.inimigos[k].vivo){

                    if (i == mapa.inimigos[k].x - 1 && j == mapa.inimigos[k].y - 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[mapa.rodadas % 3][0]);
                    }
                    else if (i == mapa.inimigos[k].x - 1 && j == mapa.inimigos[k].y){
                    vazio = 1;
                    printf("%c", mapa.desenho[mapa.rodadas % 3][1]);
                    }
                    else if (i == mapa.inimigos[k].x - 1 && j == mapa.inimigos[k].y + 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[mapa.rodadas % 3][2]);
                    }
                    else if (i == mapa.inimigos[k].x && j == mapa.inimigos[k].y - 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[mapa.rodadas % 3][3]);
                    }
                    else if (i == mapa.inimigos[k].x && j == mapa.inimigos[k].y){
                    vazio = 1;
                    printf("%c", mapa.desenho[mapa.rodadas % 3][4]);
                    }
                    else if (i == mapa.inimigos[k].x && j == mapa.inimigos[k].y + 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[mapa.rodadas % 3][5]);
                    }
                    else if (i == mapa.inimigos[k].x + 1 && j == mapa.inimigos[k].y - 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[mapa.rodadas % 3][6]);
                    }
                    else if (i == mapa.inimigos[k].x + 1 && j == mapa.inimigos[k].y){
                    vazio = 1;
                    printf("%c", mapa.desenho[mapa.rodadas % 3][7]);
                    }
                    else if (i == mapa.inimigos[k].x + 1 && j == mapa.inimigos[k].y + 1){
                    vazio = 1;
                    printf("%c", mapa.desenho[mapa.rodadas % 3][8]);
                    }  
                }
                }
            }

            //printar player

            if (vazio == 0){
            if (i == mapa.player.x - 1 && j == mapa.player.y - 1){
                vazio = 1;
                printf("M");
            }
            else if (i == mapa.player.x - 1 && j == mapa.player.y){
                vazio = 1;
                printf(" ");
            }
            else if (i == mapa.player.x - 1 && j == mapa.player.y + 1){
                vazio = 1;
                printf("M");
            }
            else if (i == mapa.player.x && j == mapa.player.y - 1){
                vazio = 1;
                printf("M");
            }
            else if (i == mapa.player.x && j == mapa.player.y){
                vazio = 1;
                printf("M");
            }
            else if (i == mapa.player.x && j == mapa.player.y + 1){
                vazio = 1;
                printf("M");
            }
            else if (i == mapa.player.x + 1 && j == mapa.player.y - 1){
                vazio = 1;
                printf("M");
            }
            else if (i == mapa.player.x + 1 && j == mapa.player.y){
                vazio = 1;
                printf("M");
            }
            else if (i == mapa.player.x + 1 && j == mapa.player.y + 1){
                vazio = 1;
                printf("M");
            }
            }

    //ocupa lugar vazio com espaco
    if (vazio == 0) {
        printf(" ");
    }

    //pular linha

            if (j == mapa.y - 1) {
                    printf("\n");
            }
        }
    }
}

mapa MudancaMapa(mapa mapa, char *argv[]) {

    char c;
    char input[100];
    int k, i;
    int desceu = 0;
    int atirou = 0;

    if (fgets(input, sizeof(input), stdin) != NULL) {
        c = input[0];
    }


    //atualizações-------------------------

    //tiro

    if (mapa.tiro.existe == 1) {

        if (mapa.tiro.x == 1) {
            mapa.tiro.existe = 0;
            mapa.contNE++;
        }

        for (k = 0; k < mapa.qtdinimigos; k++){ //verifica se acertou inimigo

            if (mapa.inimigos[k].vivo && mapa.tiro.x >= mapa.inimigos[k].x - 1 && mapa.tiro.x <= mapa.inimigos[k].x + 1 &&
            mapa.tiro.y >= mapa.inimigos[k].y - 1 && mapa.tiro.y <= mapa.inimigos[k].y + 1 && !atirou){

                RegistrarResumo(mapa, mapa.inimigos[k], mapa.tiro, 5, argv);

                mapa.inimigos[k].vivo = 0;
                mapa.inimigos[k].iteMorte = mapa.rodadas;
                mapa.inimigos[k].linMorte = (mapa.x - 1) - mapa.tiro.x;

                mapa.pontos += (mapa.x - mapa.inimigos[k].x - 2)  * (mapa.inimigos[k].y); //recebe pontos

                mapa.tiro.existe = 0;

                mapa.condicao--; //registra menos um inimigo

            }

        }

        //movimentacao do tiro
        if (atirou == 0){
            mapa.tiro.x--;
        }
    }

    //inimigos

    if (mapa.direcao == 0){ //para a direira

    for (k = 0; k < mapa.qtdinimigos; k++){ //descer ou nao

            if (mapa.inimigos[k].vivo && mapa.inimigos[k].y == mapa.y - 3){

                RegistrarResumo(mapa, mapa.inimigos[k], mapa.tiro, 1, argv);
            }
    }

        for (k = 0; k < mapa.qtdinimigos; k++){

            if (mapa.inimigos[k].vivo && mapa.inimigos[k].y == mapa.y - 3){

                if (!desceu) {

                
                mapa.contD++;

                for(i = 0; i < mapa.qtdinimigos; i++){

                    mapa.inimigos[i].x++;

                }

                desceu = 1;
                mapa.direcao = 1; //ir para a esquerda na proxima
                break;
                
            }
            }
            if (desceu) {
                break;
            }

        }

        if (!desceu){

            for (k = 0; k < mapa.qtdinimigos; k++){ 

                mapa.inimigos[k].y++; //movimentacao para a direita

            }
        }
    }

        else if (mapa.direcao == 1){ //para a esquerda

        for (k = 0; k < mapa.qtdinimigos; k++){ //descer ou nao

            if (mapa.inimigos[k].vivo && mapa.inimigos[k].y == 2){

                RegistrarResumo(mapa, mapa.inimigos[k], mapa.tiro, 2, argv);
            }
        }

        for (k = 0; k < mapa.qtdinimigos; k++){

            if (mapa.inimigos[k].vivo && mapa.inimigos[k].y == 2){

                if (!desceu){
                mapa.contD++;

                for(i = 0; i < mapa.qtdinimigos; i++){

                    mapa.inimigos[i].x++;
                    desceu = 1;
                    mapa.direcao = 0; //ir para a direita na proxima

                }
                }
            }

        }

        if (!desceu){

            for (k = 0; k < mapa.qtdinimigos; k++){ 

                mapa.inimigos[k].y--; //movimentacao para a esquerda

            }
        }
    }
    

    //Comandos------------------------------

    if (c == 'd'){ //vai pra direita

        if (mapa.player.y != mapa.y - 3){
            mapa.player.y++;
            mapa.contM++;
            
        }

        else {
                RegistrarResumo(mapa, mapa.inimigos[0], mapa.tiro, 3, argv); //bateu na parede
            }
        }
        
    if (c == 'a') { //vai pra esquerda

        if (mapa.player.y != 2) {
            mapa.player.y--;
            mapa.contM++;
        
        }

        else  {

            RegistrarResumo(mapa, mapa.inimigos[0], mapa.tiro, 4, argv); //bateu na parede
            
            }
    }

    if (c == ' ') { //atira

        if (mapa.tiro.existe == 0) {
            mapa.tiro.existe = 1;
            mapa.tiro.x = mapa.player.x - 2;
            mapa.tiro.y = mapa.player.y;
            mapa.contTE++;
            atirou = 1;
        }
    }

    mapa.rodadas++; //aumenta iteracao

    return mapa;
}

int FinalizarJogo(mapa mapa){

    int k = 0;

    if (mapa.condicao <= 0) {
        return 1; //ganha
    }

    for(k = 0; k < mapa.qtdinimigos; k++) {

        if (mapa.inimigos[k].vivo && mapa.inimigos[k].x == mapa.player.x - 2) {
            return 0; //perde
        }
    }
    return 2; //continua
}

void MensagemFinal(mapa mapa, int i){

    if (i == 1){

        printf("Parabéns, você ganhou!\n");

    }
    if (i == 0) {

        printf("Você perdeu, tente novamente!\n");
    }
}

void GerarInicializacao(mapa mapa, char *argv[]){ //gerar arquivo de inicializao (foi usado como template a funcao de imprimir o mapa)

    FILE *arq;
    char endereco[1000];

    strcpy(endereco, argv[1]);
    strcat(endereco, "/saida/inicializacao.txt");

    arq = fopen(endereco, "w");

    if (arq == NULL) {
            exit(1);
        }

    int i = 0, j = 0, k = 0;
    int vazio = 0;

    for (i = 0; i < mapa.x; i++){
        
        for (j = 0; j < mapa.y; j++){
            
            vazio = 0;

            //bordas
            
            if (i == 0 || i == mapa.x - 1) {

                if (j == mapa.y - 1 || j == 0) {
                    vazio = 1;
                    fprintf(arq, "+");
                }
                else {
                    vazio = 1;
                    fprintf(arq, "-");
                }
            }

            else if (j == 0 || j == mapa.y - 1){

                if (i == mapa.x - 1 || i == 0){
                    vazio = 1;
                    fprintf(arq, "+");
                }

                else if (i == mapa.player.x - 2) {
                    vazio = 1;
                    fprintf(arq, "-");
                }

                else {
                    vazio = 1;
                    fprintf(arq, "|");
                }
            }

            //printa tiro

            if (mapa.tiro.existe && vazio == 0) {

                if (mapa.tiro.x == i && mapa.tiro.y == j) {
                    fprintf(arq, "O");
                    vazio = 1;
                }
            }
            

            //printa inimigos
            
                for (k = 0; k < mapa.qtdinimigos; k++) { 

                    if (vazio == 0 && mapa.inimigos[k].vivo){

                    if (i == mapa.inimigos[k].x - 1 && j == mapa.inimigos[k].y - 1){
                    vazio = 1;
                    fprintf(arq, "%c", mapa.desenho[0][0]);
                    }
                    else if (i == mapa.inimigos[k].x - 1 && j == mapa.inimigos[k].y){
                    vazio = 1;
                    fprintf(arq, "%c", mapa.desenho[0][1]);
                    }
                    else if (i == mapa.inimigos[k].x - 1 && j == mapa.inimigos[k].y + 1){
                    vazio = 1;
                    fprintf(arq, "%c", mapa.desenho[0][2]);
                    }
                    else if (i == mapa.inimigos[k].x && j == mapa.inimigos[k].y - 1){
                    vazio = 1;
                    fprintf(arq, "%c", mapa.desenho[0][3]);
                    }
                    else if (i == mapa.inimigos[k].x && j == mapa.inimigos[k].y){
                    vazio = 1;
                    fprintf(arq, "%c", mapa.desenho[0][4]);
                    }
                    else if (i == mapa.inimigos[k].x && j == mapa.inimigos[k].y + 1){
                    vazio = 1;
                    fprintf(arq, "%c", mapa.desenho[0][5]);
                    }
                    else if (i == mapa.inimigos[k].x + 1 && j == mapa.inimigos[k].y - 1){
                    vazio = 1;
                    fprintf(arq, "%c", mapa.desenho[0][6]);
                    }
                    else if (i == mapa.inimigos[k].x + 1 && j == mapa.inimigos[k].y){
                    vazio = 1;
                    fprintf(arq, "%c", mapa.desenho[0][7]);
                    }
                    else if (i == mapa.inimigos[k].x + 1 && j == mapa.inimigos[k].y + 1){
                    vazio = 1;
                    fprintf(arq, "%c", mapa.desenho[0][8]);
                    }  
                }
                }

                //printar player

            if (vazio == 0){
            if (i == mapa.player.x - 1 && j == mapa.player.y - 1){
                vazio = 1;
                fprintf(arq, "M");
            }
            else if (i == mapa.player.x - 1 && j == mapa.player.y){
                vazio = 1;
                fprintf(arq, " ");
            }
            else if (i == mapa.player.x - 1 && j == mapa.player.y + 1){
                vazio = 1;
                fprintf(arq, "M");
            }
            else if (i == mapa.player.x && j == mapa.player.y - 1){
                vazio = 1;
                fprintf(arq, "M");
            }
            else if (i == mapa.player.x && j == mapa.player.y){
                vazio = 1;
                fprintf(arq, "M");
            }
            else if (i == mapa.player.x && j == mapa.player.y + 1){
                vazio = 1;
                fprintf(arq, "M");
            }
            else if (i == mapa.player.x + 1 && j == mapa.player.y - 1){
                vazio = 1;
                fprintf(arq, "M");
            }
            else if (i == mapa.player.x + 1 && j == mapa.player.y){
                vazio = 1;
                fprintf(arq, "M");
            }
            else if (i == mapa.player.x + 1 && j == mapa.player.y + 1){
                vazio = 1;
                fprintf(arq, "M");
            }
            }
            
    
    if (vazio == 0) { //ocupar espaco vazio com espaco
        fprintf(arq, " ");
    }

    //pular linha

            if (j == mapa.y - 1) {
                    fprintf(arq, "\n");
            }
        }
    }
    fprintf(arq, "A posicao central do jogador iniciara em (%d %d).", mapa.player.y, mapa.player.x);
    fclose(arq);
}

void RegistrarResumo(mapa mapa, inimigo inimigo, tiro tiro, int evento, char *argv[]){

    //EVENTOS: 1 - bateu na borda direita(inimigo), 2 - bateu na dorda esquerda(inimigo), 3 - bateu na borda direita(player)
    //4 - bateu na dorda esquerda(player), 5 - eliminou inimigo

    FILE *arq;
    char endereco[1000];

    strcpy(endereco, argv[1]);
    strcat(endereco, "/saida/resumo.txt");

    arq = fopen(endereco, "a");

    if (arq == NULL){
            exit(1);
        }

    switch (evento){

        case 1:
        fprintf(arq, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral direita.\n", mapa.rodadas, inimigo.indice, inimigo.fileira);
        break;

        case 2:
        fprintf(arq, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral esquerda.\n", mapa.rodadas, inimigo.indice, inimigo.fileira);
        break;

        case 3:
        fprintf(arq, "[%d] Jogador colidiu na lateral direita.\n", mapa.rodadas + 1);
        break;

        case 4:
        fprintf(arq,  "[%d] Jogador colidiu na lateral esquerda.\n", mapa.rodadas + 1);
        break;

        case 5:
        fprintf(arq, "[%d] Inimigo de indice %d da fileira %d foi atingido na posicao (%d %d).\n", mapa.rodadas, inimigo.indice, inimigo.fileira, tiro.y, tiro.x);
        break;
    }

    fclose(arq);

}

void GerarEstatisticas(mapa mapa, char *argv[]){

    FILE *arq;
    char endereco[1000];

    strcpy(endereco, argv[1]);
    strcat(endereco, "/saida/estatisticas.txt");

    arq = fopen(endereco, "a");

    fprintf(arq, "Numero total de movimentos (A ou D): %d;\nNumero de tiros efetivos: %d;\nNumero de tiros que nao acertaram: %d;\nNumero de descidas dos inimigos: %d;", mapa.contM, mapa.contTE, mapa.contNE, mapa.contD);

    fclose(arq);

}

void GerarRanking(mapa mapa, char *argv[]){

    inimigo aux;
    int i = 0;
    int j = 0;

    for (i = 0; i < mapa.qtdinimigos; i++){ //ordenar

        for(j = 0; j < mapa.qtdinimigos; j++){

            if (mapa.inimigos[i].linMorte < mapa.inimigos[j].linMorte) {
                
                aux = mapa.inimigos[i];
                mapa.inimigos[i] = mapa.inimigos[j];
                mapa.inimigos[j] = aux;

            }

            else if ( mapa.inimigos[i].linMorte == mapa.inimigos[j].linMorte) {

                if (mapa.inimigos[i].iteMorte < mapa.inimigos[j].iteMorte) {

                aux = mapa.inimigos[i];
                mapa.inimigos[i] = mapa.inimigos[j];
                mapa.inimigos[j] = aux;

                }
            }
        }
    }
    
    FILE *arq;
    char endereco[1000];

    strcpy(endereco, argv[1]);
    strcat(endereco, "/saida/ranking.txt");

    arq = fopen(endereco, "a");

    fprintf(arq, "indice,fileira,linha,iteracao\n");

    for (i = 0; i < mapa.qtdinimigos; i++){ //registrar no arquivo

        if (mapa.inimigos[i].vivo == 0) {
            fprintf(arq, "%d,%d,%d,%d\n", mapa.inimigos[i].indice, mapa.inimigos[i].fileira, mapa.inimigos[i].linMorte, mapa.inimigos[i].iteMorte);
        }
    }

    fclose(arq);

}

mapa GerarHeatmap(mapa mapa, char *argv[]){

    int i = 0;
    int j = 0;

    for (i = 0; i < mapa.x; i++){

        for (j = 0; j < mapa.y; j++){

            if (i == mapa.player.x && j == mapa.player.y){
                
                mapa.heatmap[i][j]++;
                if (mapa.heatmap[i][j] >= 999){
                    mapa.heatmap[i][j] = 999;
                }
                mapa.heatmap[i - 1][j]++;
                if (mapa.heatmap[i - 1][j] >= 999){
                    mapa.heatmap[i - 1][j] = 999;
                }
                mapa.heatmap[i + 1][j]++;
                if (mapa.heatmap[i + 1][j] >= 999){
                    mapa.heatmap[i + 1][j] = 999;
                }
                mapa.heatmap[i][j + 1]++;
                if (mapa.heatmap[i][j + 1] >= 999){
                    mapa.heatmap[i][j + 1] = 999;
                }
                mapa.heatmap[i - 1][j + 1]++;
                if (mapa.heatmap[i - 1][j + 1] >= 999){
                    mapa.heatmap[i - 1][j + 1] = 999;
                }
                mapa.heatmap[i + 1][j + 1]++;
                if (mapa.heatmap[i + 1][j + 1] >= 999){
                    mapa.heatmap[i + 1][j + 1] = 999;
                }
                mapa.heatmap[i][j - 1]++;
                if (mapa.heatmap[i][j - 1] >= 999){
                    mapa.heatmap[i][j - 1] = 999;
                }
                mapa.heatmap[i - 1][j - 1]++;
                if (mapa.heatmap[i - 1][j - 1] >= 999){
                    mapa.heatmap[i - 1][j - 1] = 999;
                }
                mapa.heatmap[i + 1][j - 1]++;
                if (mapa.heatmap[i + 1][j - 1] >= 999){
                    mapa.heatmap[i + 1][j - 1] = 999;
                }

            }

            else if (i == mapa.tiro.x && j == mapa.tiro.y && mapa.tiro.existe){
                mapa.heatmap[i][j]++;
                if (mapa.heatmap[i][j] >= 999){
                    mapa.heatmap[i][j] = 999;
                }
            }
        }
    }

    FILE *arq;
    char endereco[1000];

    strcpy(endereco, argv[1]);
    strcat(endereco, "/saida/heatmap.txt");

    arq = fopen(endereco, "w");

    for (i = 1; i < mapa.x - 1; i++){
        for (j = 1; j < mapa.y - 1; j++){

            fprintf(arq, "%3d ", mapa.heatmap[i][j]);

            if (j == mapa.y - 2){
                fprintf(arq, "\n");
            }

        }
    }
    fclose(arq);

    return mapa;
}

void CriarArquivosDeSaida(char *argv[]){

    FILE *arq;
    char endereco[1000];

    strcpy(endereco, argv[1]);
    strcat(endereco, "/saida/resumo.txt");

        arq = fopen(endereco, "w"); //abre resumo

        if (arq == NULL){
            exit(1);
        }

        fclose(arq);

    strcpy(endereco, argv[1]);
    strcat(endereco, "/saida/heatmap.txt"); //abre heatmap

        arq = fopen(endereco, "w");

        if (arq == NULL){
            exit(1);
        }

        fclose(arq);
    
    strcpy(endereco, argv[1]);
    strcat(endereco, "/saida/estatisticas.txt"); //abre estatisticas

        arq = fopen(endereco, "w");

        if (arq == NULL){
            exit(1);
        }

        fclose(arq);

    strcpy(endereco, argv[1]);
    strcat(endereco, "/saida/ranking.txt");

        arq = fopen(endereco, "w"); //abre ranking

        if (arq == NULL){
            exit(1);
        }

        fclose(arq);
    
}
