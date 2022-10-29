#ifndef AED_PROJ_MENU_H
#define AED_PROJ_MENU_H

#include <stack>
#include <algorithm>
#include "Managing.h"
/*
 * Menus' definition
 */
#define MAIN_MENU 0
#define CONSULTAS_MENU 1
#define MODIFICACOES_MENU 2
#define PEDIDOS_MENU 3
#define ALUNOS_MENU 4
#define ESTUDANTES_MENU 5
#define HORARIOS_MENU 6
#define HORARIO_ALUNO 7
#define HORARIO_TURMA 8
#define HORARIO_UC 9
#define TURMA_MENU 10
#define TURMAS_MENU 11
#define COURSE_UNITS_MENU 12
#define YEARS_MENU 13
#define INSCREVER_ALUNO_MENU 14
#define DESINSCREVER_ALUNO_MENU 15

class Menu {
public:
    Menu();
    void mainMenu();
private:
    void getMenu();
    void consultasMenu();
    void modificacoesMenu();
    void efetivacaoMenu();
    void alunosMenu();
    void horariosMenu();
    void horarioAluno();
    void horarioTurma();
    void estudantesMenu();
    void turmaMenu();
    void printSchedule(vector<Slot> slots);
    void inscreverAluno();
    void desinscreverAluno();
    std::stack<short int> menuState;

};


#endif //AED_PROJ_MENU_H
