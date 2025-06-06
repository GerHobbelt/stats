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

#define STATS_TEST_INPUT_TYPE 1

#define TEST_PRINT_PRECISION_1 2
#define TEST_PRINT_PRECISION_2 5

#include "../stats_tests.hpp"

int main(void)
{
    print_begin("qbern");

    // parameters

    double prob_par = 0.4;

    //

    std::vector<double> inp_vals = { 0.2,  prob_par,  0.9 };
    std::vector<double> exp_vals = { 0,    0,         1};

    //
    // scalar tests

    STATS_TEST_EXPECTED_QUANT_VAL(qbern,inp_vals[0],exp_vals[0],prob_par);
    STATS_TEST_EXPECTED_QUANT_VAL(qbern,inp_vals[1],exp_vals[1],prob_par);
    STATS_TEST_EXPECTED_QUANT_VAL(qbern,inp_vals[2],exp_vals[2],prob_par);

    STATS_TEST_EXPECTED_QUANT_VAL(qbern,TEST_NAN,TEST_NAN,0.5);                                     // NaN inputs
    STATS_TEST_EXPECTED_QUANT_VAL(qbern,0.5,TEST_NAN,TEST_NAN);
    STATS_TEST_EXPECTED_QUANT_VAL(qbern,TEST_NAN,TEST_NAN,TEST_NAN);

    STATS_TEST_EXPECTED_QUANT_VAL(qbern,1,TEST_NAN,-0.1);                                           // bad parameter values
    STATS_TEST_EXPECTED_QUANT_VAL(qbern,1,TEST_NAN,1.1);

    STATS_TEST_EXPECTED_QUANT_VAL(qbern,-1,TEST_NAN,prob_par);                                      // p < 0 or > 1
    STATS_TEST_EXPECTED_QUANT_VAL(qbern, 5,TEST_NAN,prob_par);

    //
    // vector/matrix tests

#ifdef STATS_TEST_STDVEC_FEATURES
    STATS_TEST_EXPECTED_QUANT_MAT(qbern,inp_vals,exp_vals,std::vector<double>,prob_par);
#endif

#ifdef STATS_TEST_MATRIX_FEATURES
    mat_obj inp_mat(2,3);
    inp_mat(0,0) = inp_vals[0];
    inp_mat(1,0) = inp_vals[2];
    inp_mat(0,1) = inp_vals[1];
    inp_mat(1,1) = inp_vals[0];
    inp_mat(0,2) = inp_vals[2];
    inp_mat(1,2) = inp_vals[1];

    mat_obj exp_mat(2,3);
    exp_mat(0,0) = exp_vals[0];
    exp_mat(1,0) = exp_vals[2];
    exp_mat(0,1) = exp_vals[1];
    exp_mat(1,1) = exp_vals[0];
    exp_mat(0,2) = exp_vals[2];
    exp_mat(1,2) = exp_vals[1];

    STATS_TEST_EXPECTED_QUANT_MAT(qbern,inp_mat,exp_mat,mat_obj,prob_par);
#endif

    // 

    print_final("qbern");

    return 0;
}
