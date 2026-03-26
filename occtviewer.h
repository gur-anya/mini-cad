#pragma once

#include <QWidget>
#include <AIS_Shape.hxx>
#include <AIS_InteractiveContext.hxx>
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <Aspect_Window.hxx>

/**
 * @brief Класс визуализации OpenCASCADE.
 *
 * Отвечает за отображение 3D сцены и объектов.
 */
class OcctViewer : public QWidget
{
    Q_OBJECT

public:
    OcctViewer(QWidget* parent = nullptr);

public slots:
    Handle(AIS_Shape) createBox(double w, double h, double d);
    Handle(AIS_Shape) createSphere();
    Handle(AIS_Shape) createCylinder();

    void exportBrep();
    void removeShape(const Handle(AIS_Shape)& shape);
    void importBrep();

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void initWindow();

    Handle(V3d_Viewer) viewer;
    Handle(V3d_View) view;
    Handle(AIS_InteractiveContext) context;
    Handle(Aspect_Window) window;

    Handle(AIS_Shape) lastShape;
};
