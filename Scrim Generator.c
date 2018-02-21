//Created: Kyle Turner
//Date:    5/16/16
//Purpose: To generate random series for HCS Pro & Challenger Leagues using v1 gametypes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generateSeries(char strongHolds[4][100], char slayer[6][100], char flag[3][100]);
void resetIndexArray(int indexArray[]);
void printSeries(char masterArray[13][100]);
void makePerm(int indexArray[], int size);
void permute(int indexArray[], int i, int size, int counter, int random);
void swap(int indexArray[], int i, int j);

int main(int argc, const char * argv[]){
    //declare variables here
    char strongHolds[4][100] = {"StrongHolds Eden", "StrongHolds Empire", "StrongHolds Plaza", "StrongHolds The Rig"};
    char slayer[6][100]      = {"Slayer Coliseum", "Slayer Eden", "Slayer Plaza", "Slayer Regret", "Slayer The Rig", "Slayer Truth"};
    char flag[3][100]        = {"CTF Coliseum", "CTF Fathom", "CTF Truth"};
    
    //format = H S F S H S F S H S F S H
    generateSeries(strongHolds, slayer, flag);
    
    return 0;
}//end int main();

void generateSeries(char strongHolds[4][100], char slayer[6][100], char flag[3][100]){
    int indexArray[6] = {0, 1, 2, 3, 4, 5};
    char masterArray[13][100];
    
    makePerm(indexArray, 4);
    
    strcpy(masterArray[0],  strongHolds[indexArray[0]]);
    strcpy(masterArray[4],  strongHolds[indexArray[1]]);
    strcpy(masterArray[8],  strongHolds[indexArray[2]]);
    strcpy(masterArray[12], strongHolds[indexArray[3]]);
    
    resetIndexArray(indexArray);
    
    makePerm(indexArray, 6);
    
    strcpy(masterArray[1],  slayer[indexArray[0]]);
    strcpy(masterArray[3],  slayer[indexArray[1]]);
    strcpy(masterArray[5],  slayer[indexArray[2]]);
    strcpy(masterArray[7],  slayer[indexArray[3]]);
    strcpy(masterArray[9],  slayer[indexArray[4]]);
    strcpy(masterArray[11], slayer[indexArray[5]]);
    
    resetIndexArray(indexArray);
    
    makePerm(indexArray, 3);
    
    strcpy(masterArray[2],  flag[indexArray[0]]);
    strcpy(masterArray[6],  flag[indexArray[1]]);
    strcpy(masterArray[10], flag[indexArray[2]]);
    
    printSeries(masterArray);
    
}//end void generateSeries();

void makePerm(int indexArray[], int size){
    int i = 0;
    int factorial = 1, random = 0;
    
    for(i = 0; i < size; i++)
        factorial = factorial*(size-i);
    
    srand((unsigned)time(NULL));
    random = rand()%factorial;
    
    permute(indexArray, 0, size, 1, random);

}//end void makePerm();

void permute(int indexArray[], int i, int size, int counter, int random){
    int j = 0;
    
    if(counter == random-1){
        return;
    } else {
    for(j = i; j < size; j++){
            swap(indexArray, i, j);
            permute(indexArray, i+1, size, counter+1, random);
            //swap(indexArray, i , j);
        }//end for loop j
    }//end else
}//end void permute();

void swap(int indexArray[], int i, int j){
    int temp;
    
    temp = indexArray[i];
    indexArray[i] = indexArray[j];
    indexArray[j] = temp;
}//end void swap();

void resetIndexArray(int indexArray[]){
    int i = 0;
    
    for(i = 0; i < 6; i++){
        indexArray[i] = i;
    }//end for loop i
}//end void resetIndexArray

void printSeries(char masterArray[13][100]){
    int i = 0;
    printf("SERIES GENERATED - BEST OF 13\n-----------------------------\n");
    for(i = 0; i < 13; i++){
        printf("%i. %s\n", i+1, masterArray[i]);
    }//end for loop i
}//end void printSeries();