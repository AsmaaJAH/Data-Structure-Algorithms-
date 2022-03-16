#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  //for INT_MAX


#define maxSIZE 10000

typedef struct prioQueue prioQueue;
struct prioQueue{
    int val;
    int prio;
};

prioQueue data[maxSIZE];
int realSize=-1;

void enqueue(int val, int prio)//val =duration ////prio==deadline
{
    realSize++;

    data[realSize].val = val;
    data[realSize].prio = prio;
}


int readIndex()
{ //to peek or know the index of the highest priority elements == lower in time and earliest in deadline
    int heighest_pr = INT_MAX;
    int  index = 0;

    for(int i=0; i<=realSize; i++)
       {
                    if(heighest_pr==data[i].prio && index>0)
                    { // TO INSERT THE LAST INDEX OF DUPLICATED ELEMENTS

                        heighest_pr = data[i].prio;
                        index = i;

                    }else if(heighest_pr>data[i].prio)
                    {
                        heighest_pr = data[i].prio;
                        index = i;
                    }
    }
    return index;
}



void dequeue()
{
    int index = readIndex();
    //farward shift
    for(int i=index; i<realSize; i++)
    {
        //instead of deleting overwrite  the comming element above this element u want to delete then shift
        data[i] = data[i+1];
    }
    realSize--;
}

void getMAXCourses(int Ncourses){

    int today = 0;
    int deadline= 0;
    int count = 0;

    for(int i=0; i<Ncourses; i++)
    {
        int index = readIndex();
        today += data[index].val;
        deadline = data[index].prio;

        if(today<=deadline)
            count++;
        else
            today -= data[index].val;

        dequeue();
    }
    printf("%d", count);
}


int main(){
    int Ncourses = 0;
    scanf("%d", &Ncourses);

    int duration = 0, deadline = 0;
    for(int i=0; i<Ncourses; i++)
    {
        scanf("%d %d", &duration, &deadline);
        enqueue(duration, deadline);
    }

    getMAXCourses(Ncourses);

    return 0;
}
