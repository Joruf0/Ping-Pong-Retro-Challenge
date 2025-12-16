#include "alumne2.h"
#include <string>

using namespace sf;
using namespace std;

void inicialitzarJoc(RenderWindow& finestra) {
    finestra.create(VideoMode({ 800, 600 }), "Joc del Pong");
    finestra.setFramerateLimit(60);
}

bool inicialitzarMarcador(Marcador& marcador) {
    marcador.puntsEsquerra = 0;
    marcador.puntsDreta = 0;

    // Intentar carregar la font (usa una font del sistema)
    if (!marcador.font.openFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        // Si no es troba, prova amb una font de Windows
        if (!marcador.font.openFromFile("C:/Windows/Fonts/arial.ttf")) {
            // Si tampoc, prova amb macOS
            if (!marcador.font.openFromFile("/System/Library/Fonts/Helvetica.ttc")) {
                return false;
            }
        }
    }

    // Crear els textos amb unique_ptr
    marcador.textEsquerra = make_unique<Text>(marcador.font);
    marcador.textEsquerra->setCharacterSize(50);
    marcador.textEsquerra->setFillColor(Color::White);
    marcador.textEsquerra->setPosition(Vector2f(300, 20));

    marcador.textDreta = make_unique<Text>(marcador.font);
    marcador.textDreta->setCharacterSize(50);
    marcador.textDreta->setFillColor(Color::White);
    marcador.textDreta->setPosition(Vector2f(450, 20));

    return true;
}

void mostrarMarcador(RenderWindow& finestra, Marcador& marcador) {
    marcador.textEsquerra->setString(to_string(marcador.puntsEsquerra));
    marcador.textDreta->setString(to_string(marcador.puntsDreta));

    finestra.draw(*marcador.textEsquerra);
    finestra.draw(*marcador.textDreta);

    // Linia central
    RectangleShape liniaCentral(Vector2f(5, 600));
    liniaCentral.setPosition(Vector2f(397.5f, 0));
    liniaCentral.setFillColor(Color(100, 100, 100));
    finestra.draw(liniaCentral);
}

void actualitzarMarcador(Marcador& marcador, int jugador) {
    if (jugador == 1) {
        marcador.puntsEsquerra++;
    }
    else if (jugador == 2) {
        marcador.puntsDreta++;
    }
}

void comprovarFinal(const Marcador& marcador, bool& jocAcabat, int& guanyador) {
    const int PUNTS_PER_GUANYAR = 5;

    if (marcador.puntsEsquerra >= PUNTS_PER_GUANYAR) {
        jocAcabat = true;
        guanyador = 1;
    }
    else if (marcador.puntsDreta >= PUNTS_PER_GUANYAR) {
        jocAcabat = true;
        guanyador = 2;
    }
}

void mostrarFinal(RenderWindow& finestra, int guanyador, const Font& font) {
    Text textFinal(font);
    textFinal.setCharacterSize(60);
    textFinal.setFillColor(Color::Yellow);

    if (guanyador == 1) {
        textFinal.setString("Guanya Jugador 1!");
    }
    else {
        textFinal.setString("Guanya Jugador 2!");
    }

    // Centrar el text
    FloatRect bounds = textFinal.getLocalBounds();
    textFinal.setPosition(Vector2f(400 - bounds.size.x / 2, 250));

    finestra.draw(textFinal);

    // Text per reiniciar
    Text textReiniciar(font);
    textReiniciar.setCharacterSize(30);
    textReiniciar.setFillColor(Color::White);
    textReiniciar.setString("Prem ESPAI per jugar de nou");

    bounds = textReiniciar.getLocalBounds();
    textReiniciar.setPosition(Vector2f(400 - bounds.size.x / 2, 350));

    finestra.draw(textReiniciar);
}

void reiniciarPilota(Pilota& pilota, float amplada, float alcada, int jugadorPunt) {
    pilota.forma.setPosition(Vector2f(amplada / 2 - pilota.radi, alcada / 2 - pilota.radi));

    // La pilota va cap al jugador que NO ha marcat
    if (jugadorPunt == 1) {
        pilota.velocitat = Vector2f(300.0f, 200.0f);
    }
    else {
        pilota.velocitat = Vector2f(-300.0f, 200.0f);
    }
}