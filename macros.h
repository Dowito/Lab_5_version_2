#ifndef MACROS_H
#define MACROS_H

#define sizeMapX 45 //Solo numeros impares   Hay algunos numeros con los que no funciona poner bomba como con 31
#define sizeMapY 17 //Solo numeros impares
#define size_sprites 48 //Default 48  ->/No funciona con otro numero
#define sizeGame 1 //No funciona bien
#define dificult 0.0
#define clockGame 20 //por defecto 20

//Personaje
#define SPEED_DEAD 16
#define velPlayer 48  //Solo multiplos de 48
#define bombsPlayer 1 //default 16 /velocidad en que cambian los frames en la animacion de muerte, 16 significa que cuenta 16 veces el clockGames antes de pasar al siguiente frame
#define IMMUNE_EXPLOTION true //true para ser invulnerable a las explociones
#define STEPS 3 //default 3 /Cada tantos pasos cambia de frame al moverse
#define LIFES 3

//Enemigo
#define MAX_ENEMIES 10
#define SPEED_DEAD_ENEMY 10 //default
#define SPEED_MOVE_ANIMATION 6 //velocidad en que cambian los frames en la animacion de muerte, 16 significa que cuenta 16 veces el clockGames antes de pasar al siguiente frame
#define IFMOVE false  //Para iniciar un juego con los enemigos moviendoce o quietos.

//Bomba
#define STEPS_BOMB 80 //80  Delay/Timer = #steps para tener el delay deseado antes de que explote la bomba
#define POT 15

//Explocion
#define STEPS_EXPLOTION_ANIMATION 2
#define DELAY_EXPLOCION 500 //default 500

/*Matriz
0 = bloque
1 = bloque destruible
2 = bomba
9 = piso*/
#endif // MACROS_H
