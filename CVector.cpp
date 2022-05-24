#include "CVector.h"
#include "CVector0.h"
#include "CVector1.h"

#include <sstream>
using namespace std;

CVector:: CVector(){}

CVector:: CVector(int size)
{
    this->data.resize(size);
    for (double i : this->data) {
        i = 0;
    }
}

CVector:: CVector(int size, const char* FileName)
{
    this->data.resize(size);

    ifstream in;
    in.open(FileName);
    if (!in.is_open())
        return;
    for (double i : this->data)
        in >> i;
}

CVector:: CVector(const CVector &other)
{
    this->data = other.data;
}

CVector& CVector::operator=(const CVector &other) {

    if (this == &other) return *this;

    this->data = other.data;

    return *this;
}

double& CVector::operator[](int index){
    if (index >= this->data.size()){
        int N;
        N = this->data.size();
        vector <double> B(N);

        for (int i = 0; i < N; ++i) {
            B[i] = this->data[i];
        }
        this->data.resize(index + 1);

        for (int i = 0; i < index + 1; ++i) {
            if(i >= N){
                this->data[i] = 0;
            }
            else this->data[i] = B[i];
        }
    }
    return data[index];
}

const double& CVector:: operator[](int index)const{
    return data[index];
}


CVector0 operator+(const CVector &first, const CVector &second) {  // перегруженный оператор +

    if (first.size() != second.size()) {
        cout << "Размеры векторов различны, данная операция невозможна" << endl;
        //assert(this->data.size() == other.data.size());
    }

    CVector0 temp (first.size());

    for (int i = 0; i < first.size(); ++i) {
        temp.data[i] = first.data[i] + second.data[i];
    }

    return temp;
}

CVector& CVector:: operator+=(const CVector &other) {
    *this = *this + other;
    return *this;
}

CVector0 operator-(const CVector &first, const CVector &second) {  // перегруженный оператор +

    if (first.size() != second.size()) {
        cout << "Размеры векторов различны, данная операция невозможна" << endl;
        //assert(this->data.size() == other.data.size());
    }

    CVector0 temp (first.size());

    for (int i = 0; i < first.size(); ++i) {
        temp.data[i] = first.data[i] - second.data[i];
    }

    return temp;
}

CVector& CVector:: operator-=(const CVector &other) {
    *this = *this - other;
    return *this;
}

/*double CVector:: operator*(const CVector0 &other) {  //перегруженный оператор скалярное произведение
    if (this->data.size() != other.data.size()) {
        cout << "Размеры векторов различны, данная операция невозможна" << endl;
        assert(this->data.size() == other.data.size());
    }
    double S = 0;

    for (int i = 0; i < data.size(); ++i) {
        S += this->data[i] * other.data[i];
    }

    return S;
}*/

/*double CVector0:: operator * (const CVector &first, const CVector &second) {  // перегруженный оператор +

    if (first.size() != second.size()) {
        cout << "Размеры векторов различны, данная операция невозможна" << endl;
        //assert(this->data.size() == other.data.size());
    }
    double S = 0;

    for (int i = 0; i < first.size(); ++i) {
        S += first.data[i] * second.data[i];
    }

    return S;
}*/

CVector0:: CVector0(){}

CVector0::CVector0(string Data)
{
    string d;
    istringstream in (Data);
    while(!in.eof())
    {
        in >> d;
        this->data.push_back(atof(d.c_str()));
    }
}

int CVector0::output(const char* FileName)
{
    ofstream out;
    out.open(FileName, fstream::out|fstream::app);
    if(!out.is_open())
        return -1;
    for(double i : this->data)
        out << i << ' ';
    out << endl;
    out.close();
    return 0;
}

/*CVector0 CVector0::operator+(const CVector &first, const CVector &second) {
    return CVector0();
}*/

CVector1:: CVector1(){}

CVector1::CVector1(string Data)
{
    string d;
    istringstream in (Data);
    while(!in.eof())
    {
        in >> d;
        this->data.push_back(atof(d.c_str()));
    }
}

int CVector1::output(const char* FileName)
{
    ofstream out;
    out.open(FileName, fstream::out|fstream::app);
    if(!out.is_open())
        return -1;
    for(double i : this->data)
        out << i << '\n';
    out << endl;
    out.close();
    return 0;
}

ostream &operator<<(ostream &out, const CVector &value)
{
    for (double i : value.data) {
        cout << i << "\t";
    }
    cout << endl<< endl;
    return out;
}