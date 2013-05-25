#include "generator.h"

double frameXleft = -1.8;
double frameYleft = -1.2;
double frameXright = 0.6;
double frameYright = 1.2;

double K_real = 0.353;
double K_imag = 0.288;


int Width = 900;
int Height = 900;

int maxIterations = 50;

const int maxColorLevel = 255;

void Generator::generate(QImage& image, bool julia){
    for(int y = 0; y < Height; y++){
            for(int x = 0; x < Width; x++){
               //Find c
                Complex c;
                c.real = frameXleft + x * (frameXright - frameXleft) / Width;
                c.imag = frameYleft + y * (frameYright - frameYleft) / Height;
                int iter = 0;
                Color color;
                Complex Z(c.real, c.imag);
                Complex K;
                if(julia){
                    K.real = K_real;
                    K.imag = K_imag;
                } else {
                    K.real = c.real;
                    K.imag = c.imag;
                }
                while(iter < maxIterations){
                    if(Z.magnitudeSquared() > 2){
                        break;
                    }
                    Z = Z.squared();
                    Z = Z.add(K);
                    iter++;
                }
                if(iter < maxIterations / 2){
                    color.r = (2 * iter * maxColorLevel) / maxIterations;
                } else if (iter > maxIterations / 2 && iter < maxIterations) {
                    color.r = 255;
                    color.g = (2 * (iter - maxIterations / 2) * maxColorLevel) / maxIterations;
                    color.b = (2 * (iter - maxIterations / 2) * maxColorLevel) / maxIterations;
                } else {
                    //do nothing
                }
                image.setPixel(x, y, qRgb(color.r, color.g, color.b));
            }
        }
}
