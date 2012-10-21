#include "misComposiciones.h"

void defineLuces()
{
    escena->defineLuz("light0",'D', 1.0, 1.0, 1.0);
	escena->posicionLuz("light0", 0.0, 3.0, 1.0);
	
    escena->defineLuz("light1",'E', 1.0, 1.0, 1.0);
	escena->posicionLuz("light1", 1.0, -2.0, 1.0);
	
	escena->defineLuz("light2",'S', 1.0, 1.0, 1.0);
	escena->posicionLuz("light2", 0.0, 8.0, 0.0);
	escena->direccionLuz("light2", 0.0, -1.0, 0.0);
	escena->anguloLuz("light2", 30.0);
}

void demuestraModelo()
{
  escena->agregaObjeto("ejemplo", (Objeto *) new Modelo("al"));
  escena->objetos["ejemplo"]->escalaUniforme(3.0);
}


void demuestraMateriales()
{ 

    //Esfera que sirve como Sky Dome. IMPORTANTE: lighting, el ultimo parametro de defineMaterial, es false 
    escena->agregaObjeto("skydome",(Objeto *) new Esfera(40.0,30,30,1.0,1.0,1.0));
    escena->objetos["skydome"]->velRotX=0.1;
	escena->objetos["skydome"]->defineMaterial(1.0,1.0,1.0,
										 1.0,1.0,1.0,
										 0.0,0.0,0.0,
										 0.0,0.0,0.0,
										 "agua.tga",GL_REPEAT,0.5,0.0,0.0,0.0,0.0,1.0,GL_SPHERE_MAP,false);


    //Modelo Texturizado
	escena->agregaObjeto("f-16", (Objeto *) new Modelo("f-16",TEX_SPHERE));//como se va a mapear, mapeo esférico, metalico
	escena->objetos["f-16"]->escalaUniforme(2.0);
	//escena->objetos["f-16"]->velRotX=1.0;
	escena->modificaMaterial("f-16", "blue", "chrome.tga", GL_REPEAT, 1.0,1.0,0.0,0.0);//al grupo de poligonos debe aplicarle la textura chrome repetidamente
    escena->modificaMaterial("f-16", "glass", "agua.tga", GL_REPEAT, 0.5);//0.5 de transparencia
	
	
	//Tres objetos iguales que copian el material del modelo con los diferentes modos de mapeo de texturas
	escena->agregaObjeto("tetera1",(Objeto *) new Tetera(1.0,1.0,0.0,1.0));
    escena->objetos["tetera1"]->velRotX=-1.0;
	escena->objetos["tetera1"]->posX=-5.0;
	escena->objetos["tetera1"]->posY=3.0;
	escena->objetos["tetera1"]->loopFrames=200;
	escena->objetos["tetera1"]->copiaMaterial("f-16","blue",GL_OBJECT_LINEAR);//modo de mapeo textura pegada al objeto
	
	escena->agregaObjeto("tetera2",(Objeto *) new Tetera(1.0,1.0,0.0,1.0));
    escena->objetos["tetera2"]->velRotX=-1.0;
	escena->objetos["tetera2"]->posY=3.0;
	escena->objetos["tetera2"]->loopFrames=200;
	escena->objetos["tetera2"]->copiaMaterial("f-16","blue",GL_EYE_LINEAR);//textura fija el objeto se mueve sobre la textura
	
	escena->agregaObjeto("tetera3",(Objeto *) new Tetera(1.0,1.0,0.0,1.0));
    escena->objetos["tetera3"]->velRotX=-1.0;
	escena->objetos["tetera3"]->posX=5.0;
	escena->objetos["tetera3"]->posY=3.0;
	escena->objetos["tetera3"]->loopFrames=200;
	escena->objetos["tetera3"]->copiaMaterial("f-16","blue",GL_SPHERE_MAP);//sensacion de metal
	
}

void demuestraCubo()
{
  escena->agregaObjeto("cuboAvatar", (Objeto *) new Cubo(0.5, 1.0, 0.0, 0.0));
  escena->objetos["cuboAvatar"]->posZ=5.0;
  escena->objetos["cuboAvatar"]->posY=-1.0;
  
}

void referencias(){
	escena->agregaObjeto("x-", (Objeto *) new Esfera(0.1, 20,20,0,0,1));
	escena->objetos["x-"]->posX=-3;
	escena->agregaObjeto("x+", (Objeto *) new Esfera(0.1, 20,20,0,0,1));
	escena->objetos["x+"]->posX=3;

	escena->agregaObjeto("y-", (Objeto *) new Esfera(0.1, 20,20,0,1,0));
	escena->objetos["y-"]->posY=-3;
	escena->agregaObjeto("y+", (Objeto *) new Esfera(0.1, 20,20,0,1,0));
	escena->objetos["y+"]->posY=3;

	escena->agregaObjeto("z-", (Objeto *) new Esfera(0.1, 20,20,1,1,1));
	escena->objetos["z-"]->posZ=-3;
	escena->agregaObjeto("z+", (Objeto *) new Esfera(0.1, 20,20,1,1,1));
	escena->objetos["z+"]->posZ=3;
}

void creaEscena()
{
	//demuestraModelo();
	//demuestraMateriales();
	referencias();
	demuestraCubo();

}

