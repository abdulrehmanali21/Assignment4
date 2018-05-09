#include<stdio.h>
#include<pthread.h>

int sum = 0;              //Global sum variable declaration
int noarr[1000];          //Global number array declaration
pthread_t thread[10];     //Global threads array declaration

void * adder(void* arg);  //Function to be used by threads to add number array

int main()
{
    //Initializing the numbers array
	for(int i=0; i<1000; i++){
		noarr[i] = i+1;
	}
    
	int iarr[10] = {0,100,200,300,400,500,600,700,800,900};
    
    //Creating threads
	for(int i=0; i<10; i++){
		pthread_create(&thread[i],NULL,adder,&iarr[i]);
	}

    //Joining all the threads
	for(int i=0; i<10; i++){
		pthread_join(thread[i], NULL);
	}

	//Displaying sum on console
	printf("The sum is %d\n",sum);

	return 0;
}

void * adder(void* arg)
{
	int si = *((int *)arg);       //Dereferencing Starting index of array
	int li = *((int *)arg) + 100; //Last index to sum
	printf("%d\n",si);
	for(si; si < li; si++)
		sum += noarr[si];         //Adding in global variable.
	
    pthread_exit(0);
}
