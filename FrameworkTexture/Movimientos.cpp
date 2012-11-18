#include "Movimientos.h"
#include "misInteracciones.h"
#include "iostream"


//solo verifica que exista colision con el objeto cuboAvatar
bool collision(GLfloat rotY){
    map <string, Objeto *>::iterator it1;
    map <string, Objeto *>::iterator it;
    //buscar avatar y guardar la localidad donde se encuentra en el map
    it1 = escena->objetos.find("cuboAvatar");
    //
    /*    
    //por cada objeto declarado en la clase
    for ( it=escena->objetos.begin() ; it != escena->objetos.end(); it++){
        //buscar solo el objeto que tenga el nombre de pared
        if(it->first == "pared"){
            
            if((it->second->posZ + 2.5) >=  (it1->second->posZ -.25)){
                cout<<"se esta pasando!!!"<<endl;
                return true;
            }
            
        }
    }*/

	/*
    int angulo;
    angulo = ((int)rotY) %360;
    if(rotY < 0){
        angulo = abs(angulo);
        angulo = 360 - angulo;
        //printf("angulo negativo %i\n", angulo);

    }
    //it1->second->posX > -1.7 && it1->second->posX < 1.7 && 
    if( it1->second->posZ > -2.70 && it1->second->posX > -1.75 && it1->second->posZ < 0.85 && it1->second->posX < 1.8){
        //printf("Aqui golpea %i\n",angulo);
        printf("estas adentro\n");
        // pared de fondo
        if(it1->second->posZ < -2.6 && (angulo < 90  || angulo > 270)){
            
            return true;
        }
        // pared izquierda
        if(it1->second->posX < -1.7 && angulo <180 && angulo>0 ){
            return true;
        }
        // pared derecha
        if(it1->second->posX > 1.7 && angulo >180 && angulo<360 ){
            return true;
        }

        // pared de frente
        if(it1->second->posZ < -2.6 && (angulo < 90  || angulo > 270)){
            printf("Aqui golpea %i\n",angulo);
            return true;
        }
    }

        cout << "Objeto"<< it1->first << " pos Z:"  << it1->second->posZ<< " pos X:"  << it1->second->posX << " angulo:"<<angulo<<endl;*/
    return false;

}


double degToRad(double deg){
	return deg*M_PI/180;
}

//hacia la camara es positivo
void moverAdelante(){

			Objeto *aux=escena->objetos["cuboAvatar"];
		if(!collision(aux->rotY-180)){
			double rotYRad= degToRad(aux->rotY-180);
			aux->posZ-= dtran*5 * (cos(rotYRad));
			aux->posX-=  dtran*5 * (sin(rotYRad));
			camaraPrimeraPersona->xview=aux->posX+sin(degToRad(aux->rotY-180));
			camaraPrimeraPersona->zview=aux->posZ+cos(degToRad(aux->rotY-180));
		
		redimensiona(currWidth,currHeight);
	}
}

void girarIzquierda(){
	Objeto *aux=escena->objetos["cuboAvatar"];
	//rota al avatar hacia izquierda
	aux->rotY+=MOUSE_MUL_RY * drot;

	//rota la camara hacia izquierda
	//camaraPrimeraPersona->yrot-=MOUSE_MUL_RY * drot;

	//traslada camara
	camaraPrimeraPersona->xview=aux->posX+sin(degToRad(aux->rotY-180));
	camaraPrimeraPersona->zview=aux->posZ+cos(degToRad(aux->rotY-180));

	redimensiona(currWidth, currHeight);
}

void girarDerecha(){
	Objeto *aux=escena->objetos["cuboAvatar"];
	//rota al avatar hacia derecha	
	aux->rotY-=MOUSE_MUL_RY * drot;
	//traslada camara
	camaraPrimeraPersona->xview=aux->posX+sin(degToRad(aux->rotY-180));
	camaraPrimeraPersona->zview=aux->posZ+cos(degToRad(aux->rotY-180));
	//rota la camara hacia derecha
	//camaraPrimeraPersona->yrot+=MOUSE_MUL_RY * drot;
	//camaraPrimeraPersona->xview+=20;	

	redimensiona(currWidth, currHeight);
}

void moverArriba(){
	if(camaraVistaExterior->xrot< MAX_XROT_CAMARA_EXTERIOR){
		camaraVistaExterior->xrot+=drot;
		redimensiona(currWidth, currHeight);
	}
	
}

void moverAbajo(){
	if(camaraVistaExterior->xrot>MIN_XROT_CAMARA_EXTERIOR){
		camaraVistaExterior->xrot-=drot;
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