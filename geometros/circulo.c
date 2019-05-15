//
// Created by matheus on 14/05/19.
//

#include "circulo.h"
#include <math.h>

double calculaAreaCirculo(TCIRC *circ){
    return (M_PI * pow(circ->raio, 2));
}

