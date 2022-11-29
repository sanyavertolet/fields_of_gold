/**
 * @author sanyavertolet
 */

#include "GradientDescent.h"
#include "Functions/Operators/operators.h"

numeric_type gradient(AbstractFunctionPtr function, numeric_type x) {
    return function->get_derivative(x);
}

numeric_type solve(AbstractFunctionPtr function, numeric_type x, int iterations, numeric_type lambda) {
    auto square_function = *function * *function;
    for (; iterations > 0; --iterations) {
        x = x - lambda * gradient(square_function, x);
    }
    return x;
}

numeric_type solve(AbstractFunctionPtr function, numeric_type x, int iterations, numeric_type lambda, numeric_type lambda_decreaser) {
    auto square_function = *function * *function;
    for (; iterations > 0; --iterations) {
        x = x - lambda * gradient(square_function, x);
        lambda = lambda / lambda_decreaser;
    }
    return x;
}
