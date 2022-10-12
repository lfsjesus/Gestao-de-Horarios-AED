cmake_minimum_required(VERSION 3.23)
project(AED_Proj)

set(CMAKE_CXX_STANDARD 14)

add_executable(AED_Proj main.cpp menus.h menus.cpp Classes/Aula.h Classes/Turma.h Classes/Turma.cpp Classes/Horario.cpp Classes/Horario.h Classes/Aula.cpp Classes/Estudante.cpp Classes/Estudante.h Classes/Inscricao.cpp Classes/Inscricao.h Classes/Dados.cpp Classes/Dados.h)
