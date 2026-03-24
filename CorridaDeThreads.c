#include <stdio.h>
#include <pthread.h>

void* contagem(){
    pthread_t id = pthread_self();
    int i = 0;
    for(i;i<100;i++){
        printf("Thread %lu -> %i\n",id,i);
    }
}

int     main(void) {
  pthread_t     t1;
  pthread_t     t2;
  pthread_t     t3;
  pthread_t     t4;

  pthread_create(&t1, NULL, contagem, NULL);
  pthread_create(&t2, NULL, contagem, NULL);
  pthread_create(&t3, NULL, contagem, NULL);
  pthread_create(&t4, NULL, contagem, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);

  printf("FIM.\n");

  return 0;
}