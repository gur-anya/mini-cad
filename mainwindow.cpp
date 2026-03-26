#include "mainwindow.h"
#include "occtviewer.h"

#include "../commands/CreateBoxCommand.h"
#include "../commands/CreateSphereCommand.h"
#include "../commands/CreateCylinderCommand.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QLabel>

MainWindow::MainWindow()
{
    viewer = new OcctViewer(this);
    setCentralWidget(viewer);

    QWidget* panel = new QWidget(this);
    panel->setFixedSize(200, 500);

    QVBoxLayout* layout = new QVBoxLayout(panel);

    QListWidget* historyList = new QListWidget();

    QLineEdit* widthEdit = new QLineEdit("100");
    QLineEdit* heightEdit = new QLineEdit("50");
    QLineEdit* depthEdit = new QLineEdit("30");

    layout->addWidget(new QLabel("Width"));
    layout->addWidget(widthEdit);

    layout->addWidget(new QLabel("Height"));
    layout->addWidget(heightEdit);

    layout->addWidget(new QLabel("Depth"));
    layout->addWidget(depthEdit);

    QPushButton* boxBtn = new QPushButton("Box");
    QPushButton* sphereBtn = new QPushButton("Sphere");
    QPushButton* cylinderBtn = new QPushButton("Cylinder");
    QPushButton* exportBtn = new QPushButton("Export");
    QPushButton* importBtn = new QPushButton("Import");
    QPushButton* undoBtn = new QPushButton("Undo");
    QPushButton* redoBtn = new QPushButton("Redo");

    layout->addWidget(boxBtn);
    layout->addWidget(sphereBtn);
    layout->addWidget(cylinderBtn);
    layout->addWidget(exportBtn);
    layout->addWidget(importBtn);
    layout->addWidget(undoBtn);
    layout->addWidget(redoBtn);
    layout->addWidget(historyList);

    panel->setLayout(layout);
    panel->move(20, 20);
    panel->setStyleSheet("background-color: rgba(255,255,255,200); border-radius: 8px;");

    connect(boxBtn, &QPushButton::clicked, this, [this, historyList, widthEdit, heightEdit, depthEdit]() {
        double w = widthEdit->text().toDouble();
        double h = heightEdit->text().toDouble();
        double d = depthEdit->text().toDouble();

        auto log = commandManager.execute(std::make_shared<CreateBoxCommand>(viewer, w, h, d));
        historyList->addItem(QString::fromStdString(log));
    });

    connect(sphereBtn, &QPushButton::clicked, this, [this, historyList]() {
        auto log = commandManager.execute(std::make_shared<CreateSphereCommand>(viewer));
        historyList->addItem(QString::fromStdString(log));
    });

    connect(cylinderBtn, &QPushButton::clicked, this, [this, historyList]() {
        auto log = commandManager.execute(std::make_shared<CreateCylinderCommand>(viewer));
        historyList->addItem(QString::fromStdString(log));
    });

    connect(exportBtn, &QPushButton::clicked, viewer, &OcctViewer::exportBrep);
    connect(importBtn, &QPushButton::clicked, viewer, &OcctViewer::importBrep);

    connect(undoBtn, &QPushButton::clicked, this, [this, historyList]() {
        auto log = commandManager.undo();
        if (!log.empty())
            historyList->addItem(QString::fromStdString(log));
    });

    connect(redoBtn, &QPushButton::clicked, this, [this, historyList]() {
        auto log = commandManager.redo();
        if (!log.empty())
            historyList->addItem(QString::fromStdString(log));
    });
}
