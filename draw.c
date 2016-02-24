#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if( x0 == x1 ) { //verticle line
    for(; y0 < y1; y0++ )
      plot( s, c, x0, y0);
  }
  else if( y0 == y1 ) { //horizontal line
    for(; x0 < x1; x0++ )
      plot( s, c, x0, y0 );
  }
  else {
    //    printf("in\n");
    double m = (y1 - y0) / (x1 - x0);
    if( (m >= 0 && m <= 1) ) 
      first_octant( x0, y0, x1, y1, s, c );
    else if( (m > 1) )
      second_octant( x0, y0, x1, y1, s, c );
    else if( (m < -1 ))
      third_octant( x0, y0, x1, y1, s, c );
    else
      fourth_octant( x0, y0, x1, y1, s, c );
  }
}

void first_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;

  int dx = x1 - x0;
  int dy = y1 - y0;
  
  int d = 2 * dy - dx;
  while( x <= x1 ) {
    plot( s, c, x, y);
    if( d > 0 ) {
      y += 1;
      d -= 2 * dx;
    }
    x += 1;
    d += 2 * dy;
  }
}

void second_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;

  int dx = x1 - x0;
  int dy = y1 - y0;
  
  int d = 2 * dx - dy;
  while( x <= x1 ) {
    plot( s, c, x, y);
    if( d < 0 ) {
      y += 1;
      d -= 2 * dx;
    }
    x += 1;
    d += dy;
  }
}

void third_octant(int x0, int y0, int x1, int y1, screen s, color c) {

}

void fourth_octant(int x0, int y0, int x1, int y1, screen s, color c) {

}

