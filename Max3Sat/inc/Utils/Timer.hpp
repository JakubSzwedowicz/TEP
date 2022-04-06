#pragma once

namespace time_counters
{
    class Time_Counter
    {
    public:

        Time_Counter();

        ~Time_Counter()
        {};

        void set_start_now();

        bool
        get_time_passed(double* a_time_passed_sec);//if returned value is false it means the timer was not set on start
        bool set_finish_on(double a_time_to_finish_sec);

        bool is_finished();

    private:
        bool m_start_inited;
        long long int m_start_pos;
        long long int m_freq;

        bool m_finish_inited;
        long long int m_finish_pos;

    };//class  Time_Counter
};//namespace  time_counters