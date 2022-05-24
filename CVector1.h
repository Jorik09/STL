

#ifndef INC_4_2_CVECTOR1_H
#define INC_4_2_CVECTOR1_H

#include "CVector.h"

class CVector1: public CVector{
public:
    CVector1();
    CVector1(int size) : CVector (size){};
    CVector1(const CVector &other) : CVector(other){};
    CVector1(string S);
    using CVector :: operator=;

    int output(const char* FileName = NULL);
};
#endif //INC_4_2_CVECTOR1_H
