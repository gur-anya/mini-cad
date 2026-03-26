#include "occtviewer.h"

#include <OpenGl_GraphicDriver.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Xw_Window.hxx>

#include <AIS_Shape.hxx>

#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>

#include <BRepTools.hxx>
#include <TopoDS_Shape.hxx>
#include <BRep_Builder.hxx>

OcctViewer::OcctViewer(QWidget* parent)
    : QWidget(parent)
{
    Handle(Aspect_DisplayConnection) display = new Aspect_DisplayConnection();
    Handle(OpenGl_GraphicDriver) driver = new OpenGl_GraphicDriver(display);

    viewer = new V3d_Viewer(driver);
    viewer->SetDefaultLights();
    viewer->SetLightOn();

    view = viewer->CreateView();

    context = new AIS_InteractiveContext(viewer);
    context->SetDisplayMode(AIS_Shaded, Standard_True);

    initWindow();
}

void OcctViewer::initWindow()
{
    Aspect_Handle win = (Aspect_Handle)this->winId();
    Handle(Aspect_DisplayConnection) display = new Aspect_DisplayConnection();

    window = new Xw_Window(display, win);

    view->SetWindow(window);

    if (!window->IsMapped())
        window->Map();

    view->SetBackgroundColor(Quantity_NOC_BLACK);
    view->MustBeResized();
}

void OcctViewer::resizeEvent(QResizeEvent*)
{
    if (!view.IsNull())
    {
        view->MustBeResized();
    }
}

Handle(AIS_Shape) OcctViewer::createBox(double w, double h, double d)
{
    TopoDS_Shape shape = BRepPrimAPI_MakeBox(w, h, d).Shape();

    Handle(AIS_Shape) ais = new AIS_Shape(shape);
    lastShape = ais;

    context->Display(ais, true);
    view->FitAll();

    return ais;
}

Handle(AIS_Shape) OcctViewer::createSphere()
{
    TopoDS_Shape shape = BRepPrimAPI_MakeSphere(50).Shape();

    Handle(AIS_Shape) ais = new AIS_Shape(shape);
    lastShape = ais;

    context->Display(ais, true);
    view->FitAll();

    return ais;
}

Handle(AIS_Shape) OcctViewer::createCylinder()
{
    TopoDS_Shape shape = BRepPrimAPI_MakeCylinder(20, 60).Shape();

    Handle(AIS_Shape) ais = new AIS_Shape(shape);
    lastShape = ais;

    context->Display(ais, true);
    view->FitAll();
    return ais;
}

void OcctViewer::removeShape(const Handle(AIS_Shape)& shape)
{
    if (shape.IsNull())
        return;

    context->Remove(shape, true);
    view->Redraw();
}

void OcctViewer::exportBrep()
{
    if (lastShape.IsNull())
        return;

    TopoDS_Shape shape = lastShape->Shape();
    BRepTools::Write(shape, "model.brep");
}

void OcctViewer::importBrep()
{
    BRep_Builder builder;
    TopoDS_Shape shape;

    if (!BRepTools::Read(shape, "model.brep", builder))
        return;

    Handle(AIS_Shape) ais = new AIS_Shape(shape);
    context->Display(ais, true);
    view->FitAll();
}
