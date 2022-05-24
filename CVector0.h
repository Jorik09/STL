
#ifndef INC_4_2_CVECTOR0_H
#define INC_4_2_CVECTOR0_H

#include "CVector.h"

class CVector0: public CVector{
public:
    CVector0();
    CVector0(int size) : CVector(size){};

    CVector0(string Data);


    using CVector::operator=;


    int output(const char* FileName = NULL);
};
CVector0 operator+(const CVector &, const CVector &);
CVector0 operator-(const CVector &, const CVector &);
//double CVector0:: operator * (const CVector &, const CVector &);
#endif //INC_4_2_CVECTOR0_H
