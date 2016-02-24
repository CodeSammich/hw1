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
  else //everything else
    if( x0 > 0 ) {
      if( y0 >= 0 ) {
	if( y0 <= x0 )
	  first_octant( x0, y0, x1, y1, s, c );
	else
	  second_octant( x0, y0, x1, y1, s, c );
      }
      else if( y0 < 0 ) {
	if( y0 <= -1 * x0 )
	  seventh_octant( x0, y0, x1, y1, s, c );
	else
	  eigth_octant( x0, y0, x1, y1, s, c );
      }
    } else {
      if( y0 >= 0 )
	if( y0 <= -1 * x0 )
	  third_octant( x0, y0, x1, y1, s, c );
	else
	  fourth_octant( x0, y0, x1, y1, s, c );
      else
	if( -1 * y0 <= -1 * x0 )
	  fifth_octant( x0, y0, x1, y1, s, c );
	else
	  sixth_octant( x0, y0, x1, y1, s, c ); 
    }
}

void first_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;

  int dx = x1 - x0;
  int dy = y1 - y0;

  int d = 2 * dx - dy;
  while( x <= x1 ) {
    plot( s, c, x, y);
    if( d > 0 ) {
      y += .5;
      d -= 2 * dy;
    }
    x += 1;
    d += dx;
  }
}

void second_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;

  int dx = x1 - x0;
  int dy = y1 - y0;

  int d = 2 * dy - dx;
  while( y <= y1 ) {
    plot( s, c, x, y);
    if( d < 0 ) {
      y += 1;
      d += 2 * dx;
    }
    x += .5;
    d -= dy;
  }
}

void third_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;

  int dx = x1 - x0;
  int dy = y1 - y0;

  int d = 2 * dy + dx;
  while( y <= y1 ) {
    plot( s, c, x, y);
    if( d > 0 ) {
      y -= 1;
      d -= 2 * dx;
    }
    x += .5;
    d -= dy;
  }
}

void fourth_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;

  int dx = x1 - x0; 
  int dy = y1 - y0;

  int d = 2 * dx + dy;
  while( x <= x1 ) {
    plot( s, c, x, y);
    if( d < 0 ) {
      y -= .5;
      d += 2 * dx;
    }
    x += 1;
    d += dx;
  }
}

void fifth_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  first_octant( x0, y0, x1, y1, s, c);
}

void sixth_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  second_octant( x0, y0, x1, y1, s, c);
}

void seventh_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  third_octant( x0, y0, x1, y1, s, c);
}

void eigth_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  fourth_octant( x0, y0, x1, y1, s, c);
}
