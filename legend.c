#include "map.h"

int main(int argc, char *argv[])
{
  mapObj *map=NULL;
  gdImagePtr img=NULL;

  if( argc < 3 ) {
      fprintf(stdout,"Syntax: legend [mapfile] [output image]\n" );
      exit(0);
  }

  map = msLoadMap(argv[1]);
  if(!map) {
    msWriteError(stderr);
    exit(0);
  }

  img = msDrawLegend(map);
  if(!img) {
    msWriteError(stderr);
    exit(0);
  }

  msSaveImage(img, argv[2], map->legend.transparent, map->legend.interlace);
  gdImageDestroy(img);

  msFreeMap(map);
  
  return(MS_TRUE);
}
