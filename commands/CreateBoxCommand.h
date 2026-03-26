#pragma once

#include "Command.h"
#include <AIS_Shape.hxx>

class OcctViewer;

/**
 * @brief Команда создания параллелепипеда.
 *
 * Поддерживает параметрическое моделирование.
 */
class CreateBoxCommand : public Command
{
public:
    CreateBoxCommand(OcctViewer* viewer, double w, double h, double d);

    void execute() override;
    void undo() override;
    std::string name() const override;

private:
    OcctViewer* viewer;
    Handle(AIS_Shape) shape;

    double width;
    double height;
    double depth;
};
