#include "pixelRGB.hpp"
#include "msgassert.h"

/*
Descricao: retorna um inteiro com o valor 
de vermlho do pixel

Entrada: nao tem

Saida: inteiro com o valor de vermlho do
pixel
*/
int PixelRGB::getVermelho() {
    return vermelho;
}


/*
Descricao: retorna um inteiro com o valor 
de verde do pixel

Entrada: nao tem

Saida: inteiro com o valor de verde do
pixel
*/
int PixelRGB::getVerde() {
    return verde;
}


/*
Descricao: retorna um inteiro com o valor 
de azul do pixel

Entrada: nao tem

Saida: inteiro com o valor de azul do
pixel
*/
int PixelRGB::getAzul() {
    return azul;
}


/*
Descricao: atribui o inteiro passado como 
parametro ao valor de vermelho do pixel

Entrada: inteiro com o valor de vermelho 
do pixel

Saida: nao tem
*/
void PixelRGB::setVermelho(int vermelho_){
    vermelho = vermelho_;
}


/*
Descricao: atribui o inteiro passado como 
parametro ao valor de verde do pixel

Entrada: inteiro com o valor de verde 
do pixel

Saida: nao tem
*/
void PixelRGB::setVerde(int verde_){
    verde = verde_;
}


/*
Descricao: atribui o inteiro passado como 
parametro ao valor de azul do pixel

Entrada: inteiro com o valor de azul 
do pixel

Saida: nao tem
*/
void PixelRGB::setAzul(int azul_){
    azul = azul_;
}


/*
Descricao: retorna a conversao dos valores
vermelho, verde e azul para um inteiro no
espectro cinza

Entrada: nao tem

Saida: inteiro no espectro cinza
*/
int PixelRGB::converteRGBparaCinza() {
    int Y = ((49.0/255.0) * ((0.3 * getVermelho()) + (0.59 * getVerde()) + (0.11 * getAzul())));

    /*
    Verifica se funcao Y retorna valor dentro do intervalo [0, 49]
    */ 
    erroAssert(Y >= 0 && Y <= 49,
    "A conversao de RGB para cinza ultrapassou o intervalo de [0, 49]");
    return Y;
}