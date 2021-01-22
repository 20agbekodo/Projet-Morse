#include<iostream>

int length(std::string mes){            // Mesure la longueur "en point" du signal
    int l=0;
    for(char c: mes){
        if(c=='.'){                      // 2 points (1 point de bruit + 1 point de silence intermédiaire)
            l+=1+1;
        }
        if(c=='-'){                         // 4 points (3 point de bruit + 1 point de silence intermédiaire)
            l+=3+1; 
        }  
        if (c==' '){                         // 3 points de silence
            l+=3;
        }  
        if(c=='/'){
            l+=7;                             // 7 points de silence
        }
    }
    return l;
}
