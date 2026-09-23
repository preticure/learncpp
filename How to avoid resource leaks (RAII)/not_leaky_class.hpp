#pragma once

#include <iostream>
#include <string>
#include <mutex>

class NotLeakyClass
{
public:
    NotLeakyClass()
    {
        mtx.lock();
    }

    ~NotLeakyClass()
    {
        // オブジェクトが破棄される際にミューテックスを手放すが,
        // オブジェクトの存続期間中はずっとロックされたままになる
        // そのため, 同じミューテックスを使って別の処理を行うことができない
        // ロックされたままの状態だと並行プロセスがアクセスすることもできない
        mtx.unlock();
    }

    void OutputText(const std::string& string)
    {
        if (IsStringTooLong(string))
            return; // サイズチェックでリターンしても,
                    // インスタンスが破棄される際に必ずミューテックスが解除される

        std::cout << string << std::endl;
    }
private:
    bool IsStringTooLong(const std::string& string)
    {
        return (string.length() >= 25);
    }

    std::mutex mtx;
};
