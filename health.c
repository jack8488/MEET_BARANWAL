

#include <stdio.h>
#include <string.h>

// Structure to hold patient data
typedef struct
{
    char name[50];
    int age;
    char disease[50];
    char treatment[100];
    char prediction[100];
} Patient;

// Function to predict outcome based on disease and age
void predictOutcome(Patient *p)
{
    if (strcmp(p->disease, "Diabetes") == 0)
    {
        if (p->age > 50)
        {
            strcpy(p->prediction, "High Risk, Continuous Monitoring Required");
        }
        else
        {
            strcpy(p->prediction, "Moderate Risk, Manageable with Diet");
        }
        strcpy(p->treatment, "Regular Insulin Shots, Healthy Diet");
    }
    else if (strcmp(p->disease, "Hypertension") == 0)
    {
        if (p->age > 40)
        {
            strcpy(p->prediction, "Risk of Heart Issues, Frequent Checkups Needed");
        }
        else
        {
            strcpy(p->prediction, "Manageable with Medication");
        }
        strcpy(p->treatment, "Blood Pressure Medications, Regular Exercise");
    }
    else
    {
        strcpy(p->prediction, "Consult a Specialist");
        strcpy(p->treatment, "GO TO DOCTOR FOR TREATMENT FOR FEARTHER DETAIL CONTACT +91 943212443");
    }
}

// Function to display patient details and predictions
void displayPatientDetails(Patient p)
{
    printf("\n--- Patient Details ---\n");
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Disease: %s\n", p.disease);
    printf("Treatment Plan: %s\n", p.treatment);
    printf("Predicted Outcome: %s\n", p.prediction);
    printf("-----------------------\n");
}

int main()
{
    int n, i;

    printf("Enter the number of patients: ");
    scanf("%d", &n);
    getchar(); // To consume the newline character left by scanf

    Patient patients[n];

    // Input patient data
    for (i = 0; i < n; i++)
    {
        printf("\n--- Enter Details for Patient %d ---\n", i + 1);

        printf("Name: ");
        fgets(patients[i].name, 50, stdin);
        strtok(patients[i].name, "\n"); // Remove newline character

        printf("Age: ");
        scanf("%d", &patients[i].age);
        getchar(); // Consume newline character

        printf("Disease: ");
        fgets(patients[i].disease, 50, stdin);
        strtok(patients[i].disease, "\n"); // Remove newline character

        // Predict outcome and treatment
        predictOutcome(&patients[i]);
    }

    // Display patient details and predictions
    for (i = 0; i < n; i++)
    {
        displayPatientDetails(patients[i]);
    }

    return 0;
}