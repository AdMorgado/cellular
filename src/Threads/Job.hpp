#pragma once

#include <atomic>
#include <functional>

struct Job
{
    Job() = default;        

    std::function<void()> func;
};

