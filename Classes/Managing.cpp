#define CLASSES_FILE "../Data/classes.csv"
#define COURSE_UNITS "../Data/classes_per_uc.csv"
#define STUDENTS_FILE "../Data/students_classes.csv"
#define REQUESTS_FILE "../Data/requests.csv"
#define REJECTED_FILE "../Data/rejected_requests.csv"
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Managing.h"
#include "Student.h"

Managing::Managing() {

}

void Managing::readFiles() {
    readStudents();
    readSchedules();
    readCourseUnits();
    readRequests();
    readRejectedRequests();
}

void Managing::readStudents() {
    // Reads the file about the students
    set<Student *, studComp> _students = {};
    ifstream file(STUDENTS_FILE);

    list<Turma> studentclasses;

    if (file.is_open()) {
        file.ignore(49, '\n');
        while (!file.eof()) {

            string studentCode;
            string name;
            string classCode;
            string ucCode;

            getline(file, studentCode, ',');
            if (studentCode.empty()) break;
            getline(file, name, ',');
            getline(file, ucCode, ',');
            getline(file, classCode);
            classCode.erase(classCode.size() - 1); // remove carriage return symbol \r

            auto it = _students.find(new Student(stoi(studentCode)));

            Turma _class = Turma(classCode, ucCode);

            if (it != _students.end()) {
                (*it)->addClass(_class);
            }
            else {
                studentclasses.clear();
                studentclasses.push_back(_class);
                _students.insert(new Student(stoi(studentCode), name, studentclasses));
            }

        }
        file.close();
        studentclasses.clear();
        this->students = _students;
    }
}

void Managing::readSchedules() {
    // Reads the file about the students
    set<Schedule*, schedComp> _schedules = {};

    ifstream file(CLASSES_FILE);

    list<Slot> slots;

    if (file.is_open()) {
        file.ignore(100, '\n');
        while (!file.eof()) {

            string classCode;
            string ucCode;
            string weekday;
            string startHour;
            string duration;
            string type;

            getline(file, classCode, ',');
            if (classCode.empty()) break;
            getline(file, ucCode, ',');
            getline(file, weekday, ',');
            getline(file, startHour, ',');
            getline(file, duration, ',');
            getline(file, type);
            type.erase(type.size() - 1); // remove carriage return symbol \r

            Turma _class(classCode, ucCode);
            Slot slot(_class, type, weekday, stof(startHour), stof(duration));
            auto it = _schedules.find(new Schedule(_class));

            if (it != _schedules.end()) {
                (*it)->addSlot(slot);
            }

            else {
                slots.clear();
                slots.push_back(slot);
                _schedules.insert(new Schedule(_class, slots));
            }

        }
        file.close();
        slots.clear();
        this->schedules = _schedules;
    }
}

void Managing::readCourseUnits() {
    set<CourseUnit> _ucs;
    CourseUnit lastCourseUnit;
    ifstream file(COURSE_UNITS);
    if (file.is_open()) {
        file.ignore(20, '\n');
        while (!file.eof()) {

            string ucCode;
            string classCode;


            getline(file, ucCode, ',');
            if (ucCode.empty()) {
                _ucs.insert(lastCourseUnit);
                break;
            }
            getline(file, classCode);
            classCode.erase(classCode.size() - 1); // remove carriage return symbol \r

            Turma _class = Turma(classCode, ucCode);
            this->classes.insert(_class);

            if (lastCourseUnit.getUcCode() != ucCode) {
                if (lastCourseUnit.getUcCode() != "-") {
                    _ucs.insert(lastCourseUnit);
                    lastCourseUnit = CourseUnit(ucCode);
                    lastCourseUnit.insertClass(classCode);
                }
                else {
                    lastCourseUnit = CourseUnit(ucCode);
                    lastCourseUnit.insertClass(classCode);
                    continue;
                }
            }
            else {
                lastCourseUnit.insertClass(classCode);
                continue;
            }
        }
        file.close();
        this->ucs = _ucs;
    }
}

