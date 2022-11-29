/**
 * @author sanyavertolet
 */

#include "AbstractFunction.h"

#include <utility>

AbstractFunction::AbstractFunction(std::string  function_type, std::initializer_list<numeric_type> parameters):
type(std::move(function_type)), params(parameters) { }

std::string AbstractFunction::to_string() {
    return type;
}
