#include  "Timer.hpp"

using namespace time_counters;

Time_Counter::Time_Counter()
{
    m_start_inited = false;
    m_finish_inited = false;
}//Time_Counter::Time_Counter()



void Time_Counter::set_start_now()
{
    m_start_inited = true;
//	QueryPerformanceFrequency(&m_freq);
//	QueryPerformanceCounter(&m_start_pos);
}//void  Time_Counter::vSetStartNow()


//if returned value is false it means the timer was not set on start
bool Time_Counter::get_time_passed(double* a_time_passed_sec)
{
    if (!m_start_inited)
    {
        return false;
    }

//    long long int now;
//    QueryPerformanceCounter(&li_now);

    double res;
//    res = (now - m_start_pos);
//    res = res / m_freq;

//    *a_time_passed_sec = res;

    return true;
}//bool  Time_Counter::bGetTimePassed(double  *pdTimePassedMs)


bool Time_Counter::set_finish_on(double a_time_to_finish_sec)
{
    if ((!m_start_inited) || (a_time_to_finish_sec <= 0))
    {
        return false;
    }

    m_finish_inited = true;
    m_finish_pos = m_start_pos + m_freq * a_time_to_finish_sec;
    return true;
}//bool  Time_Counter::bSetFinishOn(double  dTimeToFinishMs)

bool Time_Counter::is_finished()
{
    if ((!m_start_inited) || (!m_finish_inited))
    {
        return true;
    }

//    long long int now;
//    QueryPerformanceCounter(&now);
//    if (now > m_finish_pos)
//        return true;
//    else
        return false;
};//bool  Time_Counter::bIsFinished()






