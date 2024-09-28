#include "imagemPPM.hpp"
#include "imagemPGM.hpp"
#include "msgassert.h"
#include "memlog.h"

/*
Descricao: constroi instancia de uma ImagemPPM

Entrada: nao tem

Saida: nao tem
*/
ImagemPPM::ImagemPPM() {
    matrizPPM = nullptr;
    id = 0;
}


/*
Descricao: Destroi todas as instancias de imagemPPM, 
desalocando memoria alocada dinamicamente da 
para armazenar a matriz de imagem colorida

Entrada: nao tem

Saida: nao tem
*/
ImagemPPM::~ImagemPPM() {
    /*
    Variaveis abaixo criadas para evitar chamadas
    repetidas aos metodos get_____()
    */
    int numLinhas_ = getNumLinhas();
    PixelRGB **matrizPPM_ = getMatrizPPM();

    for(int linha = 0; linha < numLinhas_; linha++) {
        delete[] matrizPPM_[linha];
    }
    delete[] matrizPPM_;
}


/*
Descricao: retorna ponteiro para matriz de imagem 
colorida

Entrada: nao tem

Saida: ponteiro para matriz feita para armazenar uma
imagem colorida
*/
PixelRGB **ImagemPPM::getMatrizPPM() {
    return matrizPPM;
}


/*
Descricao: atribui valor vermelho, verde e azul a um   
elemento (Pixel) de uma matriz de imagem colorida

Entrada: linha em que o elemento que se deseja atribuir
a cor RGB esta, coluna em que o elemento que se deseja atribuir
a cor RGB esta, valor da cor vermelha que se deseja atribuir,
valor da cor verde que se deseja atribuir, valor da cor azul 
que se deseja atribuir

Saida: nao tem
*/
void ImagemPPM::setElementoMatrizPPM(int linha, int coluna, int vermelho, int verde, int azul) {
    /*
    Verifica se valores de cor de cada pixel 
    estao dentro dos limites de cor permitidos
    */ 
    erroAssert(vermelho <= valorCorMax && vermelho >= 0,
    "Vermelho utilizado em um dos pixeis da imagem PGM nao esta dentro do limite de cor permitido");
    erroAssert(verde <= valorCorMax && verde >= 0,
    "Verde utilizado em um dos pixeis da imagem PGM nao esta dentro do limite de cor permitido");
    erroAssert(azul <= valorCorMax && azul >= 0,
    "Azul utilizado em um dos pixeis da imagem PGM nao esta dentro do limite de cor permitido");

    PixelRGB **matrizPPM_ = getMatrizPPM();
    matrizPPM_[linha][coluna].setVermelho(vermelho);
    matrizPPM_[linha][coluna].setVerde(verde);
    matrizPPM_[linha][coluna].setAzul(azul);
    ESCREVEMEMLOG((long int)(&(matrizPPM[linha][coluna])),sizeof(int),id);
    ESCREVEMEMLOG((long int)(&(matrizPPM[linha][coluna])),sizeof(int),id);
    ESCREVEMEMLOG((long int)(&(matrizPPM[linha][coluna])),sizeof(int),id);
}



/*
Descricao: aloca memoria dinamicamente para 
armazenar matriz de imagem colorida 

Entrada: nao tem

Saida: nao tem
*/
void ImagemPPM::alocarMatrizPPMdinamicamente() {
    /*
    Variaveis abaixo criadas para evitar chamadas
    repetidas aos metodos get_____()
    */
    int numLinhas_ = getNumLinhas();
    int numColunas_ = getNumColunas();

    matrizPPM = new PixelRGB*[numLinhas_];
    for(int i = 0; i < numLinhas_; i++) {
        matrizPPM[i] = new PixelRGB[numColunas_];
    }
}


/*
Descricao: le os dados do header de um arquivo
PPM do arquivo PPM passado por referencia, sendo eles: o
codigo do tipo de imagem, numero de colunas e linhas da
imagem (dimensoes) e valor maximo que uma cor da imagem 
pode atingir

Entrada: referencia para arquivo do tipo PPM
(imagem colorida) que pode ser lido

Saida: nao tem
*/
void ImagemPPM::lerHeaderArquivoPPM(ifstream &arquivoPPM) {
    string tipoImag_;
    int numColunas_;
    int numLinhas_;
    int valorCorMax_;
    arquivoPPM >> tipoImag_ >> numColunas_ >> numLinhas_ >> valorCorMax_;

    /*
    Verifica se o formato da imagem PPM eh P3
    
    Verifica que as dimensoes da imagem sao nao nulas

    Verifica se a cor maxima que uma cor de um pixel
    de Imagem PPM eh valida (255)
    */
    erroAssert(tipoImag_ == "P3",
    "Imagem PPM nao esta no formato correto, que seria: P3");
    erroAssert(numLinhas_ > 0,
    "Dimensao da largura da imagem PPM precisa ser maior que 0");
    erroAssert(numColunas_ > 0,
    "Dimensao da altura da imagem PPM precisa ser maior que 0");
    erroAssert(valorCorMax_ == 255,
    "Valor maximo que uma cor de um pixel da imagem PPM precisa ser 255");

    setTipoImag(tipoImag_);
    setNumColunas(numColunas_);
    setNumLinhas(numLinhas_);
    setValorCorMax(valorCorMax_); 
}


