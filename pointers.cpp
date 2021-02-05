// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    // Sequence of user input -> store in fields of `student`
    
    // ID
    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);
    
    // Name
    student.f_name = new char[128];
    printf("Please enter the student's first name: ");
    scanf("%s", student.f_name);

    student.l_name = new char[128];
    printf("Please enter the student's last name: ");
    scanf("%s", student.l_name);

    //* DEBUGGING
    // printf("Student %d - %s %s\n", student.id, student.f_name, student.l_name);

    // Get Assignment Count
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 0, INT32_MAX);

    // Get Assignment Scores
    student.grades = new double[student.n_assignments];
    for(int assignment_number = 0; assignment_number < student.n_assignments; assignment_number++) {
        std::string message = "Please enter grade for assignment " + std::to_string(assignment_number) + ": ";
        *(student.grades + assignment_number) = promptDouble(message, 0.0, 100.0);
    }

    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage((void*)&student, &average);

    // Output `average`
    printf("Student: %s %s [%d]\n", student.f_name, student.l_name, student.id);
    printf("  Average grade: %.6f\n", average);

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    int val;
    int prompting = 1;
    while(prompting == 1){
        std::cout << message;
        if(scanf("%d", &val) != 1) {
            //error
            printf("Sorry, I cannot understand your answer\n");
            std::cin.ignore(128, '\n');
        } else {
            if(val > min && val < max) {
                prompting = 0;
            } else {
                printf("Sorry, I cannot understand your answer\n");
                std::cin.ignore(128, '\n');
            }
        }
    }
    return val;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    double val;
    int prompting = 1;
    while(prompting == 1) {
        std::cout << message;
        if(scanf("%lf", &val) != 1) {
            //error
            printf("Sorry, I cannot understand your answer\n");
            std::cin.ignore(128, '\n');
        } else {   
            if(val >= min && val <= max) {
                prompting = 0;
            } else {
                printf("Sorry, I cannot understand your answer\n");
                std::cin.ignore(128, '\n');
            }
        }
        
    }
    return val;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    Student* student = (Student*)object;

    // For each assignment, add to sum
    double sum = 0.0;
    for(int grade_ind = 0; grade_ind < student->n_assignments; grade_ind++){
        sum += *(student->grades + grade_ind);
    }

    // Set average to sum / count
    *avg = sum / (double)student->n_assignments;
     
}
