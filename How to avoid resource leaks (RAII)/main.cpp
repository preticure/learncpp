#include "leaky_class.hpp"
#include "not_leaky_class.hpp"
#include "correct_class.hpp"

int main()
{
    LeakyClass leaky_class;
    leaky_class.OutputText("LeakyClass: Test");
    // leaky_class.OutputText("LeakyClass: This is a longer Test");
    leaky_class.OutputText("LeakyClass: Test2");

    NotLeakyClass not_leakey_class;
    not_leakey_class.OutputText("NotLeakyClass: Test");
    // not_leakey_class.OutputText("NotLeakyClass: This is a longer Test");
    not_leakey_class.OutputText("NotLeakyClass: Test2");

    CorrectClass correct_class;
    correct_class.OutputText("CorrectClass: Test");
    // correct_class.OutputText("CorrectClass: This is a longer Test");
    correct_class.OutputText("CorrectClass: Test2");

    return 0;
}
