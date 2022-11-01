#pragma once

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
#define ALUNOS_ANO 16
#define ALUNOS_UC 17
#define PERMUTACAO_MENU 18
#define TROCA_SINGULAR 19
#define TROCA_DUPLA 20

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
    void horarioUc();
    void horarioTurma();
    void estudantesMenu();
    void turmaMenu();
    void printSchedule(vector<Slot> slots);
    void inscreverAluno();
    void desinscreverAluno();
    void alunosAno();
    void alunosUC();
    void permutacaoMenu();
    void trocaSingular();
    void trocaDupla();
    void inscricao(char& year, string& courseUnit, string& turma, vector<Turma>& turmas);
    std::stack<short int> menuState;
};
