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
    print_begin("rinvwish");

#ifdef STATS_TEST_MATRIX_FEATURES
    int n_samp = 10000;
    int K = 3;

    stats::rand_engine_t engine_m(1);

    std::cout << "\n*** rinvwish: begin tests. ***\n" << std::endl;

    //

    double nu = 10 + K + 1;
    mat_obj Psi, X;

    stats::mat_ops::eye(Psi,K);
    Psi *= static_cast<double>(nu - K - 1);

    stats::mat_ops::zeros(X,K,K);

    for (int i=0; i < n_samp; i++) {
        X += stats::rinvwish<mat_obj>(Psi,nu,engine_m) / static_cast<double>(n_samp);
    }

    std::cout << "sample mean:\n" << X << std::endl;
    std::cout << "\ntrue mean:\n" << Psi / static_cast<double>(nu - K - 1) << std::endl;

    double dinvwish_val = stats::dinvwish(X,Psi,nu,false);

    std::cout << "\ndensity value: " << dinvwish_val << std::endl;

    //

    std::cout << "\n*** rinvwish: end tests. ***\n" << std::endl;
#else
    std::cout << "\n*** rinvwish: no matrix library found. ***\n" << std::endl;
#endif

    return 0;
}
