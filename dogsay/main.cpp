#include <iostream>
#include <string.h>

int tamanhoVetor(char *arg[], int);
void msgBoasVindas();
void intrucoes();

int main(int argc, char *argv[]){
    int quantUnder = tamanhoVetor(argv, argc);
    if(quantUnder != -1){
        std::cout << "                ";
        for(int i = 1; i <= quantUnder; i++){
            std::cout << "-";
        } 
        std::cout << std::endl;
        std::cout << "                |";
        if(argc > 1){
            for(int i = 1; i<argc; i++){
            std::cout<<argv[i]<<" "; 
            }
        }
        std::cout << "|\n";
        std::cout << "                ";
        for(int i = 1; i <= quantUnder; i++){
            std::cout << "-";
        } 
        std::cout << std::endl;
        std::cout << "                |  /" << std::endl;
        std::cout << "                | /" << std::endl;
        std::cout << "                |/" << std::endl;
        std::cout << "      /^-----^\\   " << std::endl;
        std::cout << "      V  o o  V" << std::endl;
        std::cout << "       |  Y  |" << std::endl;
        std::cout << "        \\ Q /" << std::endl;
        std::cout << "        / - \\" << std::endl;
        std::cout << "        |    \\" << std::endl;
        std::cout << "        |     \\     )" << std::endl;
        std::cout << "        || (___\\====" << std::endl;
    }else{
        msgBoasVindas();
    }
    
    return 0;
}

int tamanhoVetor(char *arg[], int tamanho){
    int tam = 0;
    if(tamanho > 1){
        for(int i = 1; i<tamanho; i++){
            tam += strlen(arg[i]);
        }
        return tam+tamanho;
    }
    return -1;
}

void msgBoasVindas(){
    intrucoes();
    std::cout << "                ";
    std::cout << "-----------------------";    
    std::cout << std::endl;
    std::cout << "                |";
    std::cout << "Boas-vindas ao DogSay";
    std::cout << "|\n";
    std::cout << "                ";
    std::cout << "-----------------------\n";
    std::cout << std::endl;
    std::cout << "                |  /" << std::endl;
    std::cout << "                | /" << std::endl;
    std::cout << "                |/" << std::endl;
    std::cout << "      /^-----^\\   " << std::endl;
    std::cout << "      V  o o  V" << std::endl;
    std::cout << "       |  Y  |" << std::endl;
    std::cout << "        \\ Q /" << std::endl;
    std::cout << "        / - \\" << std::endl;
    std::cout << "        |    \\" << std::endl;
    std::cout << "        |     \\     )" << std::endl;
    std::cout << "        || (___\\====" << std::endl;
}

void intrucoes(){
    std::cout << "-------------------------------------------------------------------------------------\n";
    std::cout << "| Para executar, primeiro compile e depois execute \"./main Mensagem a ser mostrada\" |\n";
    std::cout << "|                                                                Feito por Guilherme|\n";
    std::cout << "-------------------------------------------------------------------------------------\n\n";
}