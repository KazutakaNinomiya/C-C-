#include <stdio.h>
#include <pthread.h>

#include "hello.hpp"
#include "good_morning.hpp"
#include "thread_define.h"
#include "thread_test.h"
#include "rice_cook_thread.h"
#include "egg_cook_thread.h"
#include "serve_thread.h"

int main() {
    good_morning();
    int i;

    /* 結果を格納する配列 */
    int r[NUM] = {0};

    /* スレッドを格納する配列 */
    pthread_t t[NUM_THREAD];

    /* スレッドを実行する上で必要な情報を格納する配列 */
    struct data d[NUM_THREAD];

    /* 1つ目のスレッドを行う上で必要な情報を格納 */
    d[0].start = 0; /* 計算開始する数 */
    d[0].num = NUM / 2; /* 計算を行う回数 */
    d[0].result = r; /* 計算結果を格納するアドレス */

    /* 1つ目のスレッドを作成 */
    pthread_create(&t[0], NULL, func, &d[0]);

    /* 2つ目のスレッドを行う上で必要な情報を格納 */
    d[1].start = NUM / 2; /* 計算開始する数 */
    d[1].num = NUM / 2; /* 計算を行う回数 */
    d[1].result = r; /* 計算結果を格納するアドレス */

    /* 2つ目のスレッドを作成 */
    pthread_create(&t[1], NULL, func, &d[1]);

    /* スレッドの終了を待機 */
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);

    pthread_create(&t[2], NULL, rice_cook, &d[2]);
    pthread_create(&t[3], NULL, egg_cook, &d[3]);
    pthread_create(&t[4], NULL, serve, &d[4]);
    pthread_join(t[2], NULL);
    pthread_join(t[3], NULL);
    pthread_join(t[4], NULL);

    return 0;
}