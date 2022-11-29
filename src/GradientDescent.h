/**
 * @author sanyavertolet
 */

#ifndef FIELDS_OF_GOLD_GRADIENTDESCENT_H
#define FIELDS_OF_GOLD_GRADIENTDESCENT_H

#include "utils.h"
#include "Functions/AbstractFunction/AbstractFunction.h"
#include "Factory/FunctionFactory.h"

constexpr numeric_type delta = 0.001;

numeric_type solve(AbstractFunctionPtr function, numeric_type x_0, int iterations, numeric_type lambda);

numeric_type solve(AbstractFunctionPtr function, numeric_type x_0, int iterations, numeric_type lambda, numeric_type lambda_decreaser);

#endif //FIELDS_OF_GOLD_GRADIENTDESCENT_H
