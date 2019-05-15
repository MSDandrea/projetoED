//
// Created by matheus on 14/05/19.
//

#ifndef PROJETOED_GEOMETRO_H
#define PROJETOED_GEOMETRO_H


double calculaArea(void *geometro);

void*  criaGeometro(char *id, double* lados);

void* criaGeometroPorString(char* str);
#endif //PROJETOED_GEOMETRO_H
