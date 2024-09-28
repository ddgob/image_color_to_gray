#ifndef IMAGEM_HPP
#define IMAGEM_HPP

#include <string>

using namespace std;

class Imagem {
    public:

        string getTipoImag();
        int getNumLinhas();
        int getNumColunas();
        int getValorCorMax();

        void setTipoImag(string tipoImag_);
        void setNumLinhas(int numLinhas_);
        void setNumColunas(int numColunas_);
        void setValorCorMax(int valorCorMax_);
        
    protected:

        string tipoImag;
        int numLinhas;
        int numColunas;
        int valorCorMax;

};

#endif