#include "bernat.h"
#include <cmath>

using namespace sf;

void inicialitzarPilota(Pilota& pilota, float x, float y) {
    pilota.radi = 10.0f;
    pilota.forma.setRadius(pilota.radi);
    pilota.forma.setPosition(Vector2f(x, y));
    pilota.forma.setFillColor(Color::White);
    pilota.velocitat = Vector2f(300.0f, 200.0f);
}

void mourerPilota(Pilota& pilota, float deltaTime) {
    pilota.forma.move(pilota.velocitat * deltaTime);
}

bool rebotPilota(Pilota& pilota, float amplada, float alcada) {
    Vector2f posicio = pilota.forma.getPosition();
    bool punt = false;

    // Rebot superior i inferior
    if (posicio.y <= 0 || posicio.y + pilota.radi * 2 >= alcada) {
        pilota.velocitat.y = -pilota.velocitat.y;

        // Corregir posicio per evitar que quedi enganxada
        if (posicio.y <= 0) {
            pilota.forma.setPosition(Vector2f(posicio.x, 0));
        }
        else {
            pilota.forma.setPosition(Vector2f(posicio.x, alcada - pilota.radi * 2));
        }
    }

    // Sortir per laterals (punt)
    if (posicio.x <= 0 || posicio.x >= amplada) {
        punt = true;
    }

    return punt;
}

void detectarColisio(Pilota& pilota, const Pala& palaEsquerra, const Pala& palaDreta) {
    FloatRect limitsPilota = pilota.forma.getGlobalBounds();
    FloatRect limitsEsquerra = palaEsquerra.forma.getGlobalBounds();
    FloatRect limitsDreta = palaDreta.forma.getGlobalBounds();

    // Colisio amb pala esquerra
    if (limitsPilota.findIntersection(limitsEsquerra).has_value() && pilota.velocitat.x < 0) {
        pilota.velocitat.x = -pilota.velocitat.x;
        pilota.velocitat.x *= 1.15f;
        pilota.forma.setPosition(Vector2f(limitsEsquerra.position.x + limitsEsquerra.size.x, pilota.forma.getPosition().y));
    }

    // Colisio amb pala dreta
    if (limitsPilota.findIntersection(limitsDreta).has_value() && pilota.velocitat.x > 0) {
        pilota.velocitat.x = -pilota.velocitat.x;
        pilota.velocitat.x *= 1.15f;
        pilota.forma.setPosition(Vector2f(limitsDreta.position.x - pilota.radi * 2, pilota.forma.getPosition().y));
    }
}

void inicialitzarPala(Pala& pala, float x, float y, float amplada, float alcada) {
    pala.forma.setSize(Vector2f(amplada, alcada));
    pala.forma.setPosition(Vector2f(x, y));
    pala.forma.setFillColor(Color::White);
    pala.velocitat = 800.0f;
}

void mourerPalaEsquerra(Pala& pala, float deltaTime, float limitSuperior, float limitInferior) {
    if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
        pala.forma.move(Vector2f(0, -pala.velocitat * deltaTime));
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
        pala.forma.move(Vector2f(0, pala.velocitat * deltaTime));
    }

    // Limitar moviment
    Vector2f posicio = pala.forma.getPosition();
    if (posicio.y < limitSuperior) {
        pala.forma.setPosition(Vector2f(posicio.x, limitSuperior));
    }
    if (posicio.y + pala.forma.getSize().y > limitInferior) {
        pala.forma.setPosition(Vector2f(posicio.x, limitInferior - pala.forma.getSize().y));
    }
}

void mourerPalaDreta(Pala& pala, float deltaTime, float limitSuperior, float limitInferior) {
    if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
        pala.forma.move(Vector2f(0, -pala.velocitat * deltaTime));
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
        pala.forma.move(Vector2f(0, pala.velocitat * deltaTime));
    }

    // Limitar moviment
    Vector2f posicio = pala.forma.getPosition();
    if (posicio.y < limitSuperior) {
        pala.forma.setPosition(Vector2f(posicio.x, limitSuperior));
    }
    if (posicio.y + pala.forma.getSize().y > limitInferior) {
        pala.forma.setPosition(Vector2f(posicio.x, limitInferior - pala.forma.getSize().y));
    }
}