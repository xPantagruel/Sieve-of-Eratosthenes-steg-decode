// ppm.c
// Řešení IJC-DU1, příklad b)
// Autor: Matej Macek, FIT
// Datum: 20.03.2022
//nacte obrazek formatu .ppm a vlozi ho do struktury
#include "ppm.h"
#include <stdio.h>
#include "error.h"
#include <string.h>
#include <stdlib.h>

struct ppm * ppm_read(const char * filename){
    unsigned xsize;
    char type[3]; // typ souboru .ppm
    int color;      // 255
    unsigned ysize;


    FILE * file_for_read;

    //otevreni soubouru pro cteni
    if ((file_for_read = fopen(filename,"r"))==NULL)
    {
        warning_msg("Nelze otevrit %s \n",filename);
        return NULL;
    }

    //uklada xsize,type, color, ysize
    //pokud fscang nenacte 4 promenne vypise warning message
    if ((fscanf(file_for_read," %s %u %u %d ",type,&xsize,&ysize, &color))<4)
    {
        warning_msg("Chybny soubor %s ,chyba v identifikatorech ppm hlavicce\n ",file_for_read);
        fclose(file_for_read);
        return NULL;
    }

    //retezec porovna jestli type == P6
    if(strcmp(type, "P6"))
    {
        warning_msg("Chybna binarni varianta v hlavicce '%s' \n ",file_for_read);
        fclose(file_for_read);
        return NULL;
    }

    //xsize musi byt vetsi jak 0
    if(xsize <= 0)
    {
        warning_msg("Chybna xsize v hlavicce '%s' \n ",file_for_read);
        fclose(file_for_read);
        return NULL;
    }

    //ysize musi byt vetsi jak 0
    if(ysize <= 0)
    {
        warning_msg("Chybna ysize v hlavicce '%s' \n ",file_for_read);
        fclose(file_for_read);
        return NULL;
    }

    //spectrum musi byt mezi 0 - 255
    if(color < 0 || color > 255)
    {
        warning_msg("Chyba v hlavicce '%s', spatny identifikator barev \n ",file_for_read);
        fclose(file_for_read);
        return NULL;
    }

    //definovani nove struktury
    struct ppm *data_ppm; //vytvareni data_ppm, ktera slouzi pro data
    size_t data_size = xsize * ysize * 3;//ppm velikost dat
    data_ppm = malloc(sizeof(struct ppm) + data_size);//alokace data_ppm

    //nastaveni xsize a ysize v strukture
    data_ppm->xsize= xsize;
    data_ppm->ysize= ysize;

    //pomoci fread nacteni dat do struktury
    if(fread(data_ppm->data, sizeof(char), data_size, file_for_read) != data_size)
    {
        fclose(file_for_read);
        warning_msg("U zapisovani dat do struktury");
        return NULL;
    }

    fclose(file_for_read);
    return data_ppm;
}

//funkce uvolni pamet
void ppm_free(struct ppm *p){
    free(p);
}