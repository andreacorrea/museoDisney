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
	//printf("Z: posFin: %f\n", aux->posZ);

	
		Objeto *aux=escena->objetos["cuboAvatar"];
		double rotYRad= degToRad(aux->rotY);
		//mueve la camara hacia adelante
	if (!collision(aux->rotY)){// si no hay colisiones, entoncespuede continuar
		camaraPrimeraPersona->zview+= dtran;
		//camaraPrimeraPersona->xview+= dtran;
		//mueve al avatar hacia adelante
		aux->posZ-= dtran * (cos(rotYRad));
		aux->posX-=  dtran * (sin(rotYRad));
		redimensiona(currWidth,currHeight);		  
	} 

	printf("Angulo de rotY de avatar: %f\n", escena->objetos["cuboAvatar"]->rotY);
	printf("Angulo de rotY de camara: %f\n", camaraPrimeraPersona->yrot);
	printf("PosZ de avatar: %f\n", escena->objetos["cuboAvatar"]->posZ);
	printf("PosZ de camara: %f\n", camaraPrimeraPersona->zview);
		
}

void girarIzquierda(){
	Objeto *aux=escena->objetos["cuboAvatar"];
	//rota al avatar hacia derecha
	escena->objetos["cuboAvatar"]->rotY+=MOUSE_MUL_RY * drot;
	
	//rota la camara hacia derecha

	//camaraPrimeraPersona->yrot-=MOUSE_MUL_RY * drot;
	

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
	//rota la camara hacia derecha
	//camaraPrimeraPersona->yrot+=MOUSE_MUL_RY * drot;
	
	//rota al avatar hacia derecha
	escena->objetos["cuboAvatar"]->rotY-=MOUSE_MUL_RY * drot;
	//float distance=5;      // Straight line distance between the camera and look at point
	redimensiona(currWidth, currHeight);
}