void Managing::readRequests() {
    queue<Request*> _requests;

    ifstream file(REQUESTS_FILE);

    if(file.is_open()) {
        while(!file.eof()) {
            string line;
            string classes_line;

            string studentCode1;
            string studentCode2;
            string name;
            string type;
            string ucCode;
            string classCode;
            vector<Turma> new_classes;

            while (getline(file,line)) {
                istringstream iss(line);

                getline(iss, studentCode1, ',');
                getline(iss, studentCode2, ',');
                getline(iss, name, ',');
                getline(iss, type, ',');
                getline(iss, classes_line);

                int pos = 0;
                string delimiter = ",";


                while((pos = classes_line.find(delimiter)) != string::npos) {
                    ucCode = classes_line.substr(0, pos);
                    classes_line.erase(0, pos + delimiter.length());
                    pos = classes_line.find(delimiter);
                    classCode = classes_line.substr(0, pos);
                    classes_line.erase(0, pos + delimiter.length());
                    new_classes.push_back(Turma(classCode, ucCode));
                }

                if (!name.empty()) {
                    _requests.push(new Request(stoi(studentCode1), name, new_classes, type ));
                    new_classes.clear();
                    continue;
                }

                if (studentCode2.empty()) {
                    _requests.push(new Request(stoi(studentCode1), new_classes, type ));
                    new_classes.clear();
                    continue;
                }

                _requests.push(new Request(stoi(studentCode1), stoi(studentCode2), new_classes, type ));
                new_classes.clear();
            }
            file.close();
            this->requests = _requests;
        }



    }
    file.close();
    this->requests = _requests;

}

void Managing::readRejectedRequests() {
    vector<Request *> _requests;

    ifstream file(REJECTED_FILE);

    if (file.is_open()) {
        while (!file.eof()) {
            string line;
            string classes_line;

            string studentCode1;
            string studentCode2;
            string name;
            string type;
            string ucCode;
            string classCode;
            vector<Turma> new_classes;

            while (getline(file, line)) {
                istringstream iss(line);

                getline(iss, studentCode1, ',');
                getline(iss, studentCode2, ',');
                getline(iss, name, ',');
                getline(iss, type, ',');
                getline(iss, classes_line);

                int pos = 0;
                string delimiter = ",";


                while ((pos = classes_line.find(delimiter)) != string::npos) {
                    ucCode = classes_line.substr(0, pos);
                    classes_line.erase(0, pos + delimiter.length());
                    pos = classes_line.find(delimiter);
                    classCode = classes_line.substr(0, pos);
                    classes_line.erase(0, pos + delimiter.length());
                    new_classes.push_back(Turma(classCode, ucCode));
                }

                if (!name.empty()) {
                    _requests.push_back(new Request(stoi(studentCode1), name, new_classes, type));
                    new_classes.clear();
                    continue;
                }

                if (studentCode2.empty()) {
                    _requests.push_back(new Request(stoi(studentCode1), new_classes, type));
                    new_classes.clear();
                    continue;
                }

                _requests.push_back(new Request(stoi(studentCode1), stoi(studentCode2), new_classes, type));
                new_classes.clear();
            }
            file.close();
            this->rejected_requests = _requests;
        }

    }
}
const set<Student*, studComp> &Managing::getStudents() const {
    return students;
}

void Managing::setStudents(const set<Student*, studComp> &students) {
    Managing::students = students;
}

void Managing::addStudent(const Student* student) {
    students.insert(new Student(*student));

}

const set<Schedule*, schedComp> &Managing::getSchedules() const {
    return schedules;
}

void Managing::setSchedules(const set<Schedule*, schedComp> &schedules) {
    Managing::schedules = schedules;
}

const queue<Request*> &Managing::getRequests() const {
    return requests;
}

void Managing::setRequests(const queue<Request*> &requests) {
    Managing::requests = requests;
}

void Managing::setUcs(const set<CourseUnit> &ucs) {
    Managing::ucs = ucs;
}


set<CourseUnit> Managing::getUcs(char year) {
    if (year == '0') {
        return ucs;
    }
    set<CourseUnit> filtered_ucs;
    
    for (auto uc : this->ucs) {
        if ((*uc.getClasses().begin())[0] == year) {
            filtered_ucs.insert(uc);
        }
    }
    return filtered_ucs;
}

set<Turma> Managing::getClassesByYear(char year) {
    set<Turma> filtered_classes;

    for (Turma turma : this->classes) {
        if (turma.getClassCode()[0] == year) {
            filtered_classes.insert(turma);
        }
    }
    return filtered_classes;
}

void Managing::eraseStudent(Student *s) {
    students.erase(s);
}

const set<Turma> &Managing::getClasses() const {
    return classes;
}

void Managing::setClasses(const set<Turma> &classes) {
    Managing::classes = classes;
}

set<Student*, studentByName> Managing::sortStudentsByName(const set<Student *> s) {
    set<Student*, studentByName> sortedByName;
    for (Student* student : s) {
        sortedByName.insert(student);
    }
    return sortedByName;
}

bool Managing::addRequest(Request* request) {
    requests.push(request);
    writeRequests();
}

Schedule Managing::getStudentSchedule(Student *student) {
    Schedule studentSchedule = Schedule();
    for(Turma _class : student->getClasses()){
        auto mySchedule = schedules.find(new Schedule(_class));
        if(mySchedule != schedules.end()){
            for(Slot slot : (*mySchedule)->getSlots()){
                studentSchedule.addSlot(slot);
            }
        }
    }
    return studentSchedule;
}

