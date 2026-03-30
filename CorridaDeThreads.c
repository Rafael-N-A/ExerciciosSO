#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int condicao = 0;

void* contagem(){

  pthread_mutex_lock(&mutex);

  int idT = condicao;
  condicao++;

  while (condicao != 4) {
    pthread_cond_wait(&cond, &mutex);
  }
    pthread_cond_broadcast(&cond

  pthread_mutex_unlock(&mutex);

  int i = 0;
  for(i;i<100;i++){
    printf("Thread %i -> %i\n",idT,i);
  }
  printf("Thread %i VENCEU\n",idT);
}

int     main(void) {
  pthread_t     t1,t2,t3,t4;


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