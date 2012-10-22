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


void moverAdelante(){
	if (!collision()){// si no hay colisiones, entoncespuede continuar
		//mueve la camara hacia adelante
		activa->zview+=dtran;
		//mueve al avatar hacia adelante
		escena->objetos["cuboAvatar"]->posZ=escena->objetos["cuboAvatar"]->posZ-dtran;
		redimensiona(currWidth,currHeight);		  
	}
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