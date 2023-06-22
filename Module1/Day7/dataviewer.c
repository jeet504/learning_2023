#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

typedef struct 
{
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

int readLogEntries(LogEntry entries[]) 
{
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int numEntries = 0;
    file = fopen("data.csv", "r");
    if (file == NULL) 
    {
        printf("Unable to open the file.\n");
        return 0;
    }
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file) != NULL) 
    {
        char *token;
        int i = 0;

        token = strtok(line, ",");
        entries[numEntries].entryNo = atoi(token);

        while (token != NULL) 
        {
            token = strtok(NULL, ",");
            switch (i) 
            {
                case 0:
                    strncpy(entries[numEntries].sensorNo, token, sizeof(entries[numEntries].sensorNo));
                    break;
                case 1:
                    entries[numEntries].temperature = atof(token);
                    break;
                case 2:
                    entries[numEntries].humidity = atoi(token);
                    break;
                case 3:
                    entries[numEntries].light = atoi(token);
                    break;
                case 4:
                    strncpy(entries[numEntries].timestamp, token, sizeof(entries[numEntries].timestamp));
                    break;
            }
            i++;
        }

        numEntries++;
    }
    fclose(file);
    return numEntries;
}

void displayLogEntries(LogEntry entries[], int numEntries) 
{
    printf("EntryNo  SensorNo  Temperature  Humidity  Light  Timestamp\n");
    for (int i = 0; i < numEntries; i++) 
    {
        printf("%-8d %-9s %-12.2f %-8d %-6d %s\n", entries[i].entryNo, entries[i].sensorNo,
               entries[i].temperature, entries[i].humidity, entries[i].light, entries[i].timestamp);
    }
}

void sortLogEntries(LogEntry entries[], int numEntries) 
{
    LogEntry temp;
    for (int i = 0; i < numEntries - 1; i++) 
    {
        for (int j = 0; j < numEntries - i - 1; j++) 
        {
            if (entries[j].temperature < entries[j + 1].temperature) 
            {
                temp = entries[j];
                entries[j] = entries[j + 1];
                entries[j + 1] = temp;
            }
        }
    }
}

void updateLogEntry(LogEntry entries[], int numEntries, int entryNo, float newTemperature) 
{
    for (int i = 0; i < numEntries; i++) 
    {
        if (entries[i].entryNo == entryNo)
        {
            entries[i].temperature = newTemperature;
            break;
        }
    }
}

void updateLogFile(LogEntry entries[], int numEntries) 
{
    FILE *file;
    file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    fprintf(file, "EntryNo,sensorNo,Temperature,Humidity,Light,timestamp\n");
    for (int i = 0; i < numEntries; i++) 
    {
        fprintf(file, "%d,%s,%.2f,%d,%d,%s\n", entries[i].entryNo, entries[i].sensorNo,
                entries[i].temperature, entries[i].humidity, entries[i].light, entries[i].timestamp);
    }
    fclose(file);
    printf("Log entry updated successfully.\n");
}

int main() 
{
    LogEntry entries[MAX_ENTRIES];
    int numEntries;
    numEntries = readLogEntries(entries);
    displayLogEntries(entries, numEntries);
    
    sortLogEntries(entries, numEntries);
    printf("\nSorted log entries based on temperature:\n");
    displayLogEntries(entries, numEntries);

    int entryNo = 2;
    float newTemperature = 25.5;
    updateLogEntry(entries, numEntries, entryNo, newTemperature);
    printf("\nAfter updating entry number %d with temperature %.2f:\n", entryNo, newTemperature);
    displayLogEntries(entries, numEntries);

    updateLogFile(entries, numEntries);

    return 0;
}
