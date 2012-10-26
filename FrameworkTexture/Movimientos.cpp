#include "Movimientos.h"
#include "misInteracciones.h"
#include "iostream"


//solo verifica que exista colision con el objeto cuboAvatar
bool collision(){
	map <string, Objeto *>::iterator it1;
	map <string, Objeto *>::iterator it;
	//buscar avatar y guardar la localidad donde se encuentra en el map
	it1 = escena->objetos.find("cuboAvatar");
	//por cada objeto declarado en la clase
	for ( it=escena->objetos.begin() ; it != escena->objetos.end(); it++){
		//buscar solo el objeto que tenga el nombre de pared
		if(it->first == "pared"){
			// imprimir pos de la pared y el avatar
			cout << it->first << " pos Z:" << it->second->posZ << " pos Z:"<< it1->first << " pos Z:"  << it1->second->posZ;
			cout<<endl;
				//validar la pos
			if((it->second->posZ + 2.5) >=  (it1->second->posZ -.25)){
				cout<<"se esta pasando!!!"<<endl;
				return true;
			}
			
		}
	}
	return false;

}


double degToRad(double deg){
	return deg*M_PI/180;
}

//hacia la camara es positivo
void moverAdelante(){
	
	if (!collision()){// si no hay colisiones, entoncespuede continuar
		Objeto *aux=escena->objetos["cuboAvatar"];
		double rotYRad= degToRad(aux->rotY);
		//mueve la camara hacia adelante
		camaraPrimeraPersona->zview+= dtran;
		//camaraPrimeraPersona->xview+= dtran;
		//mueve al avatar hacia adelante
		aux->posZ-= dtran * (cos(rotYRad));
		aux->posX-=  dtran * (sin(rotYRad));
	} 
	
	redimensiona(currWidth,currHeight);
	
}

void girarIzquierda(){
	printf("entra girar izq\n");
	if(activa == camaraVistaExterior){
		printf("giraIzquierda cam ext\n");
		activa->yrot+=MOUSE_MUL_RY * drot;
	}else if(activa == camaraPrimeraPersona){
		printf("giraIzquierda cam 1era persona\n");
		Objeto *aux=escena->objetos["cuboAvatar"];
		//rota al avatar hacia izquierda
		aux->rotY+=MOUSE_MUL_RY * drot;
	
		//rota la camara hacia izquierda
		//camaraPrimeraPersona->yrot-=MOUSE_MUL_RY * drot;
	}
	redimensiona(currWidth, currHeight);
	
	/*

	GLdouble rotYRad=degToRad(aux->rotY);
	GLfloat posX = 2 * sin(rotYRad);
	GLfloat posZ = 2 * cos(rotYRad);

	printf("Cam PosIniX: %f\n", camaraPrimeraPersona->xview);
	printf("Cam PosIniZ: %f\n", camaraPrimeraPersona->zview);

	camaraPrimeraPersona->zview=-posZ;
	camaraPrimeraPersona->xview=-posX;

	printf("Cam PosFinX: %f\n", camaraPrimeraPersona->xview);
	printf("Cam PosFinZ: %f\n", camaraPrimeraPersona->zview);
	
	redimensiona(currWidth, currHeight);*/
}

void girarDerecha(){

	if(activa == camaraVistaExterior){
		activa->yrot-=MOUSE_MUL_RY * drot;
	}else if(activa == camaraPrimeraPersona){
		Objeto *aux=escena->objetos["cuboAvatar"];
		//rota al avatar hacia derecha
		aux->rotY-=MOUSE_MUL_RY * drot;
	
		//rota la camara hacia derecha
		//camaraPrimeraPersona->yrot+=MOUSE_MUL_RY * drot;
		
	}
	redimensiona(currWidth, currHeight);
}

void moverArriba(){
	if(camaraVistaExterior->xrot< MAX_XROT_CAMARA_EXTERIOR){
		camaraVistaExterior->xrot+=dtran;
		redimensiona(currWidth, currHeight);
	}
	
}

void moverAbajo(){
	if(camaraVistaExterior->xrot>MIN_XROT_CAMARA_EXTERIOR){
		camaraVistaExterior->xrot-=dtran;
		redimensiona(currWidth, currHeight);
	}
}

void acercar(){
	if(camaraVistaExterior->xrot < MAX_XROT_ACERCAMIENTO ){
		if(camaraVistaExterior->zview < MAX_ZVIEW_ACERCAMIENTO_AL_PUENTE){
			camaraVistaExterior->zview+=dtran;
			redimensiona(currWidth, currHeight);
		}
	}else{
		if(camaraVistaExterior->zview<MAX_ZVIEW_ACERCAMIENTO_AL_CASTILLO){
			camaraVistaExterior->zview+=dtran;
			redimensiona(currWidth, currHeight);
		}
	}
}

void alejar(){
	if(camaraVistaExterior->zview > MAX_ZVIEW_ALEJAMIENTO_CAMARA_EXTERIOR){
		camaraVistaExterior->zview-=dtran;
		redimensiona(currWidth, currHeight);
	}
}