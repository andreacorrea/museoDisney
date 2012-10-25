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

	if (!collision()){// si no hay colisiones, entoncespuede continuar
		Objeto *aux=escena->objetos["cuboAvatar"];
		double rotYRad= degToRad(aux->rotY);
		//mueve la camara hacia adelante
		camaraPrimeraPersona->zview+= dtran * (cos(rotYRad));
		camaraPrimeraPersona->xview+= dtran * (sin(rotYRad));
		//mueve al avatar hacia adelante
		aux->posZ-= dtran * (cos(rotYRad));
		aux->posX-=  dtran * (sin(rotYRad));
		redimensiona(currWidth,currHeight);		  
	} 
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

