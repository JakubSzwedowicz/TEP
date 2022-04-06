#include "Max3Sat.hpp"

int main(int arg_count, char** args)
{
    Max3Sat prob;
    prob.run();
}

// Ugly function
//void run_experiment(Max3Sat* a_problem)
//{
//    try
//    {
//        Time_Counter time_counter;
//
//        double time_passed;
//
//        Optimizer opt(a_problem);
//
//        time_counter.set_start_now();
//
//        opt.initialize();
//
//        time_counter.get_time_passed(&time_passed);
//
//        while (time_passed <= MAX_TIME)
//        {
//            opt.run_iteration();
//            opt.get_best_score();
//
//            time_counter.get_time_passed(&time_passed);
//        }//while (time_passed <= MAX_TIME)
//    }//try
//    catch (const std::exception& ex)
//    {
//        std::cout << ex.what() << std::endl;
//    }//catch (exception &c_exception)
//}//void run_experiment(const CEvaluator &cConfiguredEvaluator)