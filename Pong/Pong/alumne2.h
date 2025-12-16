#ifndef ALUMNE2_H
#define ALUMNE2_H

#include <SFML/Graphics.hpp>
#include "alumne1.h"
#include <memory>

using namespace sf;

// Estructura per al marcador
struct Marcador {
    int puntsEsquerra;
    int puntsDreta;
    Font font;
    std::unique_ptr<Text> textEsquerra;
    std::unique_ptr<Text> textDreta;

    Marcador() : puntsEsquerra(0), puntsDreta(0) {}
};

// Funcions de l'Alumne 2 (GROC/TARONGE)
void inicialitzarJoc(RenderWindow& finestra);
void mostrarMarcador(RenderWindow& finestra, Marcador& marcador);
void actualitzarMarcador(Marcador& marcador, int jugador);

void comprovarFinal(const Marcador& marcador, bool& jocAcabat, int& guanyador);
void mostrarFinal(RenderWindow& finestra, int guanyador, const Font& font);

void reiniciarPilota(Pilota& pilota, float amplada, float alcada, int jugadorPunt);

bool inicialitzarMarcador(Marcador& marcador);

#endif