#ifndef WAVFILE_H
#define WAVFILE_H

#include <stdio.h>
#include <inttypes.h>
                                                         // Wavfile_open créé un fichier relié à un audio
FILE * wavfile_open( const char *filename );
void wavfile_write( FILE *file, short data[], int length );
void wavfile_close( FILE * file );

#define WAVFILE_SAMPLES_PER_SECOND 44100

#endif