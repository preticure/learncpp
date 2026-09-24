#pragma once

/**
 * CRTP (Curiously Recurring Template Pattern)
 * 
 *      基底クラス: 派生クラスのテンプレートパラメータを持つ
 *      派生クラス: テンプレートパラメータとして自身を使用する
 * 
 *      これにより, 基底クラスが派生クラスの型を知ることができるため、
 *      派生型への静的型キャストを使用することができる
 */

template <typename Derived>
class Base
{
public:
    Base() = default;

    void DoSomething()
    {
        Derived& derived = static_cast<Derived&>(*this);
        // use derived...
    }
};

class Derived : public Base<Derived>
{
public:
    Derived() = default;
};
