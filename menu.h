#pragma once
#include <stack>
#include <algorithm>
#include "Managing.h"

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
#define UCS_MENU 12
#define ANOS_MENU 13
#define INSCREVER_ALUNO_MENU 14
#define DESINSCREVER_ALUNO_MENU 15
#define ALUNOS_ANO 16
#define ALUNOS_UC 17
#define PERMUTACAO_MENU 18
#define TROCA_SINGULAR 19
#define TROCA_DUPLA 20
#define TURMAS_DECRESCENTE_MENU 21
#define TURMAS_CRESCENTE_MENU 22
#define UCS_DECRESCENTE_MENU 23
#define UCS_CRESCENTE_MENU 24
#define LISTAR_PEDIDOS_MENU 25
#define PEDIDOS_ARQUIVADOS_MENU 26
#define EFETIVADOS_MENU 27
#define ANOS_CRESCENTE_MENU 28
#define ANOS_DECRESCENTE_MENU 29
#define TURMAS_ANO_MENU 30
#define TURMAS_UC_MENU 31
#define TURMAS_ORDEM_MENU 32
#define ESTUDANTES_NUCS 33


class Menu {
public:
    Menu();

    /**
     *@brief
     * Imprime o menu inicial. Fica à espera de input do utilizador. O(1).
     */
    void mainMenu();
private:
    /**
     * @brief
     * Atualiza o menu, consoante o menu que se encontra no topo da stack. O(1).
     */
    void getMenu();

    /**
     * @brief
     * Menu que contém todas as categorias de listagens (Alunos, Turmas, Horários, etc). O(1).
     */
    void consultasMenu();

    /**
     * @brief
     * Menu que mostra todas as modificações possíveis (mudanças de turma, inscrição, permutações). O(1).
     */
    void modificacoesMenu();

    /**
     * @brief
     * Menu que permite gerir os pedidos efetuados no menu de modificações: ver pedidos em espera, ver pedidos arquivados, efetuar pedidos. O(1).
     */
    void efetivacaoMenu();

    /**
     * @brief
     * Menu que mostra todas as listagens possíveis relativamente aos alunos (alunos inscritos, alunos inscritos por ano, alunos inscritos por UC, etc...). O(1).
     */
    void alunosMenu();

    /**
     * @brief
     * Menu que mostra todas as lsitagens possíveis relativamente às turmas (turmas por nº de alunos, turmas de um ano, etc). O(1).
     */
    void turmasMenu();

    /**
     * @brief
     * Mostra os tipos de listagens para as turmas (crescente/decrescente). O(1).
     */
    void turmasOrdemMenu();

    /**
     * @brief
     * Mostra as turmas por ordem decrescente de número de alunos. O(n log(n)).
     */
    void turmasDecrescenteMenu();

    /**
     * @brief
     * Mostra as turmas por ordem decrescente de número de alunos. O(n³), por chamar m.getOcupacaoTurmas() que tem complexidade O(n³).
     */
    void turmasCrescenteMenu();

    /**
     * @brief
     * Mostra a ocupação de turmas por ano. O(n³), por chamar m.getOcupacaoTurmas() que tem complexidade O(n³).
     */
    void turmasAnoMenu();

    /**
     * @brief
     * Mostra a ocupação de uma turma de uma UC. O(n³), por chamar m.getOcupacaoTurmas() que tem complexidade O(n³).
     */
    void turmasUcMenu();

    /**
     * @brief
     * Mostra listagens possíveis para as UCS. O(1). Em caso de o utilizador querer ver ocupação de uma UC de um ano (opção 3), O(n³) por chamar m.getOcupacaoUCS(), que tem complexidade O(n³).
     */
    void ucsMenu();

    /**
     * @brief
     * UCs por ordem decrescente de número de alunos. O(n³) por chamar m.getOcupacaoUCS(), que tem complexidade O(n³).
     */
    void ucsDecrescenteMenu();

    /**
     * @brief
     * UCs por ordem decrescente de número de alunos. O(n³) por chamar m.getOcupacaoUCS(), que tem complexidade O(n³).
     */
    void ucsCrescenteMenu();

