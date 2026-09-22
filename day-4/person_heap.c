#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

// Global or heap pointers
struct person *students = NULL;
int total_students = 0;
int heap_capacity = 0;

void swapPerson(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify based on age
void minHeapifyAge(struct person arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age) {
        smallest = left;
    }
    if (right < n && arr[right].age < arr[smallest].age) {
        smallest = right;
    }

    if (smallest != i) {
        swapPerson(&arr[i], &arr[smallest]);
        minHeapifyAge(arr, n, smallest);
    }
}

// Build Min-heap based on age
void buildMinHeapAge(struct person arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapifyAge(arr, n, i);
    }
}

// Max-heapify based on weight
void maxHeapifyWeight(struct person arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight) {
        largest = left;
    }
    if (right < n && arr[right].weight > arr[largest].weight) {
        largest = right;
    }

    if (largest != i) {
        swapPerson(&arr[i], &arr[largest]);
        maxHeapifyWeight(arr, n, largest);
    }
}

// Build Max-heap based on weight
void buildMaxHeapWeight(struct person arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapifyWeight(arr, n, i);
    }
}

// Display all students in tabular form
void displayStudents(struct person arr[], int n) {
    printf("Id    Name           Age  Height  Weight(pound)\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-14s %-4d %-7d %d\n",
               arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }
}

// Free allocated memory
void freeStudents() {
    if (students != NULL) {
        for (int i = 0; i < total_students; i++) {
            if (students[i].name != NULL) {
                free(students[i].name);
            }
        }
        free(students);
        students = NULL;
    }
    total_students = 0;
    heap_capacity = 0;
}

// Read student records from file
void readData() {
    char filepath[256];
    FILE *fp = NULL;

    // Check default locations first
    const char *default_paths[] = {
        "day-4/input/students.txt",
        "input/students.txt",
        "students.txt",
        "../day-4/input/students.txt",
        "../input/students.txt"
    };
    int num_paths = sizeof(default_paths) / sizeof(default_paths[0]);

    for (int i = 0; i < num_paths; i++) {
        fp = fopen(default_paths[i], "r");
        if (fp != NULL) {
            strcpy(filepath, default_paths[i]);
            break;
        }
    }

    if (fp == NULL) {
        printf("Enter data file path: ");
        if (scanf("%255s", filepath) != 1) return;
        fp = fopen(filepath, "r");
        if (fp == NULL) {
            printf("Error: Cannot open file '%s'\n", filepath);
            return;
        }
    }

    freeStudents();

    int n = 0;
    char line[512];

    // Check if the first line is count 'n'
    if (fgets(line, sizeof(line), fp) != NULL) {
        int count_check;
        if (sscanf(line, "%d", &count_check) == 1 && strchr(line, ' ') == NULL) {
            n = count_check;
        } else {
            // It's already the first student record, rewind
            rewind(fp);
        }
    }

    heap_capacity = (n > 0) ? n + 10 : 20;
    students = (struct person *)malloc(heap_capacity * sizeof(struct person));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
        return;
    }

    total_students = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Trim newline and carriage returns
        line[strcspn(line, "\r\n")] = '\0';
        if (strlen(line) == 0) continue;

        // Ensure dynamic capacity
        if (total_students >= heap_capacity) {
            heap_capacity *= 2;
            students = (struct person *)realloc(students, heap_capacity * sizeof(struct person));
        }

        // Parse: Id Name (can be multiple words) Age Height Weight
        int id, age, height, weight;
        char temp_line[512];
        strcpy(temp_line, line);

        char *tokens[20];
        int tok_count = 0;
        char *tok = strtok(temp_line, " \t");
        while (tok != NULL && tok_count < 20) {
            tokens[tok_count++] = tok;
            tok = strtok(NULL, " \t");
        }

        if (tok_count >= 5) {
            id = atoi(tokens[0]);
            weight = atoi(tokens[tok_count - 1]);
            height = atoi(tokens[tok_count - 2]);
            age = atoi(tokens[tok_count - 3]);

            // Reconstruct name from tokens[1] to tokens[tok_count - 4]
            char name_buf[256] = "";
            for (int k = 1; k <= tok_count - 4; k++) {
                if (k > 1) strcat(name_buf, " ");
                strcat(name_buf, tokens[k]);
            }

            students[total_students].id = id;
            students[total_students].name = (char *)malloc(strlen(name_buf) + 1);
            strcpy(students[total_students].name, name_buf);
            students[total_students].age = age;
            students[total_students].height = height;
            students[total_students].weight = weight;

            total_students++;
        }
    }

    fclose(fp);
    displayStudents(students, total_students);
}

