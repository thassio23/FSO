#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int o = 0;
struct ARG{
	
	int variavel;	

};

pthread_mutex_t lock;


void *funcao(void *parametro){
	
	int  l;
	struct ARG *arg = (struct ARG *)parametro;

	l = arg->variavel;

	pthread_mutex_lock(&lock);
	for(int i = 0; i<l; i++){

	o++;

	}
	pthread_mutex_unlock(&lock);

	pthread_exit(0);


}

void main(int argc[], char *argv[]){
	
	
	
	
	pthread_mutex_init(&lock, NULL);

	pthread_t nomet[5];

	pthread_attr_t attr[5];

	struct ARG recebe[5];

	for(int i = 0; i<5; i++){

	recebe[i].variavel = atoi(argv[1]);

	pthread_attr_init(&attr[i]);

	pthread_create(&nomet[i],&attr[i],funcao,&recebe[i]);
	}

	for(int i = 0; i<5; i++){

	pthread_join(nomet[i], NULL);
}
	printf("%d", o);
}