/*
Descricao: le os elementos da matriz PPM (imagem colorida) 
do arquivo PPM passado por referencia, guardando os valores
na matriz PPM que foi alocada dinamicamente

Entrada: referencia para arquivo do tipo PPM
(imagem cinza) que pode ser lido

Saida: nao tem
*/
void ImagemPPM::lerImagemArquivoPPM(ifstream &arquivoPPM) {
    /*
    Variaveis temporarias para guardar cores do pixel
    daquele loop
    */
    int tempVermelho;
    int tempVerde;
    int tempAzul;

    /*
    Variaveis abaixo criadas para evitar chamadas
    repetidas aos metodos get_____()
    */
    int numLinhas_ = getNumLinhas();
    int numColunas_ = getNumColunas();
    alocarMatrizPPMdinamicamente();
    acessaMatrizPPM();

    for(int linha = 0; linha < numLinhas_; linha++) {
        for(int coluna = 0; coluna < numColunas_; coluna++) {
            arquivoPPM >> tempVermelho >> tempVerde >> tempAzul;
            setElementoMatrizPPM(linha, coluna, tempVermelho, tempVerde, tempAzul);
        }
    }

}


/*
Descricao: abre arquivo PPM que pode ser lido e chama
os metodos que leem o header e a imagem (matriz cinza)
do arquivo PPM 

Entrada: nome do arquivo PPM a ser aberto e lido

Saida: nao tem
*/
void ImagemPPM::lerArquivoPPM(string nomeArquivoPPM) {
    ifstream arquivoPPM;
    arquivoPPM.open(nomeArquivoPPM);

    // Verifica se arquivo PPM foi aberto corretamente
    erroAssert(arquivoPPM.is_open() == true,
    "Erro ao tentar abrir arquivo PPM");

    lerHeaderArquivoPPM(arquivoPPM);
    lerImagemArquivoPPM(arquivoPPM);
}


/*
Descricao: aloca uma matriz PGM (cinza) dinamicamente
e itera pelos pixeis RGB da matriz PPM (colorida) 
fazendo a conversao do pixel RGB em um valor inteiro de
cinza que eh guardado no na matriz PGM alocada dinamicamente

Entrada: nome do arquivo PPM a ser aberto e lido

Saida: nao tem
*/
void ImagemPPM::converterParaPGM(ImagemPGM &imagemPGM) {
    /*
    Variavel temporaria para guardar o valor de cinza
    daquele loop
    */
    int tempCinza = 0;

    /*
    Variaveis abaixo criadas para evitar chamadas
    repetidas aos metodos get_____()
    */
    int numLinhas_ = getNumLinhas();
    int numColunas_ = getNumColunas();
    PixelRGB **matrizPPM_ = getMatrizPPM();

    imagemPGM.setNumLinhas(numLinhas_);
    imagemPGM.setNumColunas(numColunas_);
    imagemPGM.alocarMatrizPGMdinamicamente();
    acessaMatrizPPM();
    imagemPGM.acessaMatrizPGM();

    for(int linha = 0; linha < numLinhas_; linha++) {
        for(int coluna = 0; coluna < numColunas_; coluna++) {
            tempCinza = matrizPPM_[linha][coluna].converteRGBparaCinza();
            LEMEMLOG((long int)(&(matrizPPM_[linha][coluna])),sizeof(int),id);
            LEMEMLOG((long int)(&(matrizPPM_[linha][coluna])),sizeof(int),id);
            LEMEMLOG((long int)(&(matrizPPM_[linha][coluna])),sizeof(int),id);
            imagemPGM.setElementoMatrizPGM(linha, coluna, tempCinza);
        }
    }
}

int ImagemPPM::acessaMatrizPPM() {
    int temp;
    int soma = 0;

    /*
    Variaveis abaixo criadas para evitar chamadas
    repetidas aos metodos get_____()
    */
    int numLinhas_ = getNumLinhas();
    int numColunas_ = getNumColunas();
    PixelRGB **matrizPPM_ = getMatrizPPM();

    for(int linha = 0; linha < numLinhas_; linha++) {
        for(int coluna = 0; coluna < numColunas_; coluna++) {
            temp = matrizPPM_[linha][coluna].getVermelho();
            soma += temp;
            temp = matrizPPM_[linha][coluna].getVerde();
            soma += temp;
            temp = matrizPPM_[linha][coluna].getAzul();
            soma += temp;
            LEMEMLOG((long int)(&(matrizPPM_[linha][coluna])),sizeof(int),id);
            LEMEMLOG((long int)(&(matrizPPM_[linha][coluna])),sizeof(int),id);
            LEMEMLOG((long int)(&(matrizPPM_[linha][coluna])),sizeof(int),id);
        }
    }

    return soma; // apenas para evitar que acesso seja eliminado
}