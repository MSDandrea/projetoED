//
// Created by matheus on 15/05/19.
//

#ifndef PROJETOED_TRAPEZIO_H
#define PROJETOED_TRAPEZIO_H
typedef struct trapezio{
    char* id;
    double menor_base;
    double maior_base;
    double altura;

}TTRA;
double calculaAreaTrapezio(TTRA* ttra);
#endif //PROJETOED_TRAPEZIO_H
