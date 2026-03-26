#include "CreateCylinderCommand.h"
#include "../occtviewer.h"

CreateCylinderCommand::CreateCylinderCommand(OcctViewer* viewer)
    : viewer(viewer)
{
}

void CreateCylinderCommand::execute()
{
    shape = viewer->createCylinder();
}

void CreateCylinderCommand::undo()
{
    viewer->removeShape(shape);
}

std::string CreateCylinderCommand::name() const
{
    return "Cylinder";
}
