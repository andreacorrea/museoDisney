#include "misComposiciones.h"
#include <iostream>

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
  escena->agregaObjeto("castillo", (Objeto *) new Modelo("castillo1"));
  escena->objetos["castillo"]->escalaUniforme(20.0);
  escena->objetos["castillo"]->rotY=-90;
	escena->objetos["castillo"]->posY=14.6;
}

void muestraSombrero()
{
  escena->agregaObjeto("sombrero", (Objeto *) new Modelo("sombrero"));
  escena->objetos["sombrero"]->escalaUniforme(1.9);
  escena->objetos["sombrero"]->posY=1.15;
  escena->objetos["sombrero"]->posZ=-5.0;
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
		escena->agregaObjeto(nombre, (Objeto *) new Cubo(1,0.0,1.0,0.0));
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
	/*escena->agregaObjeto("cuboAvatar", (Objeto *) new Cubo(1.0, 1.0, 0.0, 0.0));
	escena->objetos["cuboAvatar"]->agregaDescendiente("frente", (Objeto *) new Esfera(0.1, 20, 20, 0.0, 1.0, 0.0));
	escena->objetos["cuboAvatar"]->descendientes["frente"]->posZ=-0.5;
	//escena->objetos["cuboAvatar"]->posZ=5.0;
	escena->objetos["cuboAvatar"]->posY=-1.0;*/
	//escena->agregaObjeto("CuboAvatar",(Objeto *) new Poses("pose%d",5,3));
  escena->agregaObjeto("cuboAvatar",(Objeto *) new Poses("pose%d",5,3));
  //escena->agregaObjeto("cuboAvatar", (Objeto *) new Cubo(0.5, 1.0, 0.0, 0.0));
  escena->objetos["cuboAvatar"]->posY=0.25;
  escena->objetos["cuboAvatar"]->posZ=20;
  escena->objetos["cuboAvatar"]->rotY=180;
}

void cuboParaElClic(){
escena->agregaObjeto("cuboParaElClic1", (Objeto *) new Cubo(0.3, 0.0, 0.5, 0.5));
escena->objetos["cuboParaElClic1"]->posZ=-0.25;
escena->objetos["cuboParaElClic1"]->posX=-1.9;
escena->objetos["cuboParaElClic1"]->posY=1.0;

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

void muestraCuadro(string nombreCuadro, string nombreTextura, GLfloat ancho, GLfloat alto, GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat rotY, GLfloat rotX){
	escena->agregaObjeto(nombreCuadro, (Objeto *) new AlphaQuad(escena, nombreTextura, GL_REPEAT, 1.0, ancho, alto, 0.0, 0.0, 1.0, 0, 0.00));
	escena->objetos[nombreCuadro]->posX=posX;
	escena->objetos[nombreCuadro]->posY=posY;
	escena->objetos[nombreCuadro]->posZ=posZ;
	escena->objetos[nombreCuadro]->rotY=rotY;
	escena->objetos[nombreCuadro]->rotX=rotX;
}

void muestraCuadros(){
	GLfloat ancho=2.5;
	GLfloat alto=4.0;
	GLfloat primerPisoPosY=2;
	GLfloat segundopisoPosY=7;
	GLfloat paredIzqX = -8.275;
	GLfloat paredDerX = 7.625;
	GLfloat paredFondoZ = -11.0;
	GLfloat paredPuertaZ = -0.7;
	//Cuadros primer piso
	muestraCuadro("CuadroBlancanieves", "agua.tga", ancho, alto, paredIzqX, primerPisoPosY, -4, 90, 0);
	muestraCuadro("CuadroAprendizBrujo", "moho.tga", ancho, alto, -2, primerPisoPosY, paredFondoZ, 0, 0);
	muestraCuadro("CuadroBellaYBestia", "stone.tga", ancho, alto, 3, primerPisoPosY, paredFondoZ, 0, 0);
	muestraCuadro("CuadroPinocho", "chrome.tga", ancho, alto, paredDerX, primerPisoPosY, -7.5, 90, 0);
	muestraCuadro("CuadroAladdin", "bumpy.tga", ancho, alto, paredDerX, primerPisoPosY, -2.5, 90, 0);
	

	//Cuadros segundo piso
	
	muestraCuadro("CuadroToyStory", "moho.tga", ancho, alto, -2, segundopisoPosY, paredFondoZ, 0, 0);
	muestraCuadro("CuadroIncreibles", "stone.tga", ancho, alto, 3, segundopisoPosY, paredFondoZ, 0, 0);
	muestraCuadro("CuadroNemo", "bumpy.tga", ancho, alto, paredDerX, segundopisoPosY, -2.5, 90, 0);
	muestraCuadro("CuadroUp", "chrome.tga", ancho, alto, paredDerX, segundopisoPosY, -7.5, 90, 0);
	muestraCuadro("CuadroWallE", "hoja.tga", ancho, alto, -2, segundopisoPosY, paredPuertaZ, 0, 0);
	muestraCuadro("CuadroMonstersInc", "agua.tga", ancho, alto, 3, segundopisoPosY, paredPuertaZ, 0, 0);

}

void muestraCuadroSubirBajar(){
	muestraCuadro("cuadroSubir", "agua.tga", 1.5, 1.5, -7, -0.725, -7, 0, 90);
	//muestraCuadro("cuadroBajar", "agua.tga", 5, 5, 0, 0, 0, 0, 90);
	//escena->objetos["cuadroSubir"]->anulaMaterial();
	//muestraCuadro("cuadroSubir", "bumpy.tga", 1.5, 1.5, -6, -0.725, -3, 0, 90);
	/*escena->objetos["cuadroSubir"]->defineMaterial(1.0,1.0,1.0,
										 1.0,1.0,1.0,
										 0.0,0.0,0.0,
										 0.0,0.0,0.0,
										 "bumpy.tga",GL_CLAMP,0.5,0.0,0.0,0.0,0.0,1.0,GL_OBJECT_LINEAR,false);*/
}

void creaEscena()
{

	muestraCastillo();
	muestraSombrero();

	muestraProtagonista();
	//cuboParaElClic();
	muestraCuadroSubirBajar();
	//muestraCuadros();
}

