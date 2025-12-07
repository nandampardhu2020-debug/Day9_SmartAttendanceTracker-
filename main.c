#include <stdio.h>
#define TOTAL_DAYS 30.0

int main() {
    int total_students;
    int days_present;
    int eligible_students = 0;
    int not_eligible_students = 0;
    double attendance_percent;
    double sum_of_attendance_percents = 0.0;
    int student_counter;

    // --- 1. Get Total Number of Students ---
    printf("Enter total number of students: ");
    if (scanf("%d", &total_students) != 1 || total_students <= 0) {
        printf("Invalid number of students entered.\n");
        return 1;
    }

    printf("\n--- Individual Student Attendance Report ---\n");

    for (student_counter = 1; student_counter <= total_students; student_counter++) {
        
        // --- Input for the current student ---
        printf("Enter attendance for student %d (out of 30): ", student_counter);
        scanf("%d", &days_present);

        if (days_present < 0 || days_present > 30) {
            printf("Invalid days present. Assuming 0 and continuing.\n");
            days_present = 0;
        }

        // --- Calculation ---
        attendance_percent = (days_present / TOTAL_DAYS) * 100.0;
        
        sum_of_attendance_percents += attendance_percent;

        printf("Student %d: %.2lf%% - ", student_counter, attendance_percent);

        // Check eligibility: Eligible if attendance >= 75%
        if (attendance_percent >= 75.0) {
            printf("Eligible\n");
            eligible_students++; // Increment counter
        } else {
            printf("Not Eligible\n");
            not_eligible_students++; // Increment counter
        }
    }

    // --- 3. Compute Class Summary ---
    double average_attendance = 0.0;
    
    if (total_students > 0) {
        average_attendance = sum_of_attendance_percents / total_students;
    }

    // --- 4. Display Final Summary Report ---
    printf("\n========================================\n");
    printf("Class Summary:\n");
    printf("Total Students: %d\n", total_students);
    printf("Eligible Students: %d\n", eligible_students);
    printf("Not Eligible: %d\n", not_eligible_students);
    printf("Average Attendance: %.2lf%%\n", average_attendance);
    printf("========================================\n");

    return 0;
}
