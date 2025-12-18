# Ping-Pong-Retro-Challenge
Imagina que pots programar el teu propi joc de Ping Pong com els clàssics dels anys 80. En aquesta activitat treballaràs amb un company per crear una versió bàsica del joc utilitzant C++ i la llibreria SFML.  L’objectiu és aplicar la programació estructurada i el disseny descendent per construir un joc complet, senzill i funcional.

## Funcionament
El joc realitzat es Ping Pong, en aquest joc dos jugadors competeixen amb una bola per marcar en el camp del altre jugador, al arrivar a 5 punts (un per cada gol) el jugador guanya.
| Victoria 1 | Victoria 2 |
|----------|-------|
| ![jugador1](./images/jugador1.png)         |  ![jugador2](./images/jugador2.png)  |

## Controls
Controls per el joc:
- Moure Jugador 2  [↑ ↓]
- Moure Jugador 1 [W S]
- Comença una nova ronda [Space]

## Esquema descendent
![diagrama](./images/esquema.png)

## Tasques i la seva realització

| Nom de l’autor | Tasca o responsabilitat principal | 
|----------------|-----------------------------------|
| Bernat Martin-C| Logica [Jugadors i Bola] Grafic [Marcadors] | 
| Jordi Rubau | Logica [Resolució marcadors i resolucio de partida] Grafic [Jugadors i Bola] | 

## Conclusions
El projecte ens ha permet aplicar el que vam aprendre sobre disenys descendents, sent la part mes important la facilitat que donen a l'hora d'asignar el treball, gracies a aixo hem pogut separar el treball en parts factibles que fer poc a poc. Encara que el projecte a sigut completat amb totes les funcions que voliem, encara podriem fe uns quants canvis de qualitat de vida, entre ells:
- Canvi de fons depenen del turn del jugador
- Canvi al temps entre cada input de tecles
- Afexir un mode d'un jugador
- Permetra canviar la resolució de la pestanya
