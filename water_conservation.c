
#include <stdio.h>
#include <string.h>

#define MAX_LOCATIONS 50

// Function prototypes
float calculateTotal(float usage[], int n);
int findHighestUsageIndex(float usage[], int n);
void displayReport(char names[][40], float usage[], int n, float target, float redPercent);

int main() {
    int n, i;
    char locations[MAX_LOCATIONS][40];
    float litres[MAX_LOCATIONS];
    float targetLimit, reductionPercent;

    printf("============================================================\n");
    printf("       SMART WATER CONSERVATION & USAGE TRACKER (SDG 6)     \n");
    printf("============================================================\n");

    // Step 1: Validate total number of locations/records
    do {
        printf("Enter number of locations/buildings to monitor (1 - %d): ", MAX_LOCATIONS);
        scanf("%d", &n);
        if (n <= 0 || n > MAX_LOCATIONS) {
            printf("  [Error] Please enter a valid count between 1 and %d.\n", MAX_LOCATIONS);
        }
    } while (n <= 0 || n > MAX_LOCATIONS);

    // Step 2: Read location names and validate daily water consumption
    for (i = 0; i < n; i++) {
        printf("\nRecord #%d Location Name (single word/underscore): ", i + 1);
        scanf("%s", locations[i]);

        do {
            printf("Enter water consumed at %s (in Litres): ", locations[i]);
            scanf("%f", &litres[i]);
            if (litres[i] < 0) {
                printf("  [Invalid Input] Consumption cannot be negative. Try again.\n");
            }
        } while (litres[i] < 0);
    }

    // Step 3: Read daily target limit and proposed reduction percentage
    do {
        printf("\nEnter daily target water limit for all locations (Litres): ");
        scanf("%f", &targetLimit);
        if (targetLimit < 0) {
            printf("  [Invalid Input] Target limit cannot be negative.\n");
        }
    } while (targetLimit < 0);

    do {
        printf("Enter proposed conservation reduction percentage (0 - 100): ");
        scanf("%f", &reductionPercent);
        if (reductionPercent < 0 || reductionPercent > 100) {
            printf("  [Invalid Input] Percentage must be between 0 and 100.\n");
        }
    } while (reductionPercent < 0 || reductionPercent > 100);

    // Step 4: Generate and print complete analytical output
    displayReport(locations, litres, n, targetLimit, reductionPercent);

    return 0;
}

// Calculates total water consumed across all recorded locations
float calculateTotal(float usage[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += usage[i];
    }
    return sum;
}

// Returns the array index of the location with highest consumption
int findHighestUsageIndex(float usage[], int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (usage[i] > usage[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

// Displays formatted table, target comparison, and estimated savings
void displayReport(char names[][40], float usage[], int n, float target, float redPercent) {
    float total = calculateTotal(usage, n);
    float average = total / n;
    int peakIdx = findHighestUsageIndex(usage, n);
    float estimatedSavings = total * (redPercent / 100.0);
    float projectedUsage = total - estimatedSavings;

    printf("\n============================================================\n");
    printf("                 DAILY WATER CONSUMPTION REPORT             \n");
    printf("============================================================\n");
    printf("%-5s %-25s %18s\n", "S.No", "Location / Block", "Consumption (L)");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-5d %-25s %18.2f\n", i + 1, names[i], usage[i]);
    }

    printf("------------------------------------------------------------\n");
    printf("Total Water Consumed      : %.2f Litres\n", total);
    printf("Average Use per Location  : %.2f Litres\n", average);
    printf("Highest Usage Location    : %s (%.2f Litres)\n", names[peakIdx], usage[peakIdx]);
    printf("------------------------------------------------------------\n");

    // Target comparison
    printf("Daily Target Limit        : %.2f Litres\n", target);
    if (total > target) {
        printf("Target Status             : EXCEEDED by %.2f Litres\n", total - target);
    } else if (total < target) {
        printf("Target Status             : WITHIN TARGET (%.2f Litres below limit)\n", target - total);
    } else {
        printf("Target Status             : EXACTLY ON TARGET\n");
    }

    // Savings estimation
    printf("Proposed Reduction        : %.1f%%\n", redPercent);
    printf("Estimated Water Saved     : %.2f Litres / day\n", estimatedSavings);
    printf("Projected New Total       : %.2f Litres / day\n", projectedUsage);
    printf("============================================================\n");
}
