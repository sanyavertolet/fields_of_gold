/**
 * @author sanyavertolet
 */

#include "../CompositionFunction/CompositionFunction.h"
#include "../../Factory/FunctionFactory.h"

CompositionFunction* operator+(AbstractFunction &left, AbstractFunction &right) {
    auto ptr = new CompositionFunction(&left, &right, '+');
    FunctionFactory::get().add(ptr);
    return ptr;
}

CompositionFunction* operator-(AbstractFunction &left, AbstractFunction &right) {
    auto ptr = new CompositionFunction(&left, &right, '-');
    FunctionFactory::get().add(ptr);
    return ptr;
}

CompositionFunction* operator*(AbstractFunction &left, AbstractFunction &right) {
    auto ptr = new CompositionFunction(&left, &right, '*');
    FunctionFactory::get().add(ptr);
    return ptr;
}

CompositionFunction* operator/(AbstractFunction &left, AbstractFunction &right) {
    auto ptr = new CompositionFunction(&left, &right, '/');
    FunctionFactory::get().add(ptr);
    return ptr;
}
