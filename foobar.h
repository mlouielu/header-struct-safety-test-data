#ifndef FOOBAR__H
#define FOOBAR__H

#include <stdint.h>
#include <time.h>

struct velocity {
  double x;
  double y;
  double z;
};

struct foobar {
  int32_t posx;
  int32_t posy;
  int32_t posz;

  struct velocity vel;

  struct timespec curr_time;
};

#endif /* FOOBAR__H */
