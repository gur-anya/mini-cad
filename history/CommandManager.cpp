#include "CommandManager.h"
#include "../commands/Command.h"

std::string CommandManager::execute(std::shared_ptr<Command> cmd)
{
    cmd->execute();
    undoStack.push(cmd);

    while (!redoStack.empty())
        redoStack.pop();

    return "build " + cmd->name();
}

std::string CommandManager::undo()
{
    if (undoStack.empty())
        return "";

    auto cmd = undoStack.top();
    undoStack.pop();

    cmd->undo();
    redoStack.push(cmd);

    return "undo " + cmd->name();
}

std::string CommandManager::redo()
{
    if (redoStack.empty())
        return "";

    auto cmd = redoStack.top();
    redoStack.pop();

    cmd->execute();
    undoStack.push(cmd);

    return "redo " + cmd->name();
}
