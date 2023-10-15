#include <vector>
struct polynomial {
    int level;
    double* values;
};

int get_level(polynomial a) {
    return a.level;
}

double get_value(polynomial a, int n) {
    return a.values[n];
}

polynomial add(polynomial a, polynomial b) {
    polynomial returnValue{};
    if (a.level > b.level) {
        returnValue.level = a.level;
    } else {
        returnValue.level = b.level;
    }
    returnValue.values = new double[returnValue.level];
    for(int i = 0; i < returnValue.level; i++) {
        returnValue.values[i] = 0;
    }
    for(int i = 0; i < returnValue.level; i++) {
        if(i < a.level) {
            returnValue.values[i] += a.values[i];
        }
        if(i < b.level) {
            returnValue.values[i] += b.values[i];
        }
    }
    return returnValue;
}

polynomial subtract(polynomial a, polynomial b) {
    polynomial returnValue{};
    if (a.level > b.level) {
        returnValue.level = a.level;
    }
    else {
        returnValue.level = b.level;
    }
    returnValue.values = new double[returnValue.level];
    for (int i = 0; i < returnValue.level; i++) {
        returnValue.values[i] = 0;
    }
    for (int i = 0; i < returnValue.level; i++) {
        if (i < a.level) {
            returnValue.values[i] += a.values[i];
        }
        if (i < b.level) {
            returnValue.values[i] -= b.values[i];
        }
    }
    return returnValue;
}

polynomial multiply(polynomial a, polynomial b) {
    polynomial returnValue{};
    returnValue.level = a.level + b.level - 1;
    returnValue.values = new double[returnValue.level];
    for (int i = 0; i < returnValue.level; i++) {
        returnValue.values[i] = 0;
    }
    for (int i = 0; i < a.level; i++) {
        for (int j = 0; j < b.level; j++) {
            returnValue.values[i + j] += a.values[i] * b.values[j];
        }
    }
    return returnValue;
}

polynomial set_value(polynomial a, int n, double x) {
    polynomial returnValue;
    returnValue.values[n] = x;
    return returnValue;
}