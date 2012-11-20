#include "misInteracciones.h"

GLuint selectBuf[PICKBUFSIZE];

//Interacciones particulares con teclado y mouse

void miTeclado(unsigned char key,int x,int y)
{
   //Definir comportamientos particulares para teclas simples
   switch (key) 
   {
		            
   }
   //Para desactivar comportamiento por default, hacer tecladoDefault=false 
}


void miTecladoEspecial(int key,int x,int y)
{
  //Definir comportamientos particulares para teclas especiales
  switch (key) 
  {

  }
  //Para desactivar comportamiento por default, hacer tecladoDefault=false 
}


void miMouseClick(int button, int state, int x, int y)
{
  //Definir comportamientos particulares para mouse click
 
  //Para desactivar comportamiento por default, hacer mouseDefault=false  
	/*if(button== GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		mouseDefault=false;
		startPicking(x,y);
		escena->dibujaEscena();
		stopPicking();
	}*/
}

void miMouseDrag(int x, int y,GLfloat deltaX,GLfloat deltaY)
{
  //Definir comportamientos particulares para mouse drag
  
  //Para desactivar comportamiento por default, hacer mouseDefault=false 
}


void miIdle()
{
  //Definir acciones especiales que deben ejecutarse en el idle del ciclo de GLUT
  
}

void startPicking(int cursorX, int cursorY) {
	GLint viewport[4];
	glSelectBuffer(PICKBUFSIZE,selectBuf);
	glRenderMode(GL_SELECT);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glGetIntegerv(GL_VIEWPORT,viewport);
	gluPickMatrix(cursorX,viewport[3]-cursorY,5,5,viewport);
	gluPerspective(activa->fovy,(GLdouble)currWidth/(GLdouble)currHeight, activa->near,activa->far);
	glTranslatef(activa->xview,activa->yview,activa->zview); 
	glRotatef(activa->xrot,1.0,0.0,0.0);
	glRotatef(activa->yrot,0.0,1.0,0.0);
	glRotatef(activa->zrot,0.0,0.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glInitNames();
}

void stopPicking() {
	int hits; 
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glFlush();
	hits = glRenderMode(GL_RENDER);
	if (hits != 0)
		processHits(hits);
}

void processHits (GLint hits){
   GLuint i,j,index,nitems,zmin,zmax,seleccion;
	// Procesa multiples hits
	for( i = 0, index = 0; i < hits; i++ ) { 
		  nitems = selectBuf[index++]; 
		  zmin = selectBuf[index++]; 
		  zmax = selectBuf[index++];  
		  for( j = 0; j < nitems; j++ ) { 
			 seleccion = selectBuf[index++]; 
			// Se busca el objeto de la escena con el hitName seleccionado
			map<string, Objeto *>::const_iterator iter;   
			for (iter=escena->objetos.begin(); iter != escena->objetos.end(); ++iter){
				Objeto *o=(Objeto *)iter->second;
				if (o->hitName==seleccion){
					acciones(o);
					//escena->objetos.erase(iter->first);
				}
			}
		}
	}
}

void acciones(Objeto *o){
  //Acciones con el objeto seleccionado
	/*if (o->velZ!=0.0) {
		o->velZ=0.0;
   }
   else{
		o->velZ=0.1;  
   }*/
	o->escalaUniforme(2);
}


