#pragma once

#include "Interaccion.h"
#include "globales.h"
#define PICKBUFSIZE 512

void miTeclado(unsigned char key,int x,int y);
void miTecladoEspecial(int key,int x,int y);
void miMouseClick(int button, int state, int x, int y);
void miMouseDrag(int x, int y,GLfloat deltaX,GLfloat deltaY);
void miIdle();

//Picking
void startPicking(int cursorX, int cursorY);
void stopPicking();
void processHits (GLint hits);
void acciones(Objeto *o);