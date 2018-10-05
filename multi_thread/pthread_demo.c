#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * thread1(void * args);
void * thread2(void * args);

int main(int argc, char* argv[]) {
  pthread_t th1, th2;
  void * status;
  pthread_create(&th1, NULL, thread1, NULL);
  pthread_create(&th2, NULL, thread2, NULL);

  return 0;
}

void * thread1(void * args) {
  printf("Thread 1\n");
  pthread_exit(NULL);
}

void * thread2(void * args) {
  printf("Thread 2\n");
  pthread_exit(NULL);
}
