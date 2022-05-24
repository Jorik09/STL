#include "CVector.h"
#include "CVector0.h"
#include "CVector1.h"
#include "CFabricVector.h"

#include <iostream>
#include <fstream>
#include <functional>
#include <cassert>
#include <cstdlib>

using namespace std;


int main() {

    setlocale(LC_ALL, "rus");

    map <string, CFabricVector*> mapCVector;
    mapCVector["Hori"] = new CFabricVector0;
    mapCVector["hori"] = new CFabricVector0;
    mapCVector["Vert"] = new CFabricVector1;
    mapCVector["vert"] = new CFabricVector1;

    CVector0 a(2);
    CVector1 b(2);
    CVector0 s(2);
    CVector0 d(2);
    double h;
    a[0]= 1.1; a[1]= 2.2;
    b[0]= 1.0; b[1]= 1.0;
    cout << "a: "<<a;
    cout << "b: "<<b;
    s = a + b;
    if ((s[0]==2.1)&&(s[1]==3.2))
        cout << "AT1 success"<< endl;
    s = a - b;
    cout << "s "<< s;
    if ((s[0]==0.1)&&(s[1]==1.2))
        cout << "AT2 success"<< endl;

    ifstream in;
    in.open("input.txt");
    if (!in.is_open())
        return 1;
    while (!in.eof())
    {
        CVector* A;
        string I;
        string File;
        string Data;
        in >> I;
        in >> File;
        getline(in, Data);
        A = mapCVector[I]->createCVector(Data);
        A->output(File.c_str());
        delete A;
    }
    in.close();
    return 0;
}