vector<pair<int, Turma>> Managing::getOcupacaoTurmas() {
    vector<pair<int,Turma>> numberOfStudentsByClass;
    for (Turma turma : classes){
        int count = 0;
        for(Student* student : students){
            for(Turma turmaStud : student->getClasses()){
                if (turma == turmaStud){
                    count++;
                }
            }
        }
        pair<int,Turma> tempPair(count,turma);
        numberOfStudentsByClass.push_back(tempPair);
    }
    return numberOfStudentsByClass;
}

vector<pair<int, CourseUnit>> Managing::getOcupacaoUCS() {
    vector<pair<int,CourseUnit>> numberOfStudentsByUc;

    for(CourseUnit uc : ucs) { //para cada uc
        int count = 0;
        for (string turma: uc.getClasses()) { //para cada turma da uc
            for (Student *student: students) { // em cada estudante
                for (Turma turmaStud: student->getClasses()) { //em cada turma do estudante
                    if (turma == turmaStud.getClassCode() &&
                        uc.getUcCode() == turmaStud.getUcCode()) { //se a turma for igual, conta++
                        count++;
                    }
                }
            }
        }
        pair<int, CourseUnit> tempPair(count, uc);
        numberOfStudentsByUc.push_back(tempPair);
    }
    return numberOfStudentsByUc;
}

vector<pair<int,string>> Managing::getOcupacaoYear(){
    vector<pair<int,string>> numberOfStudentsByYear;
    int count1 = 0, count2 = 0, count3 = 0;
    for(Student* student : students){
        if(student->getYear() == 1){
            count1++;
        }
        else if(student->getYear() == 2) {
            count2++;
        }
        else{
            count3++;
        }
    }
    pair<int, string> pair1(count1, "1º Ano");
    numberOfStudentsByYear.push_back(pair1);
    pair<int, string> pair2(count2, "2º Ano");
    numberOfStudentsByYear.push_back(pair2);
    pair<int, string> pair3(count3, "3º Ano");
    numberOfStudentsByYear.push_back(pair3);

    return numberOfStudentsByYear;
}

void Managing::processRequests() {
    while (!requests.empty()) {
        Request* request = requests.front();
        string type = request->getType();
        vector<Turma> turmas = request->getNewClasses();
        auto it = turmas.begin();
        if (type == "Inscricao") {
            if (!request->getStudentName().empty()) {
                addStudent(new Student(request->getStudentCode1(), request->getStudentName()));
            }

            while (it != turmas.end()) {
                bool balance = checkBalancing(CourseUnit((*it).getUcCode()));
                bool space = checkSpaceAvailable((*it));
                auto schedule = schedules.find(new Schedule((*it)));
                bool overlap = checkScheduleOverlap(*students.find(new Student(request->getStudentCode1())),(*schedule));

                if (balance && space && !overlap) {
                    auto student = students.find(new Student(request->getStudentCode1()));
                    (*student)->addClass((*it));
                    it = turmas.erase(it);

                } else {
                    it++;
                }
            }

            if (turmas.empty()) {
                requests.pop();
            } else {
                requests.pop();
                request->setNewClasses(turmas);
                rejected_requests.push_back(request);
            }

        }

        else if (type == "Troca Singular") {
            while (it != turmas.end()) {
                auto student_changing = students.find(new Student(request->getStudentCode1()));
                bool balance = checkBalancing(CourseUnit((*it).getUcCode()));
                bool space = checkSpaceAvailable((*it));
                auto schedule = schedules.find(new Schedule((*it)));
                bool overlap = checkScheduleOverlap((*student_changing),(*schedule));


                if (balance && space && !overlap) {
                    auto student = students.find(new Student(request->getStudentCode1()));
                    (*student)->addClass((*it));

                    //remove previous class
                    for (Turma t : (*student_changing)->getClasses()) {
                        if (t.getUcCode() == (*it).getUcCode()) {
                            (*student_changing)->removeClass(t);
                            break;
                        }
                    }
                    it = turmas.erase(it);

                } else {
                    it++;
                }
            }
            if (turmas.empty()) {
                requests.pop();
            } else {
                requests.pop();
                request->setNewClasses(turmas);
                rejected_requests.push_back(request);
            }

        }

        else if (type == "Troca Dupla") {
            while (it != turmas.end()) {
                auto student_changing1 = students.find(new Student(request->getStudentCode1()));
                auto student_changing2 = students.find(new Student(request->getStudentCode2()));

                Turma turma_2; // turma that student2 will have after changing (from student1)

                for (Turma c : (*student_changing1)->getClasses()) {
                    if (c.getUcCode() == turmas[0].getUcCode()) {
                        turma_2 = c;
                        break;
                    }
                }

                // no need to check balancing because number of students will still be the same, neither space
                auto schedule1 = schedules.find(new Schedule((*it)));
                auto schedule2 = schedules.find(new Schedule(turma_2));
                bool overlap = checkScheduleOverlap((*student_changing1),(*schedule1)) && checkScheduleOverlap((*student_changing2), (*schedule2));

                bool possible_change = false;

                if (!overlap) {

                    (*student_changing1)->addClass((*it));
                    (*student_changing2)->addClass(turma_2);

                    //remove previous classes from each of the students
                    (*student_changing1)->removeClass(turma_2);
                    (*student_changing2)->removeClass(*it);

                    it = turmas.erase(it);

                } else {
                    it++;
                }
            }
            if (turmas.empty()) {
                requests.pop();
            }
            else {
                requests.pop();
                request->setNewClasses(turmas);
                rejected_requests.push_back(request);
            }
        }
    }
}

