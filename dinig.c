// DINING PHILOSOPHER PROBLEM USING THREADS
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (ph_num+4)%N
#define RIGHT (ph_num+1)%N
sem_init mutex;
sem_post S[N];
void * philospher(void *num);
void take_fork(int);
void put_fork(int);
void test(int);
int state[N];
int phil_num[N]={0,1,2,3,4};
int main(){      //main function
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex,0,1);
    for(i=0;i<N;i++)
        sem_init(&S[i],0,0);
    for(i=0;i<N;i++){
        pthread_create(&thread_id[i],NULL,philospher,&phil_num[i]);    printf("Philosopher %d is thinking\n",i+1);
    }
    for(i=0;i<N;i++)
        pthread_join(thread_id[i],NULL);
}
void *philospher(void *num){ 
    while(1){
        int *i = num;
        sleep(1);
            take_fork(*i);
        sleep(0);
            put_fork(*i);
    }
}
void take_fork(int ph_num){
    sem_wait(&mutex);
    state[ph_num] = HUNGRY;
        printf("Philosopher %d is Hungry\n",ph_num+1);
    test(ph_num);       
    sem_post(&mutex);
    sem_wait(&S[ph_num]);
    sleep(1);
}
void test(int ph_num) //check for the availability of forks
{
    if (state[ph_num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        state[ph_num] = EATING;
        sleep(2);
            printf("Philosopher %d takes fork %d and %d\n",ph_num+1,LEFT+1,ph_num+1);
            printf("Philosopher %d is Eating\n",ph_num+1);
        sem_post(&S[ph_num]);
    }
}
void put_fork(int ph_num){
    sem_wait(&mutex);
    state[ph_num] = THINKING;
        printf("Philosopher %d putting fork %d and %d down\n",ph_num+1,LEFT+1,ph_num+1);    //after finished eating , both forks put down
        printf("Philosopher %d is thinking\n",ph_num+1);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

/*OUTPUT
icpbatch1@CSE-TEQIP-019:~/Desktop$ gcc -pthread dining.c
icpbatch1@CSE-TEQIP-019:~/Desktop$ ./a.out

Philosopher 1 is thinking
Philosopher 2 is thinking
Philosopher 3 is thinking
Philosopher 4 is thinking
Philosopher 5 is thinking
Philosopher 1 is Hungry
Philosopher 1 takes fork 5 and 1
Philosopher 1 is Eating
Philosopher 2 is Hungry
Philosopher 3 is Hungry
Philosopher 3 takes fork 2 and 3
Philosopher 3 is Eating
Philosopher 4 is Hungry
Philosopher 5 is Hungry
Philosopher 1 putting fork 5 and 1 down
Philosopher 1 is thinking
Philosopher 5 takes fork 4 and 5
Philosopher 5 is Eating
Philosopher 3 putting fork 2 and 3 down
Philosopher 3 is thinking
Philosopher 2 takes for*/
