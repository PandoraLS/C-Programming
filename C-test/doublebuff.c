/*
 * @Author: seenli 
 * @Date: 2020-11-17 15:50:31 
 * @Last Modified by: seenli
 * @Last Modified time: 2020-11-17 16:07:12
 */

// http://www.mouritzen.dk/aix-doc/en_US/a_doc_lib/libs/gl32tref/doublebuff_c.htm
// 消除动画闪烁 

/* doublebuff.c:
 *
 * This program demonstrates double buffering.
 * Double buffering is a method for providing smooth,
 * flicker free animation of moving images. This example
 * draws two wireframe" cubes, one inside the other.
 * The cubes are connected to the mouse, and move as the
 * mouse is moved. Notice how the cubes move smoothly as
 * the mouse is moved.
 *
 * Holding down the shift key puts the system into 
 * singlebuffer mode. Notice how the image flickers.
 * This flickering occurs because you are watching the
 * window being cleared and the cube being redrawn.
 * Letting go of the shift key puts the system back into
 * doublebuffer mode. The motion is smooth because all
 * drawing is occurring in the back buffer, which is 
 * invisible. When the drawing is completed, the front
 * and back buffers are * exchanged.
 */
#include <gl/gl.h>
#include <gl/device.h>
#define DOUBLE_BUFFER 1
#define SINGLE_BUFFER 0
int buffer_mode=DOUBLE_BUFFER;         /* DOUBLE_BUFFER=doublebuffer, * 1=singlebuffer */
main()
{
  int x, y;                /*  current position of object */
  Device dev;
  short val;
  long event=0;
  x = 0;
  y = 0;
  initialize();
  while(TRUE) {
    if (qtest())           /*If there are any events in the queue*/
      dev = qread(&val);   /*Read the queue*/
      /*This allows the program always move the cube*/
    switch(dev) {
    case ESCKEY:           /*  exit program with ESC */
      gexit();
      exit(0);
      break;
    case REDRAW:           /* window was exposed. Redraw it. */
      reshapeviewport();
      drawcube(x,y);
      break; 
    case LEFTMOUSE:        /* LEFTMOUSE turns on double buffer*/
      if (buffer_mode == SINGLE_BUFFER){
        buffer_mode = DOUBLE_BUFFER;
        doublebuffer();    /* put system in doublebuffer mode */
        gconfig();
      }
      break;
    case RIGHTMOUSE:       /* RIGHTMOUSE turns on single buffer*/
      if (buffer_mode == DOUBLE_BUFFER) {
        buffer_mode = SINGLE_BUFFER;
        singlebuffer();    /* put system in singlebuffer mode */
        gconfig();
      }
      break;
    }                      /*End of the switch statement*/
    y = getvaluator(MOUSEX); /*read the x,y value of the mouse*/
    x = getvaluator(MOUSEY); /*works outside of the window*/
    drawcube(x,y);
  }
}
initialize()
{
  /* open a window, 500 by 500 pixels */
  prefsize (500,500);
  winopen("doublebuffer"); /* put system into double buffer mode */
  winconstraints();
  doublebuffer();
  gconfig();               /* queue up the shift keys and the mouse */
  qdevice (ESCKEY);
  qdevice (LEFTMOUSE);
  qdevice (RIGHTMOUSE);
  /* use perspective projection */
  perspective (400, 3.0/2.0, 0.001, 100000.0);
  /* look at the origin from a distance of three units */
  translate (0.0, 0.0, -3.0);
  /* draw the first time, so that we don't stare
      * at a blank screen */
  drawcube();
}
drawcube(rotx,roty)
int rotx, roty;
{
  /* clear to background color */
  color(BLACK);
  clear();
  /* set the drawing color */
  color(WHITE);
  pushmatrix();
  /* rotate into the desired viewing position */
  rotate(rotx,'x');
  rotate(roty,'y');
  /* draw the big cube */
  cube();
  /* draw the small cube */
  scale(0.3,0.3,0.3);
  cube();
  popmatrix();
  /* put up a message, instructions */
  cmov2 (-0.4,-1.0);
  charstr ("Left: double buffer |  Right: single buffer");
  /* put up a message, showing buffering mode */
  cmov2 (-0.95, 0.95);
  if (buffer_mode == SINGLE_BUFFER) {
    charstr ("single-buffered, flickering image");
  }
  else {
    charstr ("double-buffered, smoothly animated image");
  }
  /*If it is double buffered, exchange the front and back buffers */
  /*Otherwise if it is single buffered the library ignores*/
  /*this call*/
  swapbuffers();
}
cube()
{
  /* make a cube out of 4 squares */
  pushmatrix();
  side();
  rotate(900,'x');
  side();
  rotate(900,'x');
  side();
  rotate(900,'x');
  side();
  popmatrix();
}
side()
{
  /* make a square translated 0.5 in the z direction */
  pushmatrix();
  translate(0.0,0.0,0.5);
  rect(-0.5,-0.5,0.5,0.5);
  popmatrix();
}
/*Changes:
  - The line once read buffer_mode = ; and now it reads:
        buffer_mode = 1; (Actually now it is SINGLE_BUFFER)
  - The qread and qdevice of MOUSEX and MOUSEY was removed.
    It is too choppy and it cannot read the mouse once the
    pointer's hot spot is outside of the window.  Now it is
    the getvaluator (MOUSE[X|Y]).
  - Put if (qtest) before the qread so the program does
    not stay in the qread command when the mouse's hot
    spot is outside of the window.
  - Added the defines for better programming style
      #define DOUBLE_BUFFER 1
      #define SINGLE_BUFFER 0
  - Made the left and right mouse buttons represent 
      double and single buffer animation respectively
  - Added the button instructions in the window (above) 
  - Added winconstraints so the window can be made larger
*/