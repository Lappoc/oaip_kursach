#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Функция, для которой решаем уравнение
double f(double x) {
    return pow(x,2) - 4 * x + 3;
}

// Решение уравнения методом хорд с ограничением числа итераций
double chord(double a, double b, double eps, int max_iter) {
    double fa = f(a), fb = f(b);
//    cout<<fa*fb<<endl;
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
    // Открытие файлов для чтения и записи
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
    // Чтение данных из файла
    double a, b, eps;
    int max_iter;
    input >> a >> b >> eps >> max_iter;
    // Решение уравнения методом хорд
    double root = chord(a, b, eps, max_iter);
    // Запись результата в файл
    if (root != 0) {
        output << "Root: " << root << endl;
    }
    // Закрытие файлов
    input.close();
    output.close();
    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <iostream>
//#include <fstream>
//#include <cmath>
//
//using namespace std;
//
//double f(double x);
//
//int main()
//{
//    double x0, x1, eps, fx0, fx1, fpx0, fpx1, x2, fx2, fpx2, error;
//    int iter = 0, maxIter;
//
//    ifstream inputFile;
//    inputFile.open("/Users/dasha/Desktop/oaip_kpyap_siaod_lab/kursach_oaip/kursach_oaip/input.txt");
//
//    if (!inputFile)
//    {
//        cout << "Ошибка при открытии файла input." << endl;
//        return 1;
//    }
//
//    inputFile >> x0 >> x1 >> eps >> maxIter;
//
//    if (eps <= 0 || maxIter <= 0 || x0 == x1)
//    {
//        cout << "Некорректные входные данные." << endl;
//        return 1;
//    }
//
//    inputFile.close();
//
//    fx0 = f(x0);
//    fx1 = f(x1);
//    fpx0 = (f(x0 + eps) - fx0) / eps;
//    fpx1 = (f(x1 + eps) - fx1) / eps;
//
//    do
//    {
//        x2 = x1 - ((x1 - x0) / (fpx1 - fpx0)) * fpx1;
//        fx2 = f(x2);
//        fpx2 = (f(x2 + eps) - fx2) / eps;
//
//        error = abs((x2 - x1) / x2);
//        iter++;
//
//        if (iter > maxIter)
//        {
//            cout << "Превышено максимальное число итераций." << endl;
//            return 1;
//        }
//
//        x0 = x1;
//        x1 = x2;
//        fx0 = fx1;
//        fx1 = fx2;
//        fpx0 = fpx1;
//        fpx1 = fpx2;
//    } while (error > eps);
//
//    ofstream outputFile;
//    outputFile.open("/Users/dasha/Desktop/oaip_kpyap_siaod_lab/kursach_oaip/kursach_oaip/output.txt");
//
//    if (!outputFile)
//    {
//        cout << "Ошибка при открытии файла output." << endl;
//        return 1;
//    }
//
//    outputFile << "Результат: " << x2 << endl;
//    outputFile << "Количество итераций: " << iter << endl;
//
//    outputFile.close();
//
//    return 0;
//}
//
//
//double f(double x)
//{
//    return pow(x,2) - 4 * x + 3;
//}
