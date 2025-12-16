#ifndef ALUMNE1_H
#define ALUMNE1_H

#include <SFML/Graphics.hpp>

using namespace sf;

// Estructura per a la pilota
struct Pilota {
    CircleShape forma;
    Vector2f velocitat;
    float radi;
};

// Estructura per a les pales
struct Pala {
    RectangleShape forma;
    float velocitat;
};

// Funcions de l'Alumne 1 (VERD)
void inicialitzarPilota(Pilota& pilota, float x, float y);
void mourerPilota(Pilota& pilota, float deltaTime);
bool rebotPilota(Pilota& pilota, float amplada, float alcada);
void detectarColisio(Pilota& pilota, const Pala& palaEsquerra, const Pala& palaDreta);

void inicialitzarPala(Pala& pala, float x, float y, float amplada, float alcada);
void mourerPalaEsquerra(Pala& pala, float deltaTime, float limitSuperior, float limitInferior);
void mourerPalaDreta(Pala& pala, float deltaTime, float limitSuperior, float limitInferior);

#endif