#include <stdio.h>
#include <stdbool.h>



bool is_sorted(int arr[], int n) {
      
}

int main(void) {
 {

    int numbers[] = {2,3,4,5};
    printf("Test 1\n");
    printf("Expected:Pass\n");
    printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers)/sizeof(int)) ? "Pass" : "Fail");
    printf("\n");
 }

  {

    int numbers[] = {5, 9, 11, 15, 35};
    printf("Test 2\n");
    printf("Expected:Pass\n");
    printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers)/sizeof(int)) ? "Pass" : "Fail");
    printf("\n");
 }

  {

    int numbers[] = {5, 9, 11, 15, 2};
    printf("Test 3\n");
    printf("Expected:Fail\n");
    printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers)/sizeof(int)) ? "Pass" : "Fail");
    printf("\n");
 }

{

    int numbers[] = {15, 11, 3, 2, -1, 0};
    printf("Test 4\n");
    printf("Expected:Fail\n");
    printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers)/sizeof(int)) ? "Pass" : "Fail");
    printf("\n");
 }

 {

    int numbers[] = {15, 11};
    printf("Test 5\n");
    printf("Expected:Pass\n");
    printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers)/sizeof(int)) ? "Pass" : "Fail");
    printf("\n");
 }

  {

    int numbers[] = {11};
    printf("Test 6\n");
    printf("Expected:Pass\n");
    printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers)/sizeof(int)) ? "Pass" : "Fail");
    printf("\n");
 }

   {

    int numbers[] = {};
    printf("Test 7\n");
    printf("Expected:Pass\n");
    printf("Actual  :%s\n", is_sorted(numbers, sizeof(numbers)/sizeof(int)) ? "Pass" : "Fail");
    printf("\n");
 }
}