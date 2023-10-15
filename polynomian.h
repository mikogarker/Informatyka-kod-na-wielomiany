struct polynomial {
    int level;
    double* values;
};

int get_level(polynomial a);
double get_value(polynomial a, int n);
polynomial add(polynomial a, polynomial b);
polynomial subtract(polynomial a, polynomial b);
polynomial multiply(polynomial a, polynomial b);
polynomial set_value(polynomial a, int n, double x);