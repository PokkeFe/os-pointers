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

    //TODO Get Assignment Count

    //TODO Get Assignment Scores

    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    std::cout << message;
    int val;
    int prompting = 1;
    while(prompting == 1){
        scanf("%d", &val);
        if(val > min && val < max) {
            prompting = 0;
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
    //TODO: Code to prompt user for a double
    return 0.0;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
}
