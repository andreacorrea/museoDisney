#include "Movimientos.h"
#include "misInteracciones.h"
#include "iostream"

int pisoAvatar =1;


double degToRad(double deg){
	return deg*M_PI/180;
}

//verific la posicion del avatar en X y Z para determinar si sube o baja las escaleras
bool checarSubirBajar(){
	Objeto *prot=escena->objetos["protagonista"];
	if(pisoAvatar == 1 && prot->posX > MIN_ELEVATOR && prot->posX < MAX_ELEVATOR && prot->posZ > MIN_ELEVATOR && prot->posZ < MAX_ELEVATOR ){
		prot->rotY=45;
		prot->posY = 6;
		prot->posX = -5.5;
		camaraPrimeraPersona->xview=prot->posX+sin(degToRad(prot->rotY-180));
		camaraPrimeraPersona->zview=prot->posZ+cos(degToRad(prot->rotY-180));
		camaraPrimeraPersona->yview=7;
		pisoAvatar=2;
		return true;
	}else if(pisoAvatar == 2 && prot->posX > MIN_ELEVATOR+2 && prot->posX < MAX_ELEVATOR+2 && prot->posZ > MIN_ELEVATOR-3 && prot->posZ < MAX_ELEVATOR-3 ){
		prot->rotY=45;
		prot->posY = 0.25;
		prot->posX = -5;
		prot->posZ += 2.5;
		camaraPrimeraPersona->xview=prot->posX+sin(degToRad(prot->rotY-180));
		camaraPrimeraPersona->zview=prot->posZ+cos(degToRad(prot->rotY-180));
		camaraPrimeraPersona->yview=1;
		pisoAvatar=1;
		return true;
	}else{
		return false;
	}
}

//solo verifica que exista colision con el objeto protagonista
bool collision(GLfloat rotY){
    map <string, Objeto *>::iterator it1;
    map <string, Objeto *>::iterator it;
    //buscar avatar y guardar la localidad donde se encuentra en el map
	int angulo;
    angulo = ((int)rotY) %360;
    if(rotY < 0){
        angulo = abs(angulo);
        angulo = 360 - angulo;
        //printf("angulo negativo %i\n", angulo);

    }

    it1 = escena->objetos.find("protagonista");
    //
       
    //por cada objeto declarado en la clase
	cout << "Objeto"<< it1->first << " pos Z:"  << it1->second->posZ<< " pos X:"  << it1->second->posX << " angulo:"<<angulo<<endl;
    for ( it=escena->objetos.begin() ; it != escena->objetos.end(); it++){
        //buscar solo el objeto que tenga el nombre de pared
        if(it->first == "sombrero"){
            //objeto frente
            if((it->second->posZ + 1.9) > it1->second->posZ &&  (it->second->posZ) < it1->second->posZ &&  (angulo<90 || angulo > 270) && (it1->second->posX > it->second->posX - 1.9 ) && (it1->second->posX < it->second->posX + 1.9 )){
                cout<<"Col Frente!!!"<<endl;
                return true;
            }
			//objeto derecho
			if((it->second->posX + 1.9) > it1->second->posX &&  (it->second->posX) < it1->second->posX &&  (angulo < 180) && (it1->second->posZ > it->second->posZ - 1.9 ) && (it1->second->posZ < it->second->posZ + 1.9 )){
                cout<<"Col Der!!!"<<endl;
                return true;
            }
			// objeto izquierdo
			if((it->second->posX - 1.91) < it1->second->posX &&  (it->second->posX) > it1->second->posX &&  (angulo > 180) && (it1->second->posZ > it->second->posZ - 1.9 ) && (it1->second->posZ < it->second->posZ + 1.9 )){
                cout<<"Col Izq!!!"<<endl;
                return true;
            }

			 //objeto frente
            if((it->second->posZ - 1.9) < it1->second->posZ &&  (it->second->posZ) > it1->second->posZ &&  (angulo>90 && angulo < 270) && (it1->second->posX > it->second->posX - 1.9 ) && (it1->second->posX < it->second->posX + 1.9 )){
                cout<<"Col Atras!!!"<<endl;
                return true;
            }
            
        }
    }

	


	//Pared interna de fondo
	if(it1->second->posZ < PARED_FONDO && it1->second->posZ > (PARED_FONDO-1) && (angulo<90 || angulo > 270) && (it1->second->posX>PARED_IZQUIERDA && it1->second->posX<PARED_DERECHA)){
		return true;
	}
	//Pared derecha
	if(it1->second->posX > PARED_DERECHA && it1->second->posX < (PARED_DERECHA+1) && (angulo > 180) && (it1->second->posZ>PARED_FONDO && it1->second->posZ<PARED_NORTE)){
		return true;
	}
	// Pared Izquierda
	if(it1->second->posX < PARED_IZQUIERDA && it1->second->posX > (PARED_IZQUIERDA-1) && (angulo < 180 ) && (it1->second->posZ>PARED_FONDO && it1->second->posZ<PARED_NORTE)){
		return true;
	}

	//Pared interna norte izquierda
	if(it1->second->posZ > PARED_NORTE && it1->second->posZ < (PARED_NORTE+1) && (angulo>90 && angulo < 270) && (it1->second->posX>PARED_IZQUIERDA && it1->second->posX<PARED_NORTE_IZQUIERDA)){
		cout << "PARED->Objeto"<< it1->first << " pos Z:"  << it1->second->posZ<< " pos X:"  << it1->second->posX << " angulo:"<<angulo<<endl;
		return true;
	}

	//Pared interna norte derecha
	if(it1->second->posZ > PARED_NORTE && it1->second->posZ < (PARED_NORTE+1) && (angulo>90 && angulo < 270) && (it1->second->posX>PARED_NORTE_DERECHA && it1->second->posX<PARED_DERECHA)){
		cout << "PARED->Objeto"<< it1->first << " pos Z:"  << it1->second->posZ<< " pos X:"  << it1->second->posX << " angulo:"<<angulo<<endl;
		return true;
	}


        //cout << "Objeto"<< it1->first << " pos Z:"  << it1->second->posZ<< " pos X:"  << it1->second->posX << " angulo:"<<angulo<<endl;
    return false;

}

//hacia la camara es positivo
void moverAdelante(){

	Objeto *aux=escena->objetos["protagonista"];
	if(!checarSubirBajar()){
		if(!collision(aux->rotY-180)){
			double rotYRad= degToRad(aux->rotY-180);
			aux->posZ-= dtran*5 * (cos(rotYRad));
			aux->posX-=  dtran*5 * (sin(rotYRad));
			camaraPrimeraPersona->xview=aux->posX+sin(degToRad(aux->rotY-180));
			camaraPrimeraPersona->zview=aux->posZ+cos(degToRad(aux->rotY-180));
			redimensiona(currWidth,currHeight);	
		}
	}else{
		redimensiona(currWidth,currHeight);	
	}
	
}

void girarIzquierda(){
	Objeto *aux=escena->objetos["protagonista"];
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
	Objeto *aux=escena->objetos["protagonista"];
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