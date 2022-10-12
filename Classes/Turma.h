//
// Created by luis on 11-10-2022.
//

#ifndef AED_PROJ_TURMA_H
#define AED_PROJ_TURMA_H

#include <iostream>
#include <vector>
#include <fstream>


class Turma {

public:
    Turma();
    Turma (const std::string& classCode, const std::string& ucCode);
    const std::string &getClassCode() const;
    void setClassCode(const std::string &classCode);

private:
    std::string classCode;
    std::string ucCode;
};


#endif //AED_PROJ_TURMA_H