bool Managing::checkBalancing(CourseUnit courseUnit) {
    /*

     Esta funçao pega no vetor que tem a ocupaçao de todas as turmas
     adiciona por ordem de ocupaçao a um vetor, todas as turmas da UC em questao
     a diferença entre o primeiro e o ultimo é a diferença maxima. se não provocar desequilibrio, então não há desequilibrio

     */
    vector<pair<int,Turma>> turmas_ocupacao = getOcupacaoTurmas();
    sort(turmas_ocupacao.begin(), turmas_ocupacao.end());
    vector<pair<int,Turma>> turmas;

    for (auto pair : turmas_ocupacao) {
        if (pair.second.getUcCode() == courseUnit.getUcCode())
            turmas.push_back(pair);
    }

    if (turmas.front().first - turmas.back().first >= 4)
        return false;

    return true;
}

bool Managing::checkSpaceAvailable(Turma turma) {
    vector<pair<int,Turma>> turmas_ocupacao = getOcupacaoTurmas();

    for (auto pair : turmas_ocupacao) {
        if (pair.second == turma) {
            if (pair.first + 1 >= 30)
                return false;
            else
                return true;
        }
    }

    return false;
}

bool Managing::checkScheduleOverlap(Student *student, Schedule* turma) {
    Schedule studentSchedule = getStudentSchedule(student);

    for (Slot slot : turma->getSlots()) {
        if (slot.getType() != "T") {
            for (Slot slot_student: studentSchedule.getSlots()) {
                if (!(slot_student.getTurma().getUcCode() == turma->getClass().getUcCode())) {
                    if (slot.getWeekday() == slot_student.getWeekday()) {
                        if (slot.getStartHour() <= slot_student.getStartHour() &&
                            slot.getStartHour() + slot.getDuration() > slot_student.getStartHour()) {
                            return true; // há sobreposiçao
                        }
                        if (slot.getStartHour() < slot_student.getStartHour() + slot_student.getDuration()
                            && slot.getStartHour() + slot.getDuration() >=
                               slot_student.getStartHour() + slot_student.getDuration()) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
}

const vector<Request *> &Managing::getRejectedRequests() const {
    return rejected_requests;
}

void Managing::setRejectedRequests(const vector<Request *> &rejectedRequests) {
    rejected_requests = rejectedRequests;
}

void Managing::writeStudents() {
    ofstream file(STUDENTS_FILE);
    file << "StudentCode,StudentName,UcCode,ClassCode" << endl;
    //inserting multiple lines
    for (Student* s : students) {
        for (Turma turma : s->getClasses())
            file << s->getCode() << "," << s->getName() << "," << turma.getUcCode() << "," << turma.getClassCode() << "\r" << endl;
    }
    file.close();

}

void Managing::writeRequests() {
    ofstream file(REQUESTS_FILE);
    //inserting multiple lines
    queue<Request*> aux_queue = requests;
    while(!aux_queue.empty()) {
        Request* request = aux_queue.front();
        file << request->getStudentCode1() << "," << request->getStudentCode2()
        << "," << request->getStudentName() << "," << request->getType();

        for (auto t : request->getNewClasses()) {
            file << "," << t.getUcCode() << "," << t.getClassCode();
        }
        file << endl;
        aux_queue.pop();
    }
    file.close();
}

void Managing::writeRejectedRequests() {
    ofstream file(REJECTED_FILE);
    //inserting multiple lines
    vector<Request*> aux_queue = rejected_requests;
    for (Request* request : aux_queue) {
        file << request->getStudentCode1() << "," << request->getStudentCode2()
             << "," << request->getStudentName() << "," << request->getType();

        for (auto t : request->getNewClasses()) {
            file << "," << t.getUcCode() << "," << t.getClassCode();
        }
        file << endl;
    }
    file.close();
}






