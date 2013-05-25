#ifndef GENERATOR_H
#define GENERATOR_H

#include <QImage>

class Color {
    public:
    int r;
    int g;
    int b;
    Color(){
        r = 0;
        g = 0;
        b = 0;
    }
    Color(int _r, int _g, int _b ){
        r = _r;
        g = _g;
        b = _b;
    }
};

class Complex {
    public:
    double real;
    double imag;
    Complex(){
        real = 0.0f;
        imag = 0.0f;
    }
    Complex(double r, double i){
        real = r;
        imag = i;
    }
    double magnitudeSquared(){
        return real*real + imag*imag;
    }
    Complex squared(){
        return Complex(real*real - imag*imag, 2*real*imag);
    }
    Complex add(Complex a){
        return Complex(real + a.real, imag + a.imag);
    }
};

class Generator {
    public :


    static void generate(QImage& image, bool julia);

};

#endif // GENERATOR_H
