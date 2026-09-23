#pragma once

#include <iostream>
#include <string>
#include <mutex>

class MutexHandler
{
public:
    MutexHandler(std::mutex& mtx) : mtx(mtx)
    {
        mtx.lock();
    }

    ~MutexHandler()
    {
        mtx.unlock();
    }

    std::mutex& mtx;
};

class CorrectClass
{
public:
    CorrectClass() {}

    void OutputText(const std::string& string)
    {
        // ミューテックスハンドラに mtx を渡す
        // 途中で早期リターンが発生しても,
        // 関数を抜ける際にミューテックスハンドラオブジェクトの破棄と一緒に mtx も解除される
        MutexHandler mutex_handler(mtx);

        if (IsStringTooLong(string))
            return;

        std::cout << string << std::endl;
    }
private:
    bool IsStringTooLong(const std::string& string)
    {
        return (string.length() >= 25);
    }

    std::mutex mtx;
};
