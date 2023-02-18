#include <stdio.h>
#include <stdlib.h>

typedef struct activity {
    char name[20]; // name of the activity
    int start, stop;  // start and stop time of the activity
    int selected;
} activity_ex;



int compare(const void *a, const void *b) //returns the difference between stop time of two activities
{
    (activity_ex) *p = (activity_ex *)a;
    (activity_ex) *q = (activity_ex *)b;
    return (p->stop - q->stop);
}
void MaxActivities(activity_ex *acts, int n){  //receives the pointer to the list of activities and the number of activities
    int *selected = (int *)malloc(sizeof(int)*n);
    int i,stop = 0;

    qsort(*acts, n, sizeof(activity_ex), compare);  //quicksort to sort the activities according to their stop time
    acts[0]->selected = 1; //first activity (according to finish time) is always selected
    stop  = acts[0].stop; //current stop time, is the stop time of the first activity
    for(i=1; i<n; i++){  //iterate through sorted activities
        if(acts[i]->start >= stop){
            acts[i]->selected = 1
            stop = acts[i].stop;
            }
        }
    printf("Following activities are selected:\n");
    printf("%d", acts[0]->name);
    for (i = 1; i < k; i++)
    {
        if (acts[i]->selected == 1){
            printf(" %d", acts[i]->name);
        }
    }
    printf("\n");
    return;
}


