#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10000

typedef struct PriorityQueue PriorityQueue;

struct PriorityQueue{
    int value;
    int priority;
};

PriorityQueue data[MAX_SIZE];
int size = -1;

void enqueue(int value, int priority){
    size++;

    data[size].value = value;
    data[size].priority = priority;
}

int peek(){ //to know the index of the highest priority elements == lower in time and earliest in deadline
    int heighest_priority = INT_MAX, idx = 0;

    for(int i=0; i<=size; i++){
        if(heighest_priority==data[i].priority && idx>0){ // TO INSERT THE LAST INDEX OF DUPLICATED ELEMENTS
            heighest_priority = data[i].priority;
            idx = i;
        }
        else if(heighest_priority>data[i].priority){
            heighest_priority = data[i].priority;
            idx = i;
        }
    }
    return idx;
}

void dequeue(){
    int idx = peek();
    for(int i=idx; i<size; i++){
        data[i] = data[i+1];
    }
    size--;
}

void get_number_of_courses(int courses){
    int current_day = 0;
    int deadline_day = 0;
    int output = 0;
    for(int i=0; i<courses; i++){
        int idx = peek();
        current_day + = data[idx].value;
        deadline_day = data[idx].priority;
        if(current_day<=deadline_day)
            output++;
        else
            current_day - = data[idx].value;
        dequeue();
    }
    printf("%d", output);
}


int main(){
    int courses = 0;
    scanf("%d", &courses);
    int duration = 0, deadline = 0;
    for(int i=0; i<courses; i++){
        scanf("%d %d", &duration, &deadline);
        enqueue(duration, deadline);
    }

    get_number_of_courses(courses);

    return 0;
}
