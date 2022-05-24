#include "CVector.h"
#include "CVector0.h"
#include "CVector1.h"

using namespace std;

class CFabricVector{
public:
    virtual CVector* createCVector(string Data) = 0;
};

class CFabricVector0: public CFabricVector
{
public:
    CVector* createCVector(string Data)
    {
        return new CVector0(Data);
    }
};

class CFabricVector1: public CFabricVector
{
public:
    CVector* createCVector(string Data)
    {
        return new CVector1(Data);
    }
};