    /**
     * @brief
     * Mostra listagens possíveis para os anos curriculares. O(1).
     */
    void anosMenu();

    /**
     * @brief
     * Mostra anos por ordem crescente de alunos. O(n²) por chamar m.getOcupacaoYear(), que tem complexidade O(n²).
     */
    void anosCrescenteMenu();

    /**
     * @brief
     * Mostra anos por ordem decrescente de alunos. O(n²) por chamar m.getOcupacaoYear(), que tem complexidade O(n²).
     */
    void anosDecrescenteMenu();

    /**
     * @brief
     * Mostra listagens possíveis para os horários. O(1).
     */
    void horariosMenu();

    /**
     * @brief
     * Mostra o horário de um aluno. O(n²) por chamar m.getStudentSchedule() que tem complexidade O(n²).
     */
    void horarioAluno();

    /**
     * @brief
     * Mostra o horário de uma UC. O(n²).
     */
    void horarioUc();

    /**
     * @brief
     * Mostra o horário de uma turma (sem estar associada a uma UC). O(n²).
     */
    void horarioTurma();

    /**
     * @brief
     * Mostra o menu de opções possíveis para listar estudantes (ordem alfabética/up(. O(n log(n)) por chamar a função chooseStudentOrder(...).
     */
    void estudantesMenu();

    /**
     * @brief
     * Mostra os alunos por turma (turma+uc). O(n²).
     */
    void turmaMenu();

    /**
     * @brief
     * Menu que vai pedindo info ao utilizador para a inscrição de um aluno. Chama a função inscricao(...), que tem complexidade ~O(n).
     */
    void inscreverAluno();

    /**
     * @brief
     * Desinscreve um aluno de uma turma. A desinscrição é imediata (não constitui um pedido) porque não carece de verificação de desequilíbrios/overlapping slots/etc. O(n).
     */
    void desinscreverAluno();

    /**
     * @brief
     * Menu inicial que pede info ao utilizador para ver alunos de um ano. O(n log(n)) por chamar a função chooseStudentOrder(...).
     */
    void alunosAno();

    /**
     * @brief
     * Mostra os alunos de uma UC. ~O(n²).
     */
    void alunosUC();

    /**
     * @brief
     * Menu que lista opções possíveis para trocas (trocar turma de estudante, trocar entre dois estudantes). O(1).
     */
    void permutacaoMenu();

    /**
     * @brief
     * Menu que trata de pedidos de mudança de turma de um aluno. ~O(n log(n)).
     */
    void trocaSingular();

    /**
     * @brief
     * Menu que trata de pedidos de mudança de turma entre dois alunos. ~O(n log(n)).
     */
    void trocaDupla();

    /**
     * @brief
     * Trata da inscrição de um aluno em turmas. ~O(n log(n)).
     * @param year ano curricular.
     * @param courseUnit unidade curricular para inscrição.
     * @param turma turma da unidade curricular para inscrição.
     * @param turmas vetor de turmas que armazena todas as turmas para onde o estudante quer ir caso eventualmente ele queira uma inscrição em várias.
     */
    void inscricao(char& year, string& courseUnit, string& turma, vector<Turma>& turmas);

    /**
     * @brief
     * Lista todos os pedidos ainda não processados/efetivados. O(1) se não existirem; O(n) se existirem -> n = número de pedidos.
     */
    void listarPedidos();

    /**
     * @brief
     * Lista todos os pedidos arquivados (arquivados == rejeitados por incompatibilidade). O(1) se não existirem; O(n) se existirem -> n = número de pedidos rejeitados.
     */
    void pedidosArquivados();

    /**
     * @brief
     * Trata do processamento/efetivação dos pedidos. Se existirem pedidos para efetivar.
     */
    void efetivadosMenu();

    /**
     * @brief
     * Menu que pede a ordem da listagens dos estudantes. O(n log(n)) porque chama a função sortStudentsByName(), que é O(n log(n)).
     */
    void chooseStudentsOrder(set<Student*, studComp>);

    /**
     * @brief
     * Menu que lista os estudantes com mais de n UCs. O(n log(n)), porque chama a função m.sortStudentsByNUCS().
     */
    void estudantesNUCS();

    std::stack<short int> menuState;
};
