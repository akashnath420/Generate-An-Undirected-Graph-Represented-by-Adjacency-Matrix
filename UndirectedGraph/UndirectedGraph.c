
                                              //**Probect name**//
                          //Generate An Undirected Graph Represented by Adjacency Matrix//


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int ADJN[7000][7000];

int main(){
    int n;
    clock_t start,stop;
    printf("Enter the Number of Vertices : ");
    scanf("%d",&n);
    srand(time(NULL));
    double time, milisecond = pow(10,3);
    start=clock();

    //Generating random matrix
    for(int i = 0; i < n; i++){
        for(int b = 0; b < n; b++){
            ADJN[i][b] = rand() % 2;
        }
    }

    //Generating undirected graph
    for(int i = 0; i < n; i++){
        for(int b = 0; b < n; b++){
            if(ADJN[i][b] == 1){
                if(i == b)     //ignoring loops
                {
                    ADJN[i][b] = 0;
                }
                else
                    ADJN[b][i] = ADJN[i][b];
            }
            else if(ADJN[i][b] == 0){
                ADJN[b][i] = ADJN[i][b];
            }
        }
    }

    //Printing The ADJNacency matrix
    for(int i = 0; i < n; i++)
    {
        for(int b = 0; b < n; b++)
        {
            printf("%4d ", ADJN[i][b]);
        }
        printf("\n");
    }

    int edge = 0,sum = 0;

    //Calculating Degree and Edges
    for(int i = 0; i < n; i++){
        int deg = 0;
        for(int b = 0; b < n; b++)
        {
            if(ADJN[i][b] == 1)
            {
                deg++;

                if(i>b)
                    edge++;
            }
        }
        sum+=deg;
    }

    stop=clock();

    printf ("\n Total Degree is %d \n",sum);
    printf ("\n Total Edge is %d \n",edge);

    if(edge*2 == sum){
        printf("\n Total Degree/2 = %d/2 = Total edge = %d \n",sum,edge);
        printf("\n So,Handshaking Theorem Is Working\n");
    }
    else
        printf("\n  Handshaking Theorem Is Not Working\n");
    time = ((double)(stop-start)/CLOCKS_PER_SEC*milisecond);
    printf("\n Total Time taken to execute is %lf milisecond\n",time);

    return 0;
}
