#include "polinom.h"
#include <iostream>
#include <cmath>

using namespace std;

void polinom::calculateDegree(vector<int>& _powers) {
    int maxDegree = -1;
    for (int i = 0; i < _powers.size(); i++) {
        if (_powers[i] > maxDegree) {
            maxDegree = _powers[i];
        }
    }
    degree = maxDegree;
}

polinom::polinom(vector<int>& _coefficients, vector<int>& _powers, int _variable) {
    coefficients = _coefficients;
    powers = _powers;
    variable = _variable;
    calculateDegree(powers);
}

polinom::polinom(const polinom &other) {
    degree = other.degree;
    coefficients = other.coefficients;
    powers = other.powers;
    variable = other.variable;
}

polinom::~polinom() {}

void polinom::setCoefficientsAndPowers(vector<int>& _coefficients, vector<int>& _powers) {
    coefficients = _coefficients;
    powers = _powers;
    calculateDegree(powers);
}

void polinom::setVariable(int _variable) {
    variable = _variable;
}

int polinom::getDegree() {
    return degree;
}

vector<int>& polinom::getCoefficients() {
    return coefficients;
}

vector<int>& polinom::getPowers() {
    return powers;
}

int polinom::getVariable() {
    return variable;
}

vecpolinom::vecpolinom(int _count, vector<polinom>& _polynomials) {
    count = _count;
    polynomials = _polynomials;
}

vecpolinom::vecpolinom(const vecpolinom &other) {
    count = other.count;
    polynomials = other.polynomials;
}

vecpolinom::~vecpolinom() {}

void vecpolinom::set(int _count, vector<polinom>& _polynomials) {
    count = _count;
    polynomials = _polynomials;
}

int vecpolinom::getCount() {
    return count;
}

vector<polinom>& vecpolinom::getPolynomials() {
    return polynomials;
}

int CountPol(vecpolinom v) {
    return v.getCount();
}

polinom SumRazn(polinom p1, polinom p2, int flag) {
    vector<int> coefficients;
    vector<int> powers;
    vector<int> coeffs1 = p1.getCoefficients();
    vector<int> pows1 = p1.getPowers();
    vector<int> coeffs2 = p2.getCoefficients();
    vector<int> pows2 = p2.getPowers();

    int degree1 = p1.getDegree();
    int degree2 = p2.getDegree();
    int maxDegree = max(degree1, degree2);
    int size1 = pows1.size();
    int size2 = pows2.size();
    int maxSize = max(size1, size2);
    int resultCoeffs[maxDegree + 1] = {0};

    for (int i = 0; i < maxSize; i++) {
        if (size1 > i) {
            resultCoeffs[pows1[i]] += coeffs1[i];
        }
        if (size2 > i) {
            resultCoeffs[pows2[i]] += (flag == 1) ? -coeffs2[i] : coeffs2[i];
        }
    }

    for (int i = 0; i < maxDegree + 1; i++) {
        if (resultCoeffs[i] != 0) {
            powers.push_back(i);
            coefficients.push_back(resultCoeffs[i]);
        }
    }
    return polinom(coefficients, powers);
}

int RESULT(polinom p) {
    int variable = p.getVariable();
    vector<int> coefficients = p.getCoefficients();
    int degree = p.getDegree();
    vector<int> powers = p.getPowers();
    int result = 0;
    for (int i = 0; i < powers.size(); i++) {
        result += pow(variable, powers[i]) * coefficients[i];
    }
    return result;
}


int main() {
    cout << "Введите количество полиномов в обоих векторах:" << endl;
    int n;
    cin >> n;
    int el;
    vector<polinom> vec1;
    vector<polinom> vec2;

    cout << "Введите первый вектор полиномов (1. коэффициенты 2. степени):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "------------------------------" << endl;
        vector<int> coefficients;
        vector<int> powers;
        cout << "Введите ненулевое количество степеней в полиноме:" << endl;
        int st;
        cin >> st;
        cout << "Введите коэффициенты в полиноме:" << endl;
        for (int j = 0; j < st; j++) {
            cin >> el;
            coefficients.push_back(el);
        }
        cout << "Введите степени в полиноме:" << endl;
        for (int j = 0; j < st; j++) {
            cin >> el;
            powers.push_back(el);
        }
     
        polinom v(coefficients, powers, 0);
        vec1.push_back(v);
    }

    cout << "Введите второй вектор полиномов (1. коэффициенты 2. степени):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "------------------------------" << endl;
        vector<int> coefficients;
        vector<int> powers;
        cout << "Введите ненулевое количество степеней в полиноме:" << endl;
        int st;
        cin >> st;
        cout << "Введите коэффициенты в полиноме:" << endl;
        for (int j = 0; j < st; j++) {
            cin >> el;
            coefficients.push_back(el);
        }
        cout << "Введите степени в полиноме:" << endl;
        for (int j = 0; j < st; j++) {
            cin >> el;
            powers.push_back(el);
        }
       
        polinom v(coefficients, powers, 0);
        vec2.push_back(v);
    }

    vecpolinom v1(n, vec1);
    vecpolinom v2(n, vec2);

    vector<polinom> result;
    for (int i = 0; i < n; i++) {
        result.push_back(SumRazn(v1.getPolynomials()[i], v2.getPolynomials()[i], 0));
    }
    vecpolinom vout(n, result);
    vout.getPolynomials()[0].setVariable(2);
    cout << RESULT(vout.getPolynomials()[0]) << endl;

    return 0;
}