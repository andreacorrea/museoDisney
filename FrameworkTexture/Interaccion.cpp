#include "misInteracciones.h"
#include "movimientos.h"


void keyboard(unsigned char key,int x,int y)
{	
    //Atiende interacciones particulares para teclas simples
	miTeclado(key, x, y);
	//Atiende interacciones por default para teclas simples
	if(tecladoDefault)
		switch(key){
							  
			case '+': 
				/*if(activa == camaraVistaExterior){
					acercar();
				}*/
				break;

			case '-': 
				/*if(activa == camaraVistaExterior){
					alejar();
				}*/
				break;

			case 'x':
				activa->xrot+=drot;
				redimensiona(currWidth,currHeight);
				break;

			case 'y': 
				activa->yrot+=drot;
				redimensiona(currWidth,currHeight);
				break;

			case 'z': 
				activa->zrot+=drot;		  
				redimensiona(currWidth,currHeight);
				break;

			case 'X':
				activa->xrot-=drot;
				redimensiona(currWidth,currHeight);
				break;

			case 'Y':
				activa->yrot-=drot;
				redimensiona(currWidth,currHeight);
				break;

			case 'Z':
				activa->zrot-=drot;
				redimensiona(currWidth,currHeight);
				break;

			case 'w':
				if(activa==camaraPrimeraPersona || activa == camaraSeguridad1 || activa == camaraSeguridad2 || activa == camaraZenital){
					moverAdelante();
				}else if(activa ==camaraVistaExterior){
					moverArriba();
				}
				
				break;

			case 's':
				if(activa ==camaraVistaExterior){
					moverAbajo();
				}
				break;

			case 'a':
				if(activa==camaraPrimeraPersona || activa == camaraSeguridad1 || activa == camaraSeguridad2 || activa == camaraZenital){
					girarIzquierda();
				}else if(activa == camaraVistaExterior){
					exploraPorIzquierda();
				}
				
				break;

			case 'd':
				if(activa==camaraPrimeraPersona || activa == camaraSeguridad1 || activa == camaraSeguridad2 || activa == camaraZenital){
					girarDerecha();
				}else if(activa == camaraVistaExterior){
					exploraPorDerecha();
				}
				break;

			case '1':
				activa=camaraPrimeraPersona;
				redimensiona(currWidth,currHeight);
				break;
		            
			case '2':
				activa=camaraVistaExterior;
				redimensiona(currWidth,currHeight);
				break;

			case '3':
				activa=camaraSeguridad1;
				redimensiona(currWidth,currHeight);
				break;

			case '4':
				activa=camaraSeguridad2;
				redimensiona(currWidth,currHeight);
				break;

			case '5': 
				activa=camaraZenital;
				redimensiona(currWidth,currHeight);
				break;

			case ESCAPE: 
				exit(0);
				break;
		}
}

void keyboardSpec(int key,int x,int y)
{
    //Atiende interacciones particulares para teclas especiales
	miTecladoEspecial(key,x, y);
	//Atiende interacciones por default para teclas especiales
	if(tecladoDefault)
		switch(key)
		{
		  case GLUT_KEY_UP:        activa->yview+=dtran;
								   redimensiona(currWidth,currHeight);
								   break;

		  case GLUT_KEY_DOWN:      activa->yview-=dtran;
								   redimensiona(currWidth,currHeight);
								   break;

		  case GLUT_KEY_PAGE_UP:   activa->zview+=dtran;
								   redimensiona(currWidth,currHeight);
								   break;

		  case GLUT_KEY_PAGE_DOWN: activa->zview-=dtran;
								   redimensiona(currWidth,currHeight);
								   break;

		  case GLUT_KEY_LEFT:      activa->xview-=dtran;
								   redimensiona(currWidth,currHeight);
								   break;

		  case GLUT_KEY_RIGHT:     activa->xview+=dtran;
								   redimensiona(currWidth,currHeight);
								   break;
								   
		  case GLUT_KEY_F1:        escena->toggleLuz("light0");
								   break;
								   
		  case GLUT_KEY_F2:        escena->toggleLuz("light1");
								   break;
								   
		  case GLUT_KEY_F3:        escena->toggleLuz("light2");
								   break;
								   
		  case GLUT_KEY_F4:        escena->toggleLuz("light3");
								   break;
								   
		  case GLUT_KEY_F5:        escena->toggleLuz("light4");
								   break;
								   
		  case GLUT_KEY_F6:        escena->toggleLuz("light5");
								   break;
								   
		  case GLUT_KEY_F7:        escena->toggleLuz("light6");
								   break;
								   
		  case GLUT_KEY_F8:        escena->toggleLuz("light7");
								   break;							   							   
		}
}


void mouseClick(int button, int state, int x, int y)
{
  
  //Atiende interacciones particulares para mouse click
  miMouseClick(button, state, x, y);
  //Atiende interacciones por default parea mouse click
  if(mouseDefault)
  {
	switch (button) {
		case GLUT_LEFT_BUTTON:   leftMouse = (state==GLUT_DOWN);
								 break;
								 
		case GLUT_MIDDLE_BUTTON: middleMouse = (state==GLUT_DOWN);
							     break;
								 
		case GLUT_RIGHT_BUTTON:  rightMouse = (state==GLUT_DOWN);
							     break;

	}
	if (state==GLUT_UP) 
	{
	      //Reinicia las posiciones previas para permitir movimientos acumulativos
		  lastMouseX=0;
          lastMouseY=0;
	}
  }
}

void mouseDrag(int x, int y)
{
  GLfloat deltaX=(lastMouseX == 0) ? MOUSE_DELTA_MIN : (GLfloat)(x-lastMouseX)/currWidth;
  GLfloat deltaY=(lastMouseY == 0) ? MOUSE_DELTA_MIN : (GLfloat)(lastMouseY-y)/currHeight;
  
  //Atiende interacciones particulares para mouse drag
  miMouseDrag(x, y,deltaX,deltaY);
  //Atiende interacciones por default parea mouse drag
  if(mouseDefault)
  {
    if (leftMouse) //Desplazamiento horizontal/vertical
	{
		activa->xview+=MOUSE_MUL_TX * deltaX;
		activa->yview+=MOUSE_MUL_TY * deltaY;
		redimensiona(currWidth, currHeight);
	}
    if (middleMouse) //Zoom in/Zoom out
	{
		activa->zview+=MOUSE_MUL_TZ * deltaY;
		redimensiona(currWidth, currHeight);
	}
	if (rightMouse) //Movimiento horizontal, rotacion respecto a eje Y; Movimiento vertical, rotacion respecto a eje X
	{
	   activa->yrot+=MOUSE_MUL_RY * deltaX;
	   activa->xrot+=MOUSE_MUL_RX * deltaY;
	   redimensiona(currWidth, currHeight);
	}
  }
  lastMouseX=x;
  lastMouseY=y;
}




