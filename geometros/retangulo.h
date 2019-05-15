//
// Created by matheus on 15/05/19.
//

#ifndef PROJETOED_RETANGULO_H
#define PROJETOED_RETANGULO_H
typedef struct retangulo{
    char* id;
    double base;
    double altura;
}TRET;

double calculaAreaRetangulo(TRET* ret);
#endif //PROJETOED_RETANGULO_H
