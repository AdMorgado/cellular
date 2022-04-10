#pragma once

#include <atomic>
#include <functional>

using JobFunction = std::function<void()>;

struct Job
{
    Job() = default;        

    JobFunction func;
};

