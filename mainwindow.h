#pragma once

#include <QMainWindow>
#include "../history/CommandManager.h"

class OcctViewer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    OcctViewer* viewer;
    CommandManager commandManager;
};
