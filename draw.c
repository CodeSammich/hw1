#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if( x > 0 ) {
    if( y >= 0 ) {
      if( y0 <= x0 )
	first_octant( x0, y0, x1, y1, s, c );
      else
	second_octant( x0, y0, x1, y1, s, c );
    }
    else if( y < 0 ) {
      if( y0 <= -1 * x0 )
	seventh_octant( x0, y0, x1, y1, s, c );
      else
	eigth_octant( x0, y0, x1, y1, s, c );
    }
  } else {
    if( y >= 0 )
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
  
}

void second_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  
}

void third_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  
}

void fourth_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  
}

void fifth_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  
}

void sixth_octant(int x0, int y0, int x1, int y1, screen s, color c) {

}

void seventh_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  
}

void eigth_octant(int x0, int y0, int x1, int y1, screen s, color c) {
  
}
