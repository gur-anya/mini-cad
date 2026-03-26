#pragma once

#include "Command.h"
#include <AIS_Shape.hxx>

class OcctViewer;

/**
 * @brief Команда создания цилиндра.
 */
class CreateCylinderCommand : public Command
{
public:
    CreateCylinderCommand(OcctViewer* viewer);

    void execute() override;
    void undo() override;
    std::string name() const override;

private:
    OcctViewer* viewer;
    Handle(AIS_Shape) shape;
};
