#include <stdio.h>
#include "serve_thread.h"

/* 関数func：スレッドでやること */
/* 引数arg：スレッド（仕事）を行う上で必要な情報 */
void *serve(void *arg){
  int i=0;
  printf("serve %d\n", i);

  return NULL;
}