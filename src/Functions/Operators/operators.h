/**
 * @author sanyavertolet
 */

#ifndef FIELDS_OF_GOLD_OPERATORS_H
#define FIELDS_OF_GOLD_OPERATORS_H

#include "../AbstractFunction/AbstractFunction.h"
#include "../CompositionFunction/CompositionFunction.h"

CompositionFunction* operator+(AbstractFunction &left, AbstractFunction &right);

CompositionFunction* operator-(AbstractFunction &left, AbstractFunction &right);

CompositionFunction* operator*(AbstractFunction &left, AbstractFunction &right);

CompositionFunction* operator/(AbstractFunction &left, AbstractFunction &right);

#endif //FIELDS_OF_GOLD_OPERATORS_H
