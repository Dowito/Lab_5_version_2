#ifndef MACROS_H
#define MACROS_H

#define sizeMapX 15 //Solo numero impares
#define sizeMapY 11 //Solo numero impares
#define size_sprites 48
#define sizeGame 1
#define dificult 0.5
#define clockGame 20 //por defecto 20

//Personaje
#define velPlayer 8  //Solo multiplos de 48
#define bombsPlayer 4
#define SPEED_DEAD 16 //default 16 /velocidad en que cambian los frames en la animacion de muerte, 16 significa que cuenta 16 veces el clockGames antes de pasar al siguiente frame
#define IMMUNE_EXPLOTION true //true para ser invulnerable a las explociones

//Enemigo
#define MAX_ENEMIES 5
#define SPEED_MOVE_ANIMATION 6 //velocidad en que cambian los frames en la animacion de muerte, 16 significa que cuenta 16 veces el clockGames antes de pasar al siguiente frame
#define IFMOVE true  //Para iniciar un juego con los enemigos moviendoce o quietos.

//Bomba
#define DELAY 1000 //default 3000
#define POT 2

//Explocion
#define DELAY_EXPLOCION 200 //default 500

//Nivel


/*Matriz
0 = bloque
1 = bloque destruible
2 = bomba
9 = piso*/
#endif // MACROS_H
