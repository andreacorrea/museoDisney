#pragma once
#include "Escena.h"

//Definiciones de camaras - Mantener al menos las definiciones de camaraDefault y activa
extern Camara *camaraDefault;
extern Camara *activa;
extern Camara *camaraPrimeraPersona;
extern Camara *camaraVistaExterior;
extern Camara *camaraSeguridad1;
extern Camara *camaraSeguridad2;

//Definiciones de camaras especiales
extern Camara *camaraZenital;

void defineCamaras();




