//Write your code in this file
#include <stdio.h>
#include <string.h>

char lower_to_upper(char input_character){
    char upper = input_character;
    if (input_character > 90){
        upper = input_character - 32;
    }
    return upper;
}

int main(){
    char names[5][10];
    int averages[5];

    for (int i=0; i<5; i++){
        int grades[13];
    
        scanf("%s %d %d %d %d %d %d %d %d %d %d %d %d %d", names[i], &grades[0], &grades[1], &grades[2], &grades[3], &grades[4], &grades[5], &grades[6], &grades[7], &grades[8], &grades[9], &grades[10], &grades[11], &grades[12]);

        int sum = 0;
        for (int j=0; j<13; j++){
            sum+=grades[j];
        }
        averages[i] = sum / 13;
    }

    char best_index = 0; 
    int highest_grade = 0;
    for (int i=0; i<5; i++){
        if (averages[i] > highest_grade){
            best_index = i;
            highest_grade = averages[i];
        }
    }

    //Print the student with the highest average grade
    char first = lower_to_upper(names[best_index][0]);
    printf("%c%s\n", first, &names[best_index][1]);

    //Calculate the average grade of all students
    int sum = 0;
    for (int i=0; i<5; i++){
        sum += averages[i];
    }

    int total_average = sum / 5;

    //If a student is under the total average, print their name in upper case
    for (int i=0; i<5; i++){
        if (averages[i] < total_average){
            char first = lower_to_upper(names[i][0]);
            printf("%c%s\n", first, &names[i][1]);
        }
    }

    return 0;
}