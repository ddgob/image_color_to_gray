#include "imagem.hpp"

/*
Descricao: retorna uma string com o codigo 
do tipo da imagem

Entrada: nao tem

Saida: string com o codigo do tipo de imagem
*/
string Imagem::getTipoImag() {
    return tipoImag;
}


/*
Descricao: retorna inteiro com o numero de 
linhas da imagem

Entrada: nao tem

Saida: inteiro com o numero de linhas da
imagem
*/
int Imagem::getNumLinhas() {
    return numLinhas;
}


/*
Descricao: retorna inteiro com o numero de 
colunas da imagem 

Entrada: nao tem

Saida: inteiro com o numero de colunas da 
imagem
*/
int Imagem::getNumColunas() {
    return numColunas;
}


/*
Descricao: retorna inteiro com o valor
maximo que uma cor pode assumir 

Entrada: nao tem

Saida: inteiro com o valor maximo que
uma cor pode assumir 
*/
int Imagem::getValorCorMax() {
    return valorCorMax;
}


/*
Descricao: atribui o codigo passado como
parametro ao atributo do tipo da imagem

Entrada: string com o codigo do tipo da
imagem 

Saida: nao tem
*/
void Imagem::setTipoImag(string tipoImag_) {
    tipoImag = tipoImag_;
}


/*
Descricao: atribui o inteiro passado como 
parametro ao numero de linhas da imagem

Entrada: inteiro com o numero de linhas 
da imagem 

Saida: nao tem
*/
void Imagem::setNumLinhas(int numLinhas_) {
    numLinhas = numLinhas_;
}


/*
Descricao: atribui o inteiro passado como 
parametro ao numero de colunas da imagem

Entrada: inteiro com o numero de colunas 
da imagem 

Saida: nao tem
*/
void Imagem::setNumColunas(int numColunas_) {
    numColunas = numColunas_;
}


/*
Descricao: atribui o inteiro passado como 
parametro ao valor maximo que uma cor 
da imagem pode assumir 

Entrada: inteiro com o valor maximo que uma 
cor da imagem pode assumir

Saida: nao tem
*/
void Imagem::setValorCorMax(int valorCorMax_) {
    valorCorMax = valorCorMax_;
}