#include <gtest/gtest.h>
#include "../history/CommandManager.h"
#include "../commands/Command.h"

class MockCommand : public Command
{
public:
    bool executed = false;
    bool undone = false;

    void execute() override { executed = true; }
    void undo() override { undone = true; }
    std::string name() const override { return "Mock"; }
};

TEST(CommandManagerTest, ExecuteCommand)
{
    CommandManager manager;
    auto cmd = std::make_shared<MockCommand>();

    manager.execute(cmd);

    EXPECT_TRUE(cmd->executed);
}

TEST(CommandManagerTest, UndoCommand)
{
    CommandManager manager;
    auto cmd = std::make_shared<MockCommand>();

    manager.execute(cmd);
    manager.undo();

    EXPECT_TRUE(cmd->undone);
}

TEST(CommandManagerTest, RedoCommand)
{
    CommandManager manager;
    auto cmd = std::make_shared<MockCommand>();

    manager.execute(cmd);
    manager.undo();
    manager.redo();

    EXPECT_TRUE(cmd->executed);
}
