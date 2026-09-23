#pragma once

#include <iostream>
#include <string>
#include <mutex>

class LeakyClass
{
public:
    LeakyClass() {}

    void OutputText(const std::string& string)
    {
        // ロックを取得
        mtx.lock();

        if (IsStringTooLong(string))
            return; // ここでリターンすると解除処理まで到達せず, 永遠にロックされたままになる

        std::cout << string << std::endl;

        // ロックを手放す
        mtx.unlock();
    }
private:
    bool IsStringTooLong(const std::string& string)
    {
        return (string.length() >= 25);
    }

    std::mutex mtx;
};
