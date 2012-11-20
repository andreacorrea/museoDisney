#include "misComposiciones.h"
#include <iostream>
#include "misInteracciones.h"
#include "iostream"

int flagpiso =1;

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

void muestraCastillo()
{
  //escena->agregaObjeto("castillo", (Objeto *) new Modelo("castillo1"));
	escena->agregaObjeto("castillo", (Objeto *) new Modelo("castillotexturas"));
	escena->objetos["castillo"]->escalaUniforme(20.0);
	escena->objetos["castillo"]->rotY=-90;
	escena->objetos["castillo"]->posY=17.5;

}


void muestraSkydome()
{ 

    //Esfera que sirve como Sky Dome. IMPORTANTE: lighting, el ultimo parametro de defineMaterial, es false 
    escena->agregaObjeto("skydome",(Objeto *) new Esfera(80.0,30,30,1.0,1.0,1.0));
    escena->objetos["skydome"]->velRotX=0.1;
	escena->objetos["skydome"]->defineMaterial(1.0,1.0,1.0,
										 1.0,1.0,1.0,
										 0.0,0.0,0.0,
										 0.0,0.0,0.0,
										 "sky1.tga",GL_REPEAT,1.0,0.0,0.0,0.0,0.0,1.0,GL_SPHERE_MAP,false);
}


void muestraSombrero()
{
  escena->agregaObjeto("sombrero", (Objeto *) new Modelo("sombrero"));
  escena->objetos["sombrero"]->escalaUniforme(1.9);
  escena->objetos["sombrero"]->posY=1.15;
  escena->objetos["sombrero"]->posZ=-5.0;
  escena->objetos["sombrero"]->velRotY=0.6;
  escena->modificaMaterial("sombrero", "blinn3SG", "sombrero.tga", GL_EYE_LINEAR, 1.0);
  /*escena->objetos["sombrero"]->defineMaterial(1.0,1.0,1.0,
  									 1.0,1.0,1.0,
  									 0.0,0.0,0.0,
  									 0.0,0.0,0.0,
  									 "sombrero.tga",GL_REPEAT,1.0,0.0,0.0,0.0,0.0,1.0,GL_SPHERE_MAP,false);*/
}

