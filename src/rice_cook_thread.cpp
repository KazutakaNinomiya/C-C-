#include <stdio.h>
#include "rice_cook_thread.h"

/* 関数func：スレッドでやること */
/* 引数arg：スレッド（仕事）を行う上で必要な情報 */
void *rice_cook(void *arg){
  int i = 0;
  printf("rice %d\n", i);

  return NULL;
}