#pragma once

#include <stack>
#include <memory>
#include <string>

class Command;

/**
 * @brief Менеджер команд.
 *
 * Отвечает за выполнение команд и хранение истории операций.
 * Поддерживает undo/redo.
 */
class CommandManager
{
public:
    /**
     * @brief Выполняет команду.
     * @param cmd команда
     * @return строка для истории
     */
    std::string execute(std::shared_ptr<Command> cmd);

    /**
     * @brief Отменяет последнюю команду.
     * @return строка для истории
     */
    std::string undo();

    /**
     * @brief Повторяет отменённую команду.
     * @return строка для истории
     */
    std::string redo();

private:
    std::stack<std::shared_ptr<Command>> undoStack;
    std::stack<std::shared_ptr<Command>> redoStack;
};