void muestraPelota()
{
  escena->agregaObjeto("pelota", (Objeto *) new Modelo("pelota"));
  escena->objetos["pelota"]->escalaUniforme(1.5);
  escena->objetos["pelota"]->posY=7.85;
  escena->objetos["pelota"]->posZ=-5.0;
  escena->objetos["pelota"]->velRotY=0.6;
  escena->modificaMaterial("pelota", "blinn1SG", "pelota.tga", GL_EYE_LINEAR, 0.5);
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

//Autor: Alonso Rodriguez
//cuboIrregular(nombre del objeto, tamanio en X, tamanio en Y, tamanio en Z, pos en X, pos en Y, pos en Z)
void plano(char *nombre, GLfloat sizeX,GLfloat sizeY,GLfloat sizeZ, GLfloat pX, GLfloat pY, GLfloat pZ){
		escena->agregaObjeto(nombre, (Objeto *) new Cubo(1,0.326,1.0,0.019)); //70,159,5
		escena->objetos [nombre]->posX=pX;
		escena->objetos [nombre]->posZ=pZ;
		escena->objetos [nombre]->posY=pY;
		escena->objetos [nombre]->escalaX=sizeX;
		escena->objetos [nombre]->escalaZ=sizeZ;
		escena->objetos [nombre]->escalaY=sizeY;
}

void demuestraPared()
{
  escena->agregaObjeto("pared", (Objeto *) new Cubo(5, 0.0, 0.0, 1.0));
  escena->objetos["pared"]->posZ=-2.50;
  escena->objetos["pared"]->posY=2.5;
  
}

void muestraProtagonista()
{
  escena->agregaObjeto("protagonista",(Objeto *) new Poses("pose%d",6,3));
  escena->objetos["protagonista"]->posY=0.25;
  escena->objetos["protagonista"]->posZ=20;
  escena->objetos["protagonista"]->rotY=180;
}

//metodos para la manzana
void baseManzana(){
	escena->agregaObjeto("baseManzana", (Objeto *) new Cubo(0.4, 0.0, 0.0, 1.0));
	escena->objetos["baseManzana"]->posZ=-2.3;
	escena->objetos["baseManzana"]->posX=-7.7;
	escena->objetos["baseManzana"]->posY=0.20;
	escena->objetos["baseManzana"]->escalaY=4.0;
	escena->objetos["baseManzana"]->defineMaterial(1.0,1.0,1.0,1.0,1.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,
								"moho.tga",GL_REPEAT,0.5,0.0,0.0,0.0,0.0,1.0,GL_SPHERE_MAP,false);
	
}

void muestraManzana()
{
  escena->agregaObjeto("manzana", (Objeto *) new Modelo("manzana"));
  escena->objetos["manzana"]->escalaUniforme(0.5);
  escena->objetos["manzana"]->posX=-7.7;
  escena->objetos["manzana"]->posY=1.38;
  escena->objetos["manzana"]->posZ=-2.3;
  escena->objetos["manzana"]->velRotY=0.6;
  escena->modificaMaterial("manzana", "blinn1SG", "manzanacolor.tga", GL_EYE_LINEAR, 0.5);

}

//metodos para la lampara
void baseLampara(){
	escena->agregaObjeto("baseLampara", (Objeto *) new Cubo(0.4, 0.0, 0.0, 1.0));
	escena->objetos["baseLampara"]->posZ=-5;
	escena->objetos["baseLampara"]->posX=7.0;
	escena->objetos["baseLampara"]->posY=0.20;
	escena->objetos["baseLampara"]->escalaY=4.0;
	escena->objetos["baseLampara"]->defineMaterial(1.0,1.0,1.0,1.0,1.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,
								"moho.tga",GL_REPEAT,0.5,0.0,0.0,0.0,0.0,1.0,GL_SPHERE_MAP,false);
	
}

void muestraLampara()
{
  escena->agregaObjeto("lampara", (Objeto *) new Modelo("lampara"));
  escena->objetos["lampara"]->escalaUniforme(0.45);
  escena->objetos["lampara"]->posX=7.0;
  escena->objetos["lampara"]->posY=1.4;
  escena->objetos["lampara"]->posZ=-5;
  escena->objetos["lampara"]->velRotY=0.6;
  //escena->modificaMaterial("manzana", "blinn1SG", "moho.tga", GL_EYE_LINEAR, 0.5);

}

//metodos para la globo
void baseGlobo(){
	escena->agregaObjeto("baseGlobo", (Objeto *) new Cubo(0.4, 0.0, 0.0, 1.0));
	escena->objetos["baseGlobo"]->posX=7;
	escena->objetos["baseGlobo"]->posY=6.3;
	escena->objetos["baseGlobo"]->posZ=-5.2;
	escena->objetos["baseGlobo"]->escalaY=4.0;
	escena->objetos["baseGlobo"]->defineMaterial(1.0,1.0,1.0,1.0,1.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,
								"moho.tga",GL_REPEAT,0.5,0.0,0.0,0.0,0.0,1.0,GL_SPHERE_MAP,false);
}

void muestraGlobo()
{
	escena->agregaObjeto("globo", (Objeto *) new Modelo("globo"));
	escena->objetos["globo"]->escalaUniforme(0.45);
	escena->objetos["globo"]->posX=7;
	escena->objetos["globo"]->posY=7.5;
	escena->objetos["globo"]->posZ=-5.2;
	escena->objetos["globo"]->velRotY=0.6;
	//escena->modificaMaterial("manzana", "blinn1SG", "moho.tga", GL_EYE_LINEAR, 0.5);

}

void muestraCandelabros()
{
	escena->agregaObjeto("candelabro", (Objeto *) new Modelo("candelabro"));
	escena->objetos["candelabro"]->escalaUniforme(1.2);
	escena->objetos["candelabro"]->posX=-3;
	escena->objetos["candelabro"]->posY=4.4;
	escena->objetos["candelabro"]->posZ=-5.0;

	escena->agregaObjeto("candelabro2", (Objeto *) new Modelo("candelabro"));
	escena->objetos["candelabro2"]->escalaUniforme(1.2);
	escena->objetos["candelabro2"]->posX=3;
	escena->objetos["candelabro2"]->posY=4.4;
	escena->objetos["candelabro2"]->posZ=-5.0;

	escena->agregaObjeto("candelabro3", (Objeto *) new Modelo("candelabro"));
	escena->objetos["candelabro3"]->escalaUniforme(1.2);
	escena->objetos["candelabro3"]->posX=-3;
	escena->objetos["candelabro3"]->posY=12.6;
	escena->objetos["candelabro3"]->posZ=-5.0;

	escena->agregaObjeto("candelabro4", (Objeto *) new Modelo("candelabro"));
	escena->objetos["candelabro4"]->escalaUniforme(1.2);
	escena->objetos["candelabro4"]->posX=3;
	escena->objetos["candelabro4"]->posY=12.6;
	escena->objetos["candelabro4"]->posZ=-5.0;

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

void posicionarQuad(string nombreQuad, GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat rotX, GLfloat rotY, GLfloat velS, GLfloat velT, GLfloat texEscala){
	escena->objetos[nombreQuad]->posX=posX;
	escena->objetos[nombreQuad]->posY=posY;
	escena->objetos[nombreQuad]->posZ=posZ;
	escena->objetos[nombreQuad]->rotY=rotY;
	escena->objetos[nombreQuad]->rotX=rotX;
	((AlphaQuad *)escena->objetos[nombreQuad])->texVelS=velS;
	((AlphaQuad *)escena->objetos[nombreQuad])->texVelT=velT;
	((AlphaQuad *)escena->objetos[nombreQuad])->texEscala = texEscala;
}

void muestraQuad(string nombreQuad, string nombreTextura, GLfloat ancho, GLfloat alto, GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat rotY, GLfloat rotX){
	escena->agregaObjeto(nombreQuad, (Objeto *) new AlphaQuad(escena, nombreTextura, GL_REPEAT, 1.0, ancho, alto, 0.0, 0.0, 1.0, 0, 0.00));
	posicionarQuad(nombreQuad, posX, posY, posZ, rotX, rotY, 0, 0, 1);
	
}

void muestraQuad(string nombreQuad, string nombreTextura, GLfloat ancho, GLfloat alto, GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat rotY, GLfloat rotX, GLfloat velS, GLfloat velT, GLfloat texEscala){
	escena->agregaObjeto(nombreQuad, (Objeto *) new AlphaQuad(escena, nombreTextura, GL_REPEAT, 1.0, ancho, alto, 0.0, 0.0, 1.0, 0, 0.00));
	posicionarQuad(nombreQuad, posX, posY, posZ, rotX, rotY, velS, velT, texEscala);
	
}

void muestraCuadros(){
	GLfloat ancho=2.5;
	GLfloat alto=4.0;
	GLfloat primerPisoPosY=2;
	GLfloat segundopisoPosY=8;
	GLfloat paredIzqX = -8.275;
	GLfloat paredDerX = 7.625;
	GLfloat paredFondoZ = -11.0;
	GLfloat paredPuertaZ = -0.7;
	//Cuadros primer piso
	muestraQuad("CuadroBlancanieves", "cuadros/CuadroBlancanieves.tga", ancho, alto, paredIzqX, primerPisoPosY, -4, 90, 0);
	muestraQuad("infoBlancaNieves", "cuadros/CuadroBlancanieves_informacion.tga", 0.01, 0.01, -8.27, primerPisoPosY, -4, 90, 0);
	muestraQuad("CuadroAprendizBrujo", "cuadros/CuadroAprendizBrujo.tga", ancho, alto, -2, primerPisoPosY, paredFondoZ, 0, 0);
	muestraQuad("CuadroBellaYBestia", "cuadros/CuadroCuadroBellaYBestia.tga", ancho, alto, 3, primerPisoPosY, paredFondoZ, 0, 0);
	muestraQuad("CuadroPinocho", "cuadros/CuadroPinocho.tga", ancho, alto, paredDerX, primerPisoPosY, -7.5, 90, 0);
	muestraQuad("CuadroAladdin", "cuadros/CuadroAladdin.tga", ancho, alto, paredDerX, primerPisoPosY, -2.5, 90, 0);
	

	//Cuadros segundo piso
	
	muestraQuad("CuadroToyStory", "cuadros/CuadroToyStory.tga", ancho, alto, -2, segundopisoPosY, paredFondoZ, 0, 0);
	muestraQuad("CuadroIncreibles", "cuadros/CuadroIncreibles.tga", ancho, alto, 3, segundopisoPosY, paredFondoZ, 0, 0);
	muestraQuad("CuadroNemo", "cuadros/CuadroNemo.tga", ancho, alto, paredDerX, segundopisoPosY, -2.5, 90, 0);
	muestraQuad("CuadroUp", "cuadros/CuadroUp.tga", ancho, alto, paredDerX, segundopisoPosY, -7.5, 90, 0);
	muestraQuad("CuadroWallE", "cuadros/CuadroWallE.tga", ancho, alto, -4, segundopisoPosY, -0.9, 0, 0);
	muestraQuad("CuadroMonstersInc", "cuadros/CuadroMonstersInc.tga", ancho, alto, 3, segundopisoPosY, paredPuertaZ, 0, 0);
	
}

void muestraCuadroSubirBajar(){
	muestraQuad("cuadroSubir", "subir.tga", 1.5, 1.5, -7, FLOOR_1_Y, -7, 0, 90);
	muestraQuad("cuadroBajar", "bajar.tga", 1.5, 1.5, -5, FLOOR_2_Y, -10, 0, 90);
	//muestraCuadro("cuadroBajar", "agua.tga", 5, 5, 0, 0, 0, 0, 90);
	//escena->objetos["cuadroSubir"]->anulaMaterial();
	//muestraCuadro("cuadroSubir", "bumpy.tga", 1.5, 1.5, -6, -0.725, -3, 0, 90);
	/*escena->objetos["cuadroSubir"]->defineMaterial(1.0,1.0,1.0,
										 1.0,1.0,1.0,
										 0.0,0.0,0.0,
										 0.0,0.0,0.0,
										 "bumpy.tga",GL_CLAMP,0.5,0.0,0.0,0.0,0.0,1.0,GL_OBJECT_LINEAR,false);*/
}


//muestra cuadros de informacion
void checaPosicionCuadro(){

	Objeto *prot=escena->objetos["protagonista"];
	//blancaNieves info X: -7.5 , Z:-4
	if(prot->posX < -6.75  && prot->posX > -8.25 && prot->posZ > -4.75 && prot->posZ < -3.25 ){
		escena->objetos["infoBlancaNieves"]->escalaY=4.0;
		escena->objetos["infoBlancaNieves"]->escalaX=2.5;
	}
}

void muestraRio(){
	/*
	muestraQuad("rio1", "agua.tga", 32, 11.5, 0, -0.55, 7.47, 0, 90, 0.005, 0.005, 0.25);
	muestraQuad("rio2", "agua.tga", 6.475, 14.5, -12.75, -0.5, -5.3, 0, 90, 0.005, 0.005, 0.25);
	muestraQuad("rio3", "agua.tga", 32, 8, 0, -0.5, -16.25, 0, 90, 0.005, 0.005, 0.25);
	muestraQuad("rio4", "agua.tga", 6.475, 14.5, 12.75, -0.5, -5.3, 0, 90, 0.005, 0.005, 0.25);*/
	//o
	muestraQuad("rio1", "agua.tga", 40, 40, 0, -0.55, -6.8, 0, 90, 0.005, 0.005, 0.25);
}

void muestraAlfombra(){
	/*
	muestraQuad("rio1", "agua.tga", 32, 11.5, 0, -0.55, 7.47, 0, 90, 0.005, 0.005, 0.25);
	muestraQuad("rio2", "agua.tga", 6.475, 14.5, -12.75, -0.5, -5.3, 0, 90, 0.005, 0.005, 0.25);
	muestraQuad("rio3", "agua.tga", 32, 8, 0, -0.5, -16.25, 0, 90, 0.005, 0.005, 0.25);
	muestraQuad("rio4", "agua.tga", 6.475, 14.5, 12.75, -0.5, -5.3, 0, 90, 0.005, 0.005, 0.25);*/
	//

	muestraQuad("alfombra", "alfombra.tga", 17, 13, -.2, -.5, -5, 0, 90, 0.0, 0.0, 0.25);
	muestraQuad("alfombra2", "alfombra.tga", 13.5, 11.5, 1, 5.33, -5.3, 0, 90, 0.0, 0.0, 0.25);
}

void creaEscena()
{
	plano("plano", 200,1,200,0,-1.06,0);
	muestraAlfombra();
	muestraSkydome();
	muestraCastillo();
	muestraSombrero();

	muestraProtagonista();
	//manzana
	baseManzana();
	muestraManzana();
	//lampara
	baseLampara();
	muestraLampara();
	//globo
	baseGlobo();
	muestraGlobo();
	muestraCuadroSubirBajar();
	muestraCuadros();
	muestraRio();
	muestraPelota();
	muestraCandelabros();
	//cuadros para info
	checaPosicionCuadro();

}

