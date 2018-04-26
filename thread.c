include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void *funcao(void *parametro){

int l;
l = atoi(parametro);

}


void main(int argc[], char *argv[]){


	pthread_t threads;

	pthread_attr_t attr;

	pthread_create(&threads,&attr,funcao,argv[1]);	

	pthread_join(threads, NULL);

}
