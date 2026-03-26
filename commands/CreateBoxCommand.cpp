#include "CreateBoxCommand.h"
#include "../occtviewer.h"

CreateBoxCommand::CreateBoxCommand(OcctViewer* viewer, double w, double h, double d)
    : viewer(viewer), width(w), height(h), depth(d)
{
}

void CreateBoxCommand::execute()
{
    shape = viewer->createBox(width, height, depth);
}

void CreateBoxCommand::undo()
{
    viewer->removeShape(shape);
}

std::string CreateBoxCommand::name() const
{
    return "Box";
}
