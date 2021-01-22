#include <map>
#include <iostream>
#include "dicomaam.h"
#include "tradmaam.h"
#include "ms.h"

int main(){
    std:: string txt="-.-. --- -.. .";
    std::cout << "la longueur de '-.-. --- -.. . /-- --- .-. ... .' est :" << length(txt)<<std::endl;  // 43
    std::map<std::string,std::string> dicoam= dico1();
    std::map<std::string,std::string> dicoma= dico2();
    std::string a=tradam("BONJOUR LES AMIS VOYONS VOIR SI LE CODE MORSE FONCTIONNE BIEN",dicoam);
    std::cout<<"'BONJOUR LES AMIS VOYONS VOIR SI LE CODE EN MORSE FONCTIONNE BIEN' --->"<<a<<" ET A NOUVEAU EN ALPHABET: "<< tradma(a,dicoma)<<std::endl; //Renvoie le même texte alphabétique
    std::string mes_a="ET L AUDIO FONCTIONNE AUSSI";
    std:: string mes_m=tradam(mes_a,dicoam);
    std::cout<< "'" + mes_a + "'" << " ---> " << mes_m<<std::endl;
    ms(mes_m);
    return 0;
}