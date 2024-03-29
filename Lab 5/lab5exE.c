// lab5exE.c
// ENSF 337- Fall 2018, Exercise E

#include "lab5exE.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    Point struct_array[10];
    int i;
    int position;

    populate_struct_array(struct_array, 10);

    printf("\nArray of Points contains: \n");

    for(i=0; i < 10; i++)
        display_struct_point(struct_array[i], i);


    printf("\nTest the search function");

    position = search(struct_array, "v0", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "v0");

    position = search(struct_array, "E1", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "E1");

    position = search(struct_array, "C5", 10);

    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "C5");

    position = search(struct_array, "B7", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "B7");
    position = search(struct_array, "A9", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "A9");
    position = search(struct_array, "E11", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "E11");

    position = search(struct_array, "M1", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "M1");

    printf("\n\nTesting the reverse function:");

    reverse(struct_array, 10);

    printf("\nThe reversed array is:");

    for(i=0; i < 10; i++)
        display_struct_point(struct_array[i], i);

    return 0;
}


void display_struct_point(const Point x , int i)
{
    printf("\nstruct_array[%d]: %s <%.2lf, %.2lf, %.2lf>\n",
           i, x.label, x.x, x.y, x.z);
}

void populate_struct_array(Point* array, int n)
{
    int i;
    char ch1 = 'A';
    char ch2 = '9';
    char ch3 = 'z';

    for( i = 0; i < 10; i++)
    {
        /* generating some random values to fill them elements of the array: */
        array[i].x = (7 * (i + 1) % 11) * 100 - i/2;
        array[i].y = (7 * (i + 1) % 11) * 120 - i/3;
        array[i].z = (7 * (i + 1) % 11) * 150 - i/4;

        if(i % 2 == 0)
            array[i].label[0] = ch1++;
        else
            array[i].label[0] = ch3--;
        array[i].label[1] = ch2--;
        array[i].label[2] = '\0';
    }
}

int search(const Point* struct_array, const char* label, int n)
{
    // Students should complete the definiton of this function
    // NOTE: YOU ARE NOT ALLOWED TO USE LIBRARY FUNCTION strcmp IN THIS FUNCTION

    for (int i = 0; i<n; i++){
      int m = 0;
      int len = strlen(label);
      for (int j = 0; j<len ; j++){
        if(struct_array[i].label[j] == label[j]){
          m++;
        }
      }
      if (m == len){
        return i;
      }
    }
    return -1;
}

void reverse (Point *a, int n) // struct array[10], 10
{
    // Students should complete the definiton of this function

    Point b[n];
    for (int i = 0; i<n/2; ++i){
      b[i] = a[n-i-1]; //b0 = a9 v0
      a[n-i-1] = a[i]; //a9 = a0 a9
      a[i] = b[i];     //a0 = b0 v0
    }
}
