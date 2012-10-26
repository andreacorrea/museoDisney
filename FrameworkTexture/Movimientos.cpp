#include "Movimientos.h"
#include "misInteracciones.h"
#include "iostream"


//solo verifica que exista colision con el objeto cuboAvatar
bool collision(GLfloat rotY){
	map <string, Objeto *>::iterator it1;
	map <string, Objeto *>::iterator it;
	//buscar avatar y guardar la localidad donde se encuentra en el map
	it1 = escena->objetos.find("cuboAvatar");
	//por cada objeto declarado en la clase
	for ( it=escena->objetos.begin() ; it != escena->objetos.end(); it++){
		//buscar solo el objeto que tenga el nombre de pared
		if(it->first == "pared"){
			// imprimir pos de la pared y el avatar
			//cout << it->first << " pos Z:" << it->second->posZ << " pos Z:"<< it1->first << " pos Z:"  << it1->second->posZ<<endl;
				//validar la pos
			/*
			if((it->second->posZ + 2.5) >=  (it1->second->posZ -.25)){
				cout<<"se esta pasando!!!"<<endl;
				return true;
			}*/
			
		}
	}
	if(it1->second->posZ < -2.6  && (((abs((int)rotY)%360)<90 || (abs((int)rotY)%360)>270))){
		return true;
	}
	//if(it1->second->posX < -1.7  && ((abs((int)rotY)%360)<180 || (abs((int)rotY)%360)>0)){
	if(1 && ((abs((int)rotY)%360)<180)){
		printf("%i\n",(abs((int)rotY)%360));
		return true;
	}
	cout << "Objeto"<< it1->first << " pos Z:"  << it1->second->posZ<< " pos X:"  << it1->second->posX << " angulo:"<<rotY<<endl;
	return false;

}


double degToRad(double deg){
	return deg*M_PI/180;
}

//hacia la camara es positivo
void moverAdelante(){
		Objeto *aux=escena->objetos["cuboAvatar"];
		double rotYRad= degToRad(aux->rotY);
		aux->posZ-= dtran * (cos(rotYRad));
		aux->posX-=  dtran * (sin(rotYRad));
		camaraPrimeraPersona->xview=aux->posX+sin(degToRad(aux->rotY));
		camaraPrimeraPersona->zview=aux->posZ+cos(degToRad(aux->rotY));
		
		redimensiona(currWidth,currHeight);
}

void girarIzquierda(){
	Objeto *aux=escena->objetos["cuboAvatar"];
	//rota al avatar hacia izquierda
	aux->rotY+=MOUSE_MUL_RY * drot;

	//rota la camara hacia izquierda
	//camaraPrimeraPersona->yrot-=MOUSE_MUL_RY * drot;

	//traslada camara
	camaraPrimeraPersona->xview=aux->posX+sin(degToRad(aux->rotY));
	camaraPrimeraPersona->zview=aux->posZ+cos(degToRad(aux->rotY));

	redimensiona(currWidth, currHeight);
}

void girarDerecha(){
	Objeto *aux=escena->objetos["cuboAvatar"];
	//rota al avatar hacia derecha	
	aux->rotY-=MOUSE_MUL_RY * drot;
	//traslada camara
	camaraPrimeraPersona->xview=aux->posX+sin(degToRad(aux->rotY));
	camaraPrimeraPersona->zview=aux->posZ+cos(degToRad(aux->rotY));
	//rota la camara hacia derecha
	//camaraPrimeraPersona->yrot+=MOUSE_MUL_RY * drot;
	//camaraPrimeraPersona->xview+=20;	

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

void exploraPorIzquierda(){
	activa->yrot+=MOUSE_MUL_RY * drot;
	redimensiona(currWidth, currHeight);
}

void exploraPorDerecha(){
	activa->yrot-=MOUSE_MUL_RY * drot;
	redimensiona(currWidth, currHeight);
}