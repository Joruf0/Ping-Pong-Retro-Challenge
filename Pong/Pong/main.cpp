#include <SFML/Graphics.hpp>
#include "bernat.h"
#include "jordi.h"

using namespace sf;

int main() {
    // Constants del joc
    const float AMPLADA = 800.0f;
    const float ALCADA = 600.0f;

    // Crear finestra
    RenderWindow finestra;
    inicialitzarJoc(finestra);

    // Inicialitzar elements del joc
    Pilota pilota;
    inicialitzarPilota(pilota, AMPLADA / 2, ALCADA / 2);

    Pala palaEsquerra;
    inicialitzarPala(palaEsquerra, 30, ALCADA / 2 - 50, 15, 100);

    Pala palaDreta;
    inicialitzarPala(palaDreta, AMPLADA - 45, ALCADA / 2 - 50, 15, 100);

    Marcador marcador;
    if (!inicialitzarMarcador(marcador)) {
        return -1; // Error carregant la font
    }

    // Variables de control
    Clock rellotge;
    bool jocAcabat = false;
    int guanyador = 0;

    // Bucle principal
    while (finestra.isOpen()) {
        float deltaTime = rellotge.restart().asSeconds();

        // Gestio d'esdeveniments
        while (auto event = finestra.pollEvent()) {
            if (event->is<Event::Closed>()) {
                finestra.close();
            }

            // Reiniciar joc si s'ha acabat
            if (jocAcabat && event->is<Event::KeyPressed>()) {
                const auto& keyEvent = event->getIf<Event::KeyPressed>();
                if (keyEvent && keyEvent->code == Keyboard::Key::Space) {
                    marcador.puntsEsquerra = 0;
                    marcador.puntsDreta = 0;
                    jocAcabat = false;
                    guanyador = 0;
                    inicialitzarPilota(pilota, AMPLADA / 2, ALCADA / 2);
                }
            }
        }

        if (!jocAcabat) {
            // Moure pales
            mourerPalaEsquerra(palaEsquerra, deltaTime, 0, ALCADA);
            mourerPalaDreta(palaDreta, deltaTime, 0, ALCADA);

            // Moure pilota
            mourerPilota(pilota, deltaTime);

            // Detectar colisions amb pales
            detectarColisio(pilota, palaEsquerra, palaDreta);

            // Detectar rebots i punts
            bool hiHaPunt = rebotPilota(pilota, AMPLADA, ALCADA);

            if (hiHaPunt) {
                Vector2f posicio = pilota.forma.getPosition();

                if (posicio.x <= 0) {
                    // Punt per al jugador dreta
                    actualitzarMarcador(marcador, 2);
                    reiniciarPilota(pilota, AMPLADA, ALCADA, 2);
                }
                else {
                    // Punt per al jugador esquerra
                    actualitzarMarcador(marcador, 1);
                    reiniciarPilota(pilota, AMPLADA, ALCADA, 1);
                }
            }

            // Comprovar si el joc ha acabat
            comprovarFinal(marcador, jocAcabat, guanyador);
        }

        // Dibuixar tot
        finestra.clear(Color::Black);

        if (!jocAcabat) {
            finestra.draw(palaEsquerra.forma);
            finestra.draw(palaDreta.forma);
            finestra.draw(pilota.forma);
        }
        else {
            mostrarFinal(finestra, guanyador, marcador.font);
        }

        mostrarMarcador(finestra, marcador);
        finestra.display();
    }

    return 0;
}