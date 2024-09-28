#ifndef PIXELRGB_HPP
#define PIXELRGB_HPP

class PixelRGB {
    public:


        int getVermelho();
        int getVerde();
        int getAzul();
        
        void setVermelho(int vermelho_);
        void setVerde(int verde_);
        void setAzul(int azul_);

        int converteRGBparaCinza();

    private:

        int vermelho;
        int verde;
        int azul;

};

#endif