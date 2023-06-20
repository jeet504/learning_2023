/*3. Write a program using structures to calculate the difference between two time periods using a user-defined function.*/

#include <stdio.h>

struct Time 
{
    int hours;
    int minutes;
    int seconds;
};


struct Time calculateTimeDifference(struct Time start, struct Time end) 
{
    struct Time diff;

    // Convert all times to seconds
    int startTimeInSeconds = start.hours * 3600 + start.minutes * 60 + start.seconds;
    int endTimeInSeconds = end.hours * 3600 + end.minutes * 60 + end.seconds;

    // Calculate the absolute difference in seconds
    int diffInSeconds = (endTimeInSeconds > startTimeInSeconds) ? (endTimeInSeconds - startTimeInSeconds) : (startTimeInSeconds - endTimeInSeconds);

    // Convert the difference back to hours, minutes, and seconds
    diff.hours = diffInSeconds / 3600;
    diffInSeconds %= 3600;
    diff.minutes = diffInSeconds / 60;
    diff.seconds = diffInSeconds % 60;

    return diff;
}

int main() 
{
    struct Time startTime, endTime, difference;

    printf("Enter the start time:\n");
    printf("Hours: ");
    scanf("%d", &startTime.hours);
    printf("Minutes: ");
    scanf("%d", &startTime.minutes);
    printf("Seconds: ");
    scanf("%d", &startTime.seconds);

    printf("\nEnter the end time:\n");
    printf("Hours: ");
    scanf("%d", &endTime.hours);
    printf("Minutes: ");
    scanf("%d", &endTime.minutes);
    printf("Seconds: ");
    scanf("%d", &endTime.seconds);

    difference = calculateTimeDifference(startTime, endTime);

    printf("\nTime difference: %02d:%02d:%02d\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
