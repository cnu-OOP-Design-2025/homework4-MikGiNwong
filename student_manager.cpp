#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students++] = Student(name, id, midterm, final);
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    if(findStudentByID(id) >= 0){
        for(int i = findStudentByID(id); i < num_of_students; i++){
            students[i] = students[i + 1]; 
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    students[findStudentByID(student.getID())] = student;
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for(int i = 0; i < num_of_students; i++){
        if(students[i].getID() == id){
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    int idx = 0, M = 0;
    for(int i = 0; i < num_of_students; i++){
        if(students[i].getRecord().getMidterm() > M){
            idx = students[i].getID();
            M = students[i].getRecord().getMidterm();
        }
    }
    return idx;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    int idx = 0, M = 0;
    for(int i = 0; i < num_of_students; i++){
        if(students[i].getRecord().getFinal() > M){
            idx = students[i].getID();
            M = students[i].getRecord().getFinal();
        }
    }
    return idx;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    int idx = 0, M = 0;
    for(int i = 0; i < num_of_students; i++){
        if(students[i].getRecord().getTotal() > M){
            idx = students[i].getID();
            M = students[i].getRecord().getTotal();
        }
    }
    return idx;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float sum = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        sum += students[i].getRecord().getMidterm();
    }
    return sum / num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float sum = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        sum += students[i].getRecord().getFinal();
    }
    return sum / num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    return getMidtermAverage() + getFinalAverage();
}

