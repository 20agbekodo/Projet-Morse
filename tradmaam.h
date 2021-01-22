#include <map>
#include <iostream>

std::string tradma(std::string code, std::map<std::string,std::string> dico){  //Traduction morse->alphabet (ma)
        std::string mes="";    //Futur message décodé
        std::string lettre="";  //String qui se réinitialise à chaque début de lettre
        for(int i=0;i<code.length();i++){
            if (code[i]=='/'){
                mes+=dico[lettre]; //On vient de finir une lettre, donc on peut rajouter sa traduction au message décodé
                mes+=" ";
                lettre=""; //On réinitialise la lettre
            }
            else if(code[i]==' '){
                mes+=dico[lettre];  //On vient de finir une lettre, donc on peut rajouter sa traduction au message décodé
                lettre="";
            }
            else{
                lettre+=code[i];  //On est en plein milieu d'une lettre
            }
        }
        mes+=dico[lettre]; //On rajoute la dernière lettre
        return mes;
}

std::string tradam(std::string code, std::map<std::string,std::string> dico){  //Traduction alphabet->morse (am)
    std::string mes="";
    std::string lettre="";
    for(int i=0;i<code.length();i++){
        if (code[i]==' '){
            mes+="/ ";
        }
        else{
            std::string lettre="";
            lettre+=code[i];   //On créé un string comportant la lettre alphabétique en question
            mes+=dico[lettre]; // Traduction
            mes+=" ";
        }
    }
    return mes;
}