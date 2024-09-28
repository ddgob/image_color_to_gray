#ifndef IMAGEMPPM_HPP
#define IMAGEMPPM_HPP

#include "imagem.hpp"
#include "pixelRGB.hpp"
#include "imagemPGM.hpp"
#include <string>
#include <fstream>
#include <iostream>

class ImagemPPM : public Imagem {

    public:

        ImagemPPM();
        ~ImagemPPM();

        PixelRGB **getMatrizPPM();

        void setElementoMatrizPPM(int linha, int coluna, int vermelho, int verde, int azul);

        void alocarMatrizPPMdinamicamente();

        void lerHeaderArquivoPPM(ifstream &arquivoPPM);
        void lerImagemArquivoPPM(ifstream &arquivoPPM);
        void lerArquivoPPM(string nomeArquivoPPM);

        void converterParaPGM(ImagemPGM &imagemPGM);

        int acessaMatrizPPM();

    private:

        PixelRGB **matrizPPM;
        int id;

};

#endif