#ifndef POLINOM_H
#define POLINOM_H

#include <vector>
using namespace std;

class polinom {
private:
    int degree;
    vector<int> coefficients;
    vector<int> powers;
    int variable;

public:
    void calculateDegree(vector<int>& _powers);
    polinom(vector<int>& _coefficients, vector<int>& _powers, int _variable);
    polinom(const polinom &other);
    ~polinom();

    void setCoefficientsAndPowers(vector<int>& _coefficients, vector<int>& _powers);
    void setVariable(int _variable);
    int getDegree();
    vector<int>& getCoefficients();
    vector<int>& getPowers();
    int getVariable();
};

class vecpolinom {
private:
    int count;
    vector<polinom> polynomials;

public:
    vecpolinom(int _count, vector<polinom>& _polynomials);
    vecpolinom(const vecpolinom &other);
    ~vecpolinom();

    void set(int _count, vector<polinom>& _polynomials);
    int getCount();
    vector<polinom>& getPolynomials();
};

int CountPol(vecpolinom v);
polinom SumRazn(polinom p1, polinom p2, int flag);
int RESULT(polinom p);

#endif // POLINOM_H