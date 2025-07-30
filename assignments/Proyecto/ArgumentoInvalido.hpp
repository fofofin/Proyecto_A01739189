#ifndef ARGUMENTOINVALIDO_HPP
#define ARGUMENTOINVALIDO_HPP

#include <stdexcept>
#include <string>

class ArgumentoInvalido : public std::runtime_error {
    public:
        ArgumentoInvalido(const std::string& mensaje)
            : std::runtime_error(mensaje) {}
};

#endif