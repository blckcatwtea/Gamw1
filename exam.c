#include <stdio.h>

float computeAverage(int scores[], int n);
int findHighest(int scores[], int n);
int findLowest(int scores[], int n);
int countPassed(int scores[], int n, int passing);

int main()
{
    int scores[50];
    int n;
    int passed, failed;
    float average;

    do
    {
        printf("Enter number of students (1-50): ");
        scanf("%d", &n);

        if (n < 1 || n > 50)
        {
            printf("Invalid input! Please enter 1-50.\n");
        }

    } while (n < 1 || n > 50);

    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Score of student %d: ", i + 1);
            scanf("%d", &scores[i]);

            if (scores[i] < 0 || scores[i] > 100)
            {
                printf("Invalid score! Enter 0-100.\n");
            }

        } while (scores[i] < 0 || scores[i] > 100);
    }

    average = computeAverage(scores, n);
    int highest = findHighest(scores, n);
    int lowest = findLowest(scores, n);
    passed = countPassed(scores, n, 75);
    failed = n - passed;

    printf("\n--- CLASS REPORT ---\n");
    printf("Average score: %.2f\n", average);
    printf("Highest score: %d\n", highest);
    printf("Lowest score: %d\n", lowest);
    printf("Passed: %d\n", passed);
    printf("Failed: %d\n", failed);

    return 0;
}

float computeAverage(int scores[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += scores[i];
    }

    return (float)sum / n;
}

int findHighest(int scores[], int n)
{
    int highest = scores[0];

    for (int i = 1; i < n; i++)
    {
        if (scores[i] > highest)
        {
            highest = scores[i];
        }
    }

    return highest;
}

int findLowest(int scores[], int n)
{
    int lowest = scores[0];

    for (int i = 1; i < n; i++)
    {
        if (scores[i] < lowest)
        {
            lowest = scores[i];
        }
    }

    return lowest;
}


int countPassed(int scores[], int n, int passing)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= passing)
        {
            count++;
        }
    }

    return count;
}