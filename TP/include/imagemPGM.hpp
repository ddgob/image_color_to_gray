#ifndef IMAGEMPGM_HPP
#define IMAGEMPGM_HPP

#include "imagem.hpp"
#include "pixelRGB.hpp"
#include <fstream>
#include <iostream>

class ImagemPGM : public Imagem {

    public:

        ImagemPGM();
        ~ImagemPGM();

        int **getMatrizPGM();

        void setElementoMatrizPGM(int linha, int coluna, int valor);

        void alocarMatrizPGMdinamicamente();

        void escreverHeaderArquivoPGM(ofstream &arquivoPGM);
        void escreverImagemArquivoPGM(ofstream &arquivoPGM);
        void escreverArquivoPGM(string nomeArquivoPGM);

        int acessaMatrizPGM();

    private:

        int **matrizPGM;
        int id;
};


#endif