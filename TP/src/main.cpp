#include <iostream>
#include <fstream>
#include <getopt.h>
#include "imagem.hpp"
#include "imagemPGM.hpp"
#include "imagemPPM.hpp"
#include "pixelRGB.hpp"
#include "memlog.h"
#include <time.h>
#include <string.h>
#include "msgassert.h"

using namespace std;

int main(int argc, char* argv[]) {

    extern char*optarg;
    int flag;
    string nomeArquivoPPM;
    bool nomeArquivoPPMpassdoTerminal = false;
    string nomeArquivoPGM;
    bool nomeArquivoPGMpassdoTerminal = false;
    bool memLogAtivado = false;
    bool memLogIniciado = false;
    char nomeLog[100];

    /*
    Faz a leitura dos comandos passados 
    por terminal
    */
    while((flag = getopt(argc, argv, "i:o:p:l")) != EOF) {
        switch(flag) {
            case 'i':
                nomeArquivoPPM = optarg;
                nomeArquivoPPMpassdoTerminal = true;
                break;
            case 'o':
                nomeArquivoPGM = optarg;
                nomeArquivoPGMpassdoTerminal = true;
                break;
            case 'p':
                strcpy(nomeLog,optarg);
                iniciaMemLog(nomeLog);
                desativaMemLog();
                memLogIniciado = true;
                break;
            case 'l':
                memLogAtivado = true;
                ativaMemLog();
                break;
            default:
                exit(1);
        }
    }

    /*
    Verifica se nome do arquivo PPM de entrada
    e nome arquivo PGM de saida foram passados 
    no terminal
    */
    erroAssert(nomeArquivoPPMpassdoTerminal == true,
    "eh necessario passar o nome do arquivo PPM de entrada no terminal pela flag -i");
    erroAssert(nomeArquivoPGMpassdoTerminal == true,
    "eh necessario passar o nome do arquivo PGM de saida no terminal pela flag -p");

    /*
    Evita que memlog seja ativado antes de ser
    iniciado, fazendo com que os registros de
    acesso nao seja escritos no arquivo de
    registros de acesso
    */
    if(memLogAtivado == true && memLogIniciado == true) {
        ativaMemLog();
    }

    /*
    Verifica que o nome do arquivo de registro de
    acesso seja passado no terminal pela flag -p
    para que sejam gravados os registros de acesso
    requeridos pela flag -l
    */
    if(memLogAtivado == true && memLogIniciado == false) {
        erroAssert(memLogAtivado == false,
        "eh necessario passar o nome do arquivo de registros no terminal pela flag -p para que sejam gravados os registros de acesso requeridos pela flag -l");
    }

    defineFaseMemLog(0);
    // Inicializa uma imagem PPM
    ImagemPPM imagemPPM;
    // Inicializa uma imagem PGM
    ImagemPGM imagemPGM;

    /*
    Le o arquivo PPM cujo nome foi passado 
    por terminal e guarda os dados na
    imagemPPM criada anteriormente
    */
    imagemPPM.lerArquivoPPM(nomeArquivoPPM);

    defineFaseMemLog(1);
    /*
    Converte a imagemPPM e em uma imagem
    PGM e salva na imagemPGM criada
    anteriormente
    */
    imagemPPM.converterParaPGM(imagemPGM);

    defineFaseMemLog(2);
    /*
    Escreve os dados da imagemPGM criada 
    anteriormente em um arquivo PGM cujo 
    nome foi passado por terminal
    */
    imagemPGM.escreverArquivoPGM(nomeArquivoPGM);

    if(memLogIniciado == true) {
        return finalizaMemLog();
    }else {
        return 0;
    }
}
