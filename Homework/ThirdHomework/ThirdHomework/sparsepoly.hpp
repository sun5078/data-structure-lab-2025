#pragma once
#ifndef SPARSEPOLY_HPP
#define SPARSEPOLY_HPP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SparsePoly {
    int numTerms;
    vector<int> exponents;
    vector<float> coefficients;

public:
    SparsePoly() : numTerms(0) {}

    void read() {
        cout << "항의 개수를 입력하세요: ";
        cin >> numTerms;

        exponents.clear();
        coefficients.clear();

        for (int i = 0; i < numTerms; ++i) {
            float coef;
            int expo;
            cout << i + 1 << "번째 항의 계수와 차수를 입력하세요 (예:계수 차수): ";
            cin >> coef >> expo;

            if (coef != 0) {
                coefficients.push_back(coef);
                exponents.push_back(expo);
            }
        }

        sort_terms(); 
    }

    void display(const char* str) const {
        cout << str;
        for (size_t i = 0; i < exponents.size(); ++i) {
            cout << coefficients[i] << "x^" << exponents[i];
            if (i != exponents.size() - 1)
                cout << " + ";
        }
        cout << endl;
    }

    void add(SparsePoly a, SparsePoly b) {
        exponents.clear();
        coefficients.clear();

        size_t i = 0, j = 0;
        while (i < a.exponents.size() && j < b.exponents.size()) {
            if (a.exponents[i] > b.exponents[j]) {
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(a.coefficients[i]);
                i++;
            }
            else if (a.exponents[i] < b.exponents[j]) {
                exponents.push_back(b.exponents[j]);
                coefficients.push_back(b.coefficients[j]);
                j++;
            }
            else {
                float sumCoef = a.coefficients[i] + b.coefficients[j];
                if (sumCoef != 0) {
                    exponents.push_back(a.exponents[i]);
                    coefficients.push_back(sumCoef);
                }
                i++;
                j++;
            }
        }

     
        while (i < a.exponents.size()) {
            exponents.push_back(a.exponents[i]);
            coefficients.push_back(a.coefficients[i]);
            i++;
        }

        while (j < b.exponents.size()) {
            exponents.push_back(b.exponents[j]);
            coefficients.push_back(b.coefficients[j]);
            j++;
        }
    }

private:
    void sort_terms() {
        vector<pair<int, float>> terms;
        for (size_t i = 0; i < exponents.size(); ++i) {
            terms.push_back({ exponents[i], coefficients[i] });
        }

        sort(terms.begin(), terms.end(), [](auto& a, auto& b) {
            return a.first > b.first;
            });

        exponents.clear();
        coefficients.clear();
        for (auto& term : terms) {
            exponents.push_back(term.first);
            coefficients.push_back(term.second);
        }
    }
};

#endif