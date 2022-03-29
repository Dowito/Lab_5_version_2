#ifndef MACROS_H
#define MACROS_H

#define sizeMapX 21 //Solo numeros impares   Hay algunos numeros con los que no funciona poner bomba como con 31
#define sizeMapY 13 //Solo numeros impares
#define size_sprites 48 //Default 48  ->/No funciona con otro numero
#define sizeGame 1 //No funciona bien
#define dificult 0.5
#define clockGame 20 //por defecto 20

//Personaje
#define velPlayer 3  //Solo multiplos de 48
#define bombsPlayer 1
#define SPEED_DEAD 16 //default 16 /velocidad en que cambian los frames en la animacion de muerte, 16 significa que cuenta 16 veces el clockGames antes de pasar al siguiente frame
#define IMMUNE_EXPLOTION true //true para ser invulnerable a las explociones
#define STEPS 3 //default 3 /Cada tantos pasos cambia de frame al moverse
#define LIFES 3

//Enemigo
#define MAX_ENEMIES 500
#define SPEED_MOVE_ANIMATION 6 //velocidad en que cambian los frames en la animacion de muerte, 16 significa que cuenta 16 veces el clockGames antes de pasar al siguiente frame
#define IFMOVE true  //Para iniciar un juego con los enemigos moviendoce o quietos.

//Bomba
#define DELAY 3000 //default 3000
#define POT 20

//Explocion
#define DELAY_EXPLOCION 500 //default 500

/*Matriz
0 = bloque
1 = bloque destruible
2 = bomba
9 = piso*/
#endif // MACROS_H
