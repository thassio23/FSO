#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct ARG{

	int argv;
};


void *conta(void *valor)
{
	 int n;
 	 struct ARG *arg = (struct ARG *)valor;
 	 n = arg->argv;
}

int main(int argc, char *argv[]){

struct ARG args[3];


pthread_t tid[3];
pthread_attr_t attr[3];

for(int i = 0; i<3;i++){

args[i].argv = atoi(argv[1]);
pthread_attr_init(&attr[i]);
pthread_create(&tid[i],&attr[i],conta,&args[i]);

}

for(int i = 0; i<3;i++){

pthread_join(tid[i], NULL);

}

}

