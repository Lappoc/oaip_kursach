#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x,2) - 4 * x + 3;
}

double chord(double a, double b, double eps, int max_iter) {
    double fa = f(a), fb = f(b);
    if (fa * fb >= 0) {
        cout << "Error: f(a) * f(b) >= 0" << endl;
        return 0;
    }
    if (eps <= 0) {
        cout << "Error: eps must be greater than zero" << endl;
        return 0;
    }
    double c = a, fc = fa;
    int iter = 0;
    while (iter < max_iter && fabs(b - a) > eps) {
        double prev_c = c;
        c = a - fa * (b - a) / (fb - fa);
        fc = f(c);
        if (fc == 0) {
            break;
        } else if (fc * fa < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
        if (prev_c == c) {
            cout << "Error: Chord method is not converging" << endl;
            break;
        }
        iter++;
    }
    return c;
}

int main() {
    ifstream input("/Users/dasha/Desktop/oaip_kpyap_siaod_lab/kursach_oaip/kursach_oaip/input.txt");
    ofstream output("/Users/dasha/Desktop/oaip_kpyap_siaod_lab/kursach_oaip/kursach_oaip/output.txt");
    if (!input.is_open()) {
        cout << "Error: input.txt is not found" << endl;
        return 0;
    }
    if (!output.is_open()) {
        cout << "Error: output.txt cannot be opened" << endl;
        return 0;
    }
    double a, b, eps;
    int max_iter;
    input >> a >> b >> eps >> max_iter;
    double root = chord(a, b, eps, max_iter);
    if (root != 0) {
        output << "Root: " << root << endl;
    }
    input.close();
    output.close();
    return 0;
}
