#include <stdio.h>

#include "foobar.h"

int main() {
  struct velocity v1 = {
      .x = 0.1,
      .y = 0.5,
      .z = 0.7,
  };
  struct foobar f1 = {
      .posx = 10,
      .posy = 20,
      .posz = 30.,
      .vel = v1,
  };

  /* Write file */
  FILE *f = fopen("test.bin", "wb");

  clock_gettime(CLOCK_MONOTONIC, &f1.curr_time);
  fwrite(&f1, sizeof(struct foobar), 1, f);

  f1.posx = 30;
  f1.posy = 40;
  f1.posz = 50;
  clock_gettime(CLOCK_MONOTONIC, &f1.curr_time);
  fwrite(&f1, sizeof(struct foobar), 1, f);

  f1.posx = 60;
  f1.posy = 70;
  f1.posz = 80;
  clock_gettime(CLOCK_MONOTONIC, &f1.curr_time);
  fwrite(&f1, sizeof(struct foobar), 1, f);
}
