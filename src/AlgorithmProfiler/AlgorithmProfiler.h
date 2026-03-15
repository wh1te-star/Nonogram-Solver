#ifndef ALGORITHMPROFILER_H
#define ALGORITHMPROFILER_H

#include <iostream>
#include <chrono>
#include <cstdint>

template <typename ResultType>
struct ProfileReport {
    ResultType result;
    double elapsed_ms;
    size_t used_memory_byte;
    bool is_tle;
    bool is_mle;
};

template <typename ResultType>
class Profiler {
private:
    const double time_limit_ms;
    const size_t memory_limit_byte;
    uintptr_t stack_base;

    uintptr_t get_current_sp() const {
        char local_var;
        return reinterpret_cast<uintptr_t>(&local_var);
    }

public:
    Profiler(double t_limit, size_t m_limit)
        : time_limit_ms(t_limit), memory_limit_byte(m_limit) {
        stack_base = get_current_sp();
    }

    template <typename Func>
    ProfileReport<ResultType> execute(Func&& algo) {
        ProfileReport<ResultType> report{};
        
        auto start_time = std::chrono::high_resolution_clock::now();
        
        report.result = algo();

        auto end_time = std::chrono::high_resolution_clock::now();

        report.elapsed_ms = std::chrono::duration<double, std::milli>(end_time - start_time).count();
        report.is_tle = (report.elapsed_ms > time_limit_ms);

        uintptr_t current_sp = get_current_sp();
        report.used_memory_byte = (stack_base > current_sp) ? (stack_base - current_sp) : (current_sp - stack_base);
        report.is_mle = (report.used_memory_byte > memory_limit_byte);

        return report;
    }
};

#endif