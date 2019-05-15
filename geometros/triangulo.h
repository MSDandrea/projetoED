//
// Created by matheus on 15/05/19.
//

#ifndef PROJETOED_TRIANGULO_H
#define PROJETOED_TRIANGULO_H
typedef struct triangulo{
    char* id;
    double base;
    double altura;
}TTRI;
double calculaAreaTriangulo(TTRI* tri);
#endif //PROJETOED_TRIANGULO_H
