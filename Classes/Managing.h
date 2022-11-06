#pragma once

#include <set>
#include <queue>
#include "Student.h"
#include "Request.h"
#include "Schedule.h"
#include "CourseUnit.h"
#include "Turma.h"
#include "Comparators.cpp"

class Managing {
public:
    Managing();

    /**
     * @brief
     * Lê todos os ficheiros TODO: quais?
     */
    void readFiles();

    const set<Student *, studComp> &getStudents() const;

    /**
     * O(n² - chama outra função O(n) dentro do loop O(n) TODO: concluir
     * @brief
     * @param year
     * @return set de pointers de estudantes de um dado ano ordenados por UP
     */
    set<Student *, studComp> getStudentsByYear(char year);

    void setStudents(const set<Student *, studComp> &students);

    /**
     * O(n log(n))
     * @brief
     * Adiciona um pointer estudante ao set de pointers de estudantes.
     * @param student
     */
    void addStudent(const Student *student);

    const set<Schedule *, schedComp> &getSchedules() const;

    void setSchedules(const set<Schedule *, schedComp> &schedules);

    const queue<Request *> &getRequests() const;

    void setRequests(const queue<Request *> &requests);

    /**
     * O(n).
     * @param year
     * @return set de unidades curriculares de um determinado ano (ou todas se não for especificado parâmetro)
     */
    set<CourseUnit> getUcs(char year = '0');

    void setUcs(const set<CourseUnit> &ucs);

    /**
     * @brief
     * Elimina um estudante do set de pointers de estudantes
     * @param s um pointer de um estudante
     */
    void eraseStudent(Student *s);

    const set<Turma> &getClasses() const;

    void setClasses(const set<Turma> &classes);

    /**
     * O(n)
     * @param year
     * @return set de Turmas (turma de uma UC) de um determinado ano
     */
    set<Turma> getClassesByYear(char &year);

    /**
     * O(n²)
     * @param student pointer de um estudante
     * @return horário de um estudante
     */
    Schedule getStudentSchedule(Student *student);


    /**
     * O(1) se não receber argumento.
     * @param _classes
     * @return vector de pares, número de alunos & turma
     */
    vector<pair<int, Turma>> getOcupacaoTurmas(set<Turma> _classes = {});

    /**
     * O(1) se não receber argumento.
     * @param UCs
     * @return vector de pares, número de alunos & UC
     */
    vector<pair<int, CourseUnit>> getOcupacaoUCS(set<CourseUnit> UCs = {});

    /**
     * O(n²) [chama outra função dentro do loop, O(n)]
     * @return vector de pares, número de alunos & ano (1º ano, 2º ano, etc)
     */
    vector<pair<int, string>> getOcupacaoYear();

    /**
     * @brief
     * Adiciona um pedido à fila de pedidos. O(1).
     * @param request
     */
    void addRequest(Request *request);

    /**
     * O(n log(n))
     * @param s set de pointers de estudantes ordenados por UPcode
     * @return set de pointers de estudantes ordenados alfabeticamente
     */
    set<Student *, studentByName> sortStudentsByName(set<Student *, studComp> s);

    /**
     * O(n log(n))
     * @param s set de pointers de estudantes ordenados por UPcode
     * @return multiset de pointers de estudantes ordenados por número de UCs
     */
    multiset<Student *, studentByNUCS> sortStudentsByNUCS(set<Student *, studComp> s);

    /**
     * @brief
     * Processa todos os pedidos em espera
     */
    void processRequests();

    /**
     * @brief
     * Se já existia desiquilibrio inicial, só permite inscrição se for numa turma que não provoque mais desequilibrio. O(n).
     * @param courseUnit
     * @return verdadeiro se houver equilíbrio entre as turmas da UC (se a diferença entre quaisquer duas turmas for >= 4), else 0.
     */
    bool checkBalancing(const Turma &turma);

    /**
     * O(n)
     * @param turma
     * @return 1 se com a inscrição do aluno, o número de alunos for superior a 30 (CAP estipulado), else 0.
     */
    bool checkSpaceAvailable(Turma &turma);

    /**
     * O(n²)
     * @param student pointer de estudante
     * @param turma pointer de um schedule de uma turma
     * @return 1 se existir sobreposição de horários com a inscrição na nova turma, else 0.
     */
    bool checkScheduleOverlap(Student *student, Schedule *turma);

    const vector<Request *> &getRejectedRequests() const;

    void setRejectedRequests(const vector<Request *> &rejectedRequests);

    /**
     *brief
     * Atualiza o ficheiro dos students
     */
    void writeStudents();

    /**
     * @brief
     * Atualiza o ficheiro dos pedidos pendentes
     */
    void writeRequests();

    /**
     * @brief
     * Atualiza o ficheiro dos pedidos rejeitados
     */
    void writeRejectedRequests();

    /**
     *
     * @param uc unidade curricular
     * @return set de turmas dessa unidade curricular
     */
    set<Turma> getClassesByUc(string &uc);

    void emptyRejectedRequests();

private:
    set<Student *, studComp> students;
    set<Schedule *, schedComp> schedules;
    queue<Request *> requests;
    vector<Request *> rejected_requests;
    set<CourseUnit> ucs;
    set<Turma> classes;

    /**
     * O(n log(n))
     * @brief
     * Lê o ficheiro dos estudantes
     */
    void readStudents();

    /**
     * O(n log(n))
     * @brief
     * Lê o ficheiro dos horários
     */
    void readSchedules();

    /**
     * O(n log(n))
     * @brief
     * Lê o ficheiro das UCs/Turmas
     */
    void readCourseUnits();

    /**
     * O(n²) - dependente das linhas do ficheiro (n) e, em cada linha, do número de novas turmas (o parser tem complexidade temporal O(n), sendo n o número de novas turmas no pedido)
     * @brief
     * Lê o ficheiro dos pedidos
     */
    void readRequests();

    /**
     * O(n²) - dependente das linhas do ficheiro (n) e, em cada linha, do número de novas turmas (o parser tem complexidade temporal O(n), sendo n o número de turmas cuja inscrição foi rejeitada)
     * @brief
     * Lê o ficheiro dos pedidos rejeitados
     */
    void readRejectedRequests();

};
