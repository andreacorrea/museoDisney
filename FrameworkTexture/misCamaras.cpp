#include "Escena.h"

// Definiciones de camaras - Mantener al menos las definiciones de camaraDefault y activa
Camara *camaraDefault;
Camara *activa;
Camara *camaraPrimeraPersona;
Camara *camaraSeguridad;
Camara *camaraVistaExterior;
//Definiciones de camaras especiales
Camara *camaraZenital;

void defineCamaras()
{
  // Definiciones de camaras - Mantener al menos la definicion de camaraDefault
  //camaraDefault = new Camara(0.0,0.0,-5.0,0.0,0.0,0.0,100000.0,1.0,90.0);
	camaraDefault = new Camara(0.0,0.0,-5.0,0.0,0.0,0.0,100000.0,1.0,90.0);
	camaraPrimeraPersona= new Camara(0.0,-1.0,-21.0,0.0,0.0,0.0,100000.0,0.5,90.0);//Tecla 1
	camaraSeguridad = new Camara(0.0,0.0,-5.0,90.0,0.0,0.0,100.0,1.0,90.0);//Tecla 2
	camaraVistaExterior = new Camara(0.0,-1.0,-21.5,0.0,0.0,0.0,100.0,1.0,90.0);//Tecla 3
	camaraZenital = new Camara(0.0,0.0,-5.0,90.0,0.0,0.0,100.0,1.0,90.0);//Tecla 4

  //Asignar a activa la camara con la que se desea iniciar
  
  activa=camaraVistaExterior;
}

