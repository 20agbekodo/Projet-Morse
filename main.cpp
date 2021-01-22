#include <map>
#include <iostream>
#include "dicomaam.h"
#include "tradmaam.h"
#include "ms.h"

int rm= remove("morse.wav");

 // On demande à l'utilisateur quel sens il veut pour sa traduction
int main(){
    std::cout<<"Morse vers alphabet (taper 'ma') ou alphabet vers morse (taper 'am')?";
    std::string a;
    std::getline(std::cin,a);
    if(a=="ma"){
        std::cout<<"Message à décoder (ex:-.-. --- -.. . /-- --- .-. ... .)"<<std::endl;
        std::string b;
        std::getline (std::cin,b);
        std::map<std::string,std::string> dicoma= dico2();
        std::cout<<tradma(b,dicoma);
    }
    else if(a=="am"){
        std::cout<<"Message à décoder (ex:CODE MORSE)"<<std::endl;
        std::string c;
        std::getline(std::cin,c);
        std::map<std::string,std::string> dicoam= dico1();
        std::string mes=tradam(c,dicoam);
        std::cout<<mes;
        ms(mes);                                             //Fichier audio nommé morse.wav
    }
return 0;
}