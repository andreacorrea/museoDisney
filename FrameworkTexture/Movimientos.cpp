#include "Movimientos.h"
#include "misInteracciones.h"

void moverAdelante(){
	//mueve la camara hacia adelante
	activa->zview+=dtran;
	//mueve al avatar hacia adelante
	escena->objetos["cuboAvatar"]->posZ=escena->objetos["cuboAvatar"]->posZ-dtran;
	redimensiona(currWidth,currHeight);		  
}

void moverAtras(){
	//mueve la camara hacia atras
	activa->zview-=dtran;
	//mueve al avatar hacia atras
	escena->objetos["cuboAvatar"]->posZ+=dtran;
	redimensiona(currWidth,currHeight);		  
}

void girarIzquierda(){
	//rota la camara hacia izquierda
	activa->yrot-=MOUSE_MUL_RY * drot;
	//rota al avatar hacia izquierda
	escena->objetos["cuboAvatar"]->rotY+=MOUSE_MUL_RY * drot;
	redimensiona(currWidth, currHeight);
}

void girarDerecha(){
	//rota la camara hacia derecha
	activa->yrot+=MOUSE_MUL_RY * drot;
	//rota al avatar hacia derecha
	escena->objetos["cuboAvatar"]->rotY-=MOUSE_MUL_RY * drot;
	redimensiona(currWidth, currHeight);
}