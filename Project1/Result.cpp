#pragma once

class Result
{
    int status = -1;
    int result = 65535;

    //status -1 : 결과 안나옴
    //status 0 : 성공
    //status 1 : Operand1이 잘못됨
    //status 2 : Operand2가 잘못됨
    //status 3 : OPCODE가 잘못되었음

    //result 65535 : 결과 없음

public:
    void setStatus(int status) {
        this->status = status;
    }

    void setResult(int result) {
        this->result = result;
    }

    int getStatus() {
        return status;
    }

    int getResult() {
        return result;
    }
};