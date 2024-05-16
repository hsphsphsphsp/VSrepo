#pragma once

#include <string>
#include "Result.cpp"

class ALU
{
    const int NO_ERR = 0;
    const int INVALID_OPERAND1 = 1;
    const int INVALID_OPERAND2 = 2;
    const int INVALID_OPCODE = 3;

    int operand1 = -1;
    int operand2 = -1;
    std::string OPCODE = "";

public:
    void setOperand1(int operand1) {
        this->operand1 = operand1;
    }

    void setOperand2(int operand2) {
        this->operand2 = operand2;
    }

    void setOPCODE(std::string OPCODE) {
        this->OPCODE = OPCODE;
    }

    bool isValid(Result* r) {
        if (OPCODE != "ADD" && OPCODE != "MUL" && OPCODE != "SUB")
        {
            r->setStatus(INVALID_OPCODE);
            return false;
        }

        if (operand1 == -1) {
            r->setStatus(INVALID_OPERAND1);
            return false;
        }

        if (operand2 == -1) {
            r->setStatus(INVALID_OPERAND2);
            return false;
        }

        return true;
    }

    void enableSignal(Result* r) {
        if (!isValid(r)) {
            return;
        }
        
        r->setStatus(NO_ERR);
        if (OPCODE == "ADD") {
            r->setResult(operand1 + operand2);
            return;
        }
        
        if (OPCODE == "MUL") {
            r->setResult(operand1 * operand2);
            return;
        }
        
        if (OPCODE == "SUB") {
            r->setResult(operand1 - operand2);
            return;
        }   
    }
};