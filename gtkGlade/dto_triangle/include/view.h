#ifndef VIEW_H
#define VIEW_H

#include "controller_base.h"
#include "view_base.h"

typedef struct
{
  void *window;
  void *bt_submit;
  void *lb_result;
  void *txt_side_a;
  void *txt_side_b;
  void *txt_side_c;
} VIEW_WIDGETS_T;

typedef struct
{
  VIEW_BASE_T base;
  VIEW_WIDGETS_T *vw;
  CONTROLLER_BASE_T *con;
} VIEW_T;

typedef struct
{
  int argc;
  char **argv;
  CONTROLLER_BASE_T *con;
} VIEW_ARGS_T;

bool view_init(VIEW_T *view);
bool view_open(VIEW_T *view, VIEW_ARGS_T *args);
bool view_close(VIEW_T *view);

#endif /* VIEW_H */
