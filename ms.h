#include <stdio.h>
#include<iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include "wavfile.h"
#include "length.h"

//Morse->son (ms)

const int NUM_SAMPLES = (WAVFILE_SAMPLES_PER_SECOND/5);  //Durée d'un point


void ms (std::string mes)
{
    int len = NUM_SAMPLES*length(mes);  //Longueur audio= (longueur d'un point)*(longueur du message en terme de points)
	short waveform[len];                //Liste numérique correspondant à l'audio
	double frequency = 440.0;           //Caractéristique de l'audio
	int volume;                         //0 ou 32000 selon si on veut un silence ou un bruit
    int duration;                       // Durée dans l'audio correspondant au symbole considéré

    int time=0;                         //Compteur dans la liste waveform pour savoir où on en est
    for(char c:mes){
        if(c=='.'){
            volume=32000;                //Bruit pendant 1 point
            duration=NUM_SAMPLES;
        }
        if(c=='-'){
            volume=32000;                 //Bruit pendant 3 points
            duration=NUM_SAMPLES*3; 
        }  
        if (c==' '){
            volume=0;                    //Silence pendant 3 points (2 points + silence intermédiaire)
            duration=NUM_SAMPLES*2;
        }  
        if(c=='/'){
           volume=0;                      //Silence pendant 7 points (6 points + silence intermédiaire)
           duration=NUM_SAMPLES*6;
        }

	    int i;
	    for(i=time;i<time+duration;i++) {                      // Bruit ou absence de bruit pendant la durée "duration" correspondant au symbole
		double t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
		waveform[i] = volume*sin(frequency*t*2*M_PI);
	    }
        for(i=time+duration;i<time+duration+NUM_SAMPLES;i++){   // Silence intermédiaire
            waveform[i]=0;
        }
        time+=(duration+NUM_SAMPLES);                             // On fait avancer le compteur
    }
	FILE * f = wavfile_open("morse.wav");
	if(!f) {
		printf("couldn't open sound.wav for writing: %s",strerror(errno));
	}

	wavfile_write(f,waveform,len);                                // On met le son dans un fichier relié à l'audio
	wavfile_close(f);
}
