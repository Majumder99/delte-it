#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define M 3
#define K 2
#define N 3
#define NUM_THREADS 9

int A [M][K] = { {1,4}, {2,5}, {3,6} };
int B [K][N] = { {8,7,6}, {5,4,3} };
int C [M][N];

struct box {
   int i;
   int j;
};

struct box thread_data[NUM_THREADS];

void *runner(void *param);

int main(int argc, char *argv[]) {

    pthread_t threads[NUM_THREADS];
	int count = 0;

	int i,j,rc;
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {

			if(count > 8)
			{
				count--;
				break;
			}
			thread_data[count].i = i;
			thread_data[count].j = j;

			rc = pthread_create(&threads[count], NULL, runner, (void *)&thread_data[count]);
			printf("Thread %d created\n", count);
			count++;
			if (rc){
       			printf("ERROR; return code from pthread_create() is %d\n", rc);
       		exit(-1);
			}

         	pthread_attr_t attr;
         	pthread_attr_init(&attr);

		}
	}


 	void *status;
	for(i=0; i<count; i++) {
      //rc = pthread_join(threads[i], &status);
      /*if (rc) {
         printf("ERROR; return code from pthread_join() is %d\n", rc);
         exit(-1);
         }*/
     }


    for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
}


void *runner(void *param) {

    struct box *data;
    int k, n, sum = 0;

    data = (struct box *) param;
	int i = data->i;
	int j = data->j;

    for(k=0; k<=1 ; k++) {
   		sum = sum + A[i][k] * B[k][j];
    }

    printf("%d ", sum);
    printf("\n");
	C[i][j] = sum;


    pthread_exit(0);
}