// Display weight of youngest person
void displayWeightOfYoungest() {
    if (total_students == 0) {
        printf("No student records available. Please read data first.\n");
        return;
    }

    // Youngest person is min age. In min-heap on age, it's at index 0.
    // To ensure correctness regardless of current heap state:
    int min_idx = 0;
    for (int i = 1; i < total_students; i++) {
        if (students[i].age < students[min_idx].age) {
            min_idx = i;
        }
    }

    // 1 pound = 0.45359237 kg
    float weight_kg = (float)students[min_idx].weight * 0.45359237f;
    printf("Weight of youngest student: %.2f kg\n", weight_kg);
}

// Insert new person into Min-heap
void insertPersonMinHeap() {
    if (total_students >= heap_capacity) {
        heap_capacity = (heap_capacity == 0) ? 10 : heap_capacity * 2;
        students = (struct person *)realloc(students, heap_capacity * sizeof(struct person));
        if (students == NULL) {
            printf("Memory reallocation failed!\n");
            return;
        }
    }

    int id, age, height, weight;
    char name_buf[256];

    printf("Enter Id: ");
    if (scanf("%d", &id) != 1) return;
    printf("Enter Name: ");
    while (getchar() != '\n'); // clear newline
    if (fgets(name_buf, sizeof(name_buf), stdin) != NULL) {
        name_buf[strcspn(name_buf, "\r\n")] = '\0';
    }
    printf("Enter Age: ");
    if (scanf("%d", &age) != 1) return;
    printf("Enter Height: ");
    if (scanf("%d", &height) != 1) return;
    printf("Enter Weight (pound): ");
    if (scanf("%d", &weight) != 1) return;

    // Add at end
    int curr = total_students;
    students[curr].id = id;
    students[curr].name = (char *)malloc(strlen(name_buf) + 1);
    strcpy(students[curr].name, name_buf);
    students[curr].age = age;
    students[curr].height = height;
    students[curr].weight = weight;
    total_students++;

    // Sift-up in min-heap based on age
    while (curr > 0) {
        int parent = (curr - 1) / 2;
        if (students[curr].age < students[parent].age) {
            swapPerson(&students[curr], &students[parent]);
            curr = parent;
        } else {
            break;
        }
    }

    printf("New person inserted into the Min-heap successfully.\n");
}

// Delete the oldest person
void deleteOldestPerson() {
    if (total_students == 0) {
        printf("Heap is empty! No person to delete.\n");
        return;
    }

    // Find the person with maximum age
    int oldest_idx = 0;
    for (int i = 1; i < total_students; i++) {
        if (students[i].age > students[oldest_idx].age) {
            oldest_idx = i;
        }
    }

    printf("Deleting oldest person: Id %d, %s, Age %d\n",
           students[oldest_idx].id, students[oldest_idx].name, students[oldest_idx].age);

    free(students[oldest_idx].name);

    // Replace with last element
    students[oldest_idx] = students[total_students - 1];
    total_students--;

    // Restore min-heap property based on age
    if (total_students > 0 && oldest_idx < total_students) {
        buildMinHeapAge(students, total_students);
    }

    printf("Oldest person deleted successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n\n");
        printf("Enter option: ");

        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                readData();
                break;
            case 2:
                if (total_students > 0) {
                    buildMinHeapAge(students, total_students);
                    printf("Min-heap based on age created successfully.\n");
                    displayStudents(students, total_students);
                } else {
                    printf("Please read data first (Option 1).\n");
                }
                break;
            case 3:
                if (total_students > 0) {
                    buildMaxHeapWeight(students, total_students);
                    printf("Max-heap based on weight created successfully.\n");
                    displayStudents(students, total_students);
                } else {
                    printf("Please read data first (Option 1).\n");
                }
                break;
            case 4:
                displayWeightOfYoungest();
                break;
            case 5:
                insertPersonMinHeap();
                break;
            case 6:
                deleteOldestPerson();
                break;
            case 7:
                freeStudents();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option! Please enter 1-7.\n");
        }
    }

    freeStudents();
    return 0;
}
