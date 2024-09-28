#include "imagemPGM.hpp"
#include "msgassert.h"
#include "memlog.h"

/*
Descricao: constroi instancia de uma ImagemPGM

Entrada: nao tem

Saida: nao tem
*/
ImagemPGM::ImagemPGM() {
    setTipoImag("P2");
    setValorCorMax(49);
    matrizPGM = nullptr;
    id = 1;
}


/*
Descricao: Destroi todas as instancias de imagemPGM, 
desalocando memoria alocada dinamicamente da 
para armazenar a matriz de imagem cinza

Entrada: nao tem

Saida: nao tem
*/
ImagemPGM::~ImagemPGM() {
    /*
    Variaveis abaixo criadas para evitar chamadas
    repetidas aos metodos get_____()
    */
    int numLinhas_ = getNumLinhas();
    int **matrizPGM_ = getMatrizPGM();

    for(int linha = 0; linha < numLinhas_; linha++) {
        delete[] matrizPGM_[linha];
    }
    delete[] matrizPGM_;
}


/*
Descricao: retorna ponteiro para matriz de imagem cinza

Entrada: nao tem

Saida: ponteiro para matriz feita para armazenar uma
imagem cinza
*/
int **ImagemPGM::getMatrizPGM() {
    return matrizPGM;
}


/*
Descricao: atribui valor a um elemento de uma matriz 
de imagem cinza

Entrada: linha em que o elemento que se deseja atribuir
valor esta, coluna em que o elemento que se deseja atribuir
valor esta, valor que se deseja atribuir

Saida: nao tem
*/
void ImagemPGM::setElementoMatrizPGM(int linha, int coluna, int valor) {
    matrizPGM[linha][coluna] = valor;
    ESCREVEMEMLOG((long int)(&(matrizPGM[linha][coluna])),sizeof(int),id);
}


/*
Descricao: aloca memoria dinamicamente para 
armazenar matriz de imagem cinza 

Entrada: nao tem

Saida: nao tem
*/
void ImagemPGM::alocarMatrizPGMdinamicamente() {
    /*
    Variaveis abaixo criadas para evitar chamadas
    repetidas aos metodos get_____()
    */
    int numLinhas_ = getNumLinhas();
    int numColunas_ = getNumColunas();

    matrizPGM = new int*[numLinhas_];
    for(int i = 0; i < numLinhas_; i++) {
        matrizPGM[i] = new int[numColunas_];
    }
}


/*
Descricao: escreve os dados do header de um arquivo
PGM no arquivo PGM passado por referencia, sendo eles: o
codigo do tipo de imagem, numero de colunas e linhas da
imagem (dimensoes) e valor maximo que uma cor da imagem 
pode atingir 

Entrada: referencia para arquivo do tipo PGM
(imagem cinza) que pode ser escrito

Saida: nao tem
*/
void ImagemPGM::escreverHeaderArquivoPGM(ofstream &arquivoPGM) {
    arquivoPGM << getTipoImag() << endl;
    arquivoPGM << getNumColunas() << " " << getNumLinhas() << endl;
    arquivoPGM << getValorCorMax() << endl;
}


/*
Descricao: escreve os elementos da matriz PGM (imagem cinza) 
no arquivo PGM passado por referencia, separando cada elemento
por um espaco e dando um quebra de linha depois de escrever
o ultimo elemento de cada linha da matriz

Entrada: referencia para arquivo do tipo PGM
(imagem cinza) que pode ser escrito

Saida: nao tem
*/
void ImagemPGM::escreverImagemArquivoPGM(ofstream &arquivoPGM) {
    /*
    Variaveis abaixo criadas para evitar chamadas
    repetidas aos metodos get_____()
    */
    int numLinhas_ = getNumLinhas();
    int numColunas = getNumColunas();
    int **matrizPGM_ = getMatrizPGM();
    acessaMatrizPGM();

    for(int linha = 0; linha < numLinhas_; linha++) {
        for(int coluna = 0; coluna < numColunas; coluna++) {
            arquivoPGM << matrizPGM_[linha][coluna] << " ";
            LEMEMLOG((long int)(&(matrizPGM_[linha][coluna])),sizeof(int),id);
        }
        arquivoPGM << endl;
    }
}


/*
Descricao: cria arquivo PGM que pode ser escrito e chama
os metodos que escrevem o header e a imagem (matriz cinza)
do arquivo PGM 

Entrada: nome do arquivo PGM a ser criado e escrito

Saida: nao tem
*/
void ImagemPGM::escreverArquivoPGM(string nomeArquivoPGM) {
    ofstream arquivoPGM;
    arquivoPGM.open(nomeArquivoPGM);

    // Verifica se arquivo PPM foi aberto corretamente
    erroAssert(arquivoPGM.is_open() == true,
    "Erro ao tentar criar arquivo PGM");

    escreverHeaderArquivoPGM(arquivoPGM);
    escreverImagemArquivoPGM(arquivoPGM);
}


/*
Descricao: acessa matriz para fins de registro de
acesso

Entrada: imagemPGM

Saida: soma
*/
int ImagemPGM::acessaMatrizPGM() {

    int temp;
    int soma = 0;

    /*
    Variaveis abaixo criadas para evitar chamadas
    repetidas aos metodos get_____()
    */
    int numLinhas_ = getNumLinhas();
    int numColunas_ = getNumColunas();
    int **matrizPGM_ = getMatrizPGM();

    for(int linha = 0; linha < numLinhas_; linha++) {
        for(int coluna = 0; coluna < numColunas_; coluna++) {
            temp = matrizPGM_[linha][coluna];
            soma += temp;
            LEMEMLOG((long int)(&(matrizPGM_[linha][coluna])),sizeof(int),id);
        }
    }

    return soma; // apenas para evitar que acesso seja eliminado
}