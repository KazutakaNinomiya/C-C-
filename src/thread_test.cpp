#include <stdio.h>
#include "thread_define.h"
#include "thread_test.h"

/* 関数func：スレッドでやること */
/* 引数arg：スレッド（仕事）を行う上で必要な情報 */
void *func(void *arg){
    int i;
    struct data *pd = (struct data *)arg;

    /* argで指定された情報に基づいて処理 */
    for(i = pd->start; i < pd->start + pd->num; i++){
        pd->result[i] = i * i * i * i;
    }

    return NULL;
}