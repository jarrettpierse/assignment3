/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   avg_and_max.c
 * Author: Jarrett Pierse 18375813
 *
 * Created on 30 April 2019, 10:01
 */

#include "avg_and_max.h"

double average(double array[], int size){
    double sum = 0;
    for(int i = 0; i < size - 1; i++){
        sum = sum + array[i];
    }
    return sum/size;
    
}

double max (double array[], int size){
    double max;
    for(int i = 0; i < size ; i++){
        if(max < array[i])
            max = array[i];
    }
    return max;
    
}