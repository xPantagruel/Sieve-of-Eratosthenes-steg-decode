// ppm.h
// Řešení IJC-DU1, příklad b)
// Autor: Matej Macek, FIT
//Datum: 20.03.2022


#ifndef IJC_1_PPM_H
#define IJC_1_PPM_H

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);
#endif //IJC_1_PPM_H
