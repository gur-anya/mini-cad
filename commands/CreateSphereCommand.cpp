#include "CreateSphereCommand.h"
#include "../occtviewer.h"

CreateSphereCommand::CreateSphereCommand(OcctViewer* viewer)
    : viewer(viewer)
{
}

void CreateSphereCommand::execute()
{
    shape = viewer->createSphere();
}

void CreateSphereCommand::undo()
{
    viewer->removeShape(shape);
}

std::string CreateSphereCommand::name() const
{
    return "Sphere";
}
