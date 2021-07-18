#ifndef THREADS_DEFINE_H
#define THREADS_DEFINE_H

#define NUM 40
#define NUM_THREAD 5

/* スレッド実行に必要なデータを格納する構造体 */
struct data {
    int start;
    int num;
    int* result;
};

#endif