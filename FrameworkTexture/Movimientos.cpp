#include "Movimientos.h"
#include "misInteracciones.h"

double degToRad(double deg){
	return deg*M_PI/180;
}

//hacia la camara es positivo
void moverAdelante(){
	Objeto *aux=escena->objetos["cuboAvatar"];
	double rotYRad= degToRad(aux->rotY);
	//mueve la camara default hacia adelante
	
	camaraPrimeraPersona->zview+= dtran * (cos(rotYRad));
	camaraPrimeraPersona->xview+= dtran * (sin(rotYRad));
	
	
	/*printf("Angulo de rotY en grados: %f\n", aux->rotY);
	printf("Angulo de rotY en radianes: %f\n", rotYRad);
	printf("(sin(rotYRad)): %f\n", (sin(rotYRad)));
	printf("xview: posIni: %f\n", activa->xview);*/
	
	//printf("xview: posFin: %f\n", activa->xview);

	//mueve al avatar hacia adelante
	
	/*printf("Angulo de rotY en grados: %f\n", aux->rotY);
	printf("Angulo de rotY en radianes: %f\n", rotYRad);
	printf("(cos(degreesRotY)): %f\n", (cos(rotYRad)));
	printf("Z: posIni: %f\n", aux->posZ);
	printf("Componente de desp en Z: %f\n", dtran * (cos(rotYRad)));*/
	aux->posZ-= dtran * (cos(rotYRad));
	//printf("Z: posFin: %f\n", aux->posZ);
	aux->posX-=  dtran * (sin(rotYRad));

	redimensiona(currWidth,currHeight);		  
}

void girarIzquierda(){
	//rota la camara hacia izquierda
	printf("Angulo ini de rotY de Camara: %f\n", activa->yrot);
	
	camaraPrimeraPersona->yrot-=MOUSE_MUL_RY * drot;
	
	printf("Angulo fin de rotY de Camara: %f\n", activa->yrot);
	//rota al avatar hacia izquierda
	printf("Angulo ini de rotY de objeto: %f\n", escena->objetos["cuboAvatar"]->rotY);
	escena->objetos["cuboAvatar"]->rotY+=MOUSE_MUL_RY * drot;
	
	printf("Angulo fin de rotY de objeto: %f\n", escena->objetos["cuboAvatar"]->rotY);
	redimensiona(currWidth, currHeight);
}

void girarDerecha(){
	//rota la camara hacia derecha
	camaraPrimeraPersona->yrot+=MOUSE_MUL_RY * drot;
	
	//rota al avatar hacia derecha
	escena->objetos["cuboAvatar"]->rotY-=MOUSE_MUL_RY * drot;
	redimensiona(currWidth, currHeight);
}

