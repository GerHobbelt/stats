/*################################################################################
  ##
  ##   Copyright (C) 2011-2023 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

#include "../stats_tests.hpp"

int main(void)
{
    print_begin("runif");

    //

    double a_par = -1;
    double b_par = 3;

    double unif_mean = (a_par + b_par) / 2.0;
    double unif_var = (b_par - a_par) * (b_par - a_par) / 12.0;

    int n_sample = 10000;

    //

    double unif_rand = stats::runif(a_par,b_par);
    std::cout << "unif rv draw: " << unif_rand << std::endl;

    //

#ifdef STATS_TEST_STDVEC_FEATURES
    std::cout << "\n";
    std::vector<double> unif_stdvec = stats::runif<std::vector<double>>(n_sample,1,a_par,b_par);

    std::cout << "stdvec: unif rv mean: " << stats::mat_ops::mean(unif_stdvec) << ". Should be close to: " << unif_mean << std::endl;
    std::cout << "stdvec: unif rv variance: " << stats::mat_ops::var(unif_stdvec) << ". Should be close to: " << unif_var << std::endl;

    //

    stats::rand_engine_t engine_s(1);

    unif_stdvec = stats::runif<std::vector<double>>(n_sample,1,a_par,b_par,engine_s);

    std::cout << "stdvec (with random engine): unif rv mean: " << stats::mat_ops::mean(unif_stdvec) << ". Should be close to: " << unif_mean << std::endl;
    std::cout << "stdvec (with random engine): unif rv variance: " << stats::mat_ops::var(unif_stdvec) << ". Should be close to: " << unif_var << std::endl;
#endif

    //

#ifdef STATS_TEST_MATRIX_FEATURES
    std::cout << "\n";
    mat_obj unif_vec = stats::runif<mat_obj>(n_sample,1,a_par,b_par);

    std::cout << "Matrix: unif rv mean: " << stats::mat_ops::mean(unif_vec) << ". Should be close to: " << unif_mean << std::endl;
    std::cout << "Matrix: unif rv variance: " << stats::mat_ops::var(unif_vec) << ". Should be close to: " << unif_var << std::endl;

    //

    stats::rand_engine_t engine_m(1);

    unif_vec = stats::runif<mat_obj>(n_sample,1,a_par,b_par,engine_m);

    std::cout << "Matrix (with random engine): unif rv mean: " << stats::mat_ops::mean(unif_vec) << ". Should be close to: " << unif_mean << std::endl;
    std::cout << "Matrix (with random engine): unif rv variance: " << stats::mat_ops::var(unif_vec) << ". Should be close to: " << unif_var << std::endl;
#endif
    
    //

    std::cout << "\n*** runif: end tests. ***\n" << std::endl;
    
    return 0;
}
