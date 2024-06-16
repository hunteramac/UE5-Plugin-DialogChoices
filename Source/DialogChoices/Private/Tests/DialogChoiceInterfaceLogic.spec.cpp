#if WITH_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "ObjectDialogLogic.h"

BEGIN_DEFINE_SPEC(FDialogLogicSpec, "DialogChoice.DemoUI.Logic",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);
UObjectDialogLogic* dialogLogic; //member of FDialogLogicSpec class, accessible during tests
END_DEFINE_SPEC(FDialogLogicSpec);

void FDialogLogicSpec::Define()
{
    //Scope of tests is written during TDD of class
    Describe("TDD", [this]()
    {
        BeforeEach([this]()
        {
            dialogLogic = NewObject<UObjectDialogLogic>();

        });
        It("should return highlighted choice index zero before and after the first move", [this]()
        {
            dialogLogic->InitializeObject(10);
            TestEqual("starts at 0", dialogLogic->GetHighlightIndex(), 0);
            dialogLogic->MoveHightlightedChoiceDown();
            TestEqual("remain zero after the first scroll", dialogLogic->GetHighlightIndex(), 0);
        });
        //Clear room to be DRYer
        It("should return increasing index and wrap around before exceeding the initialized choice number when moving highlighted choice down", [this]()
        {
            dialogLogic->InitializeObject(2);

            TestEqual("starts at 0", dialogLogic->GetHighlightIndex(), 0);

            dialogLogic->MoveHightlightedChoiceDown();
            TestEqual("remain zero after the first scroll", dialogLogic->GetHighlightIndex(), 0);

            dialogLogic->MoveHightlightedChoiceDown();
            TestEqual("equal 1 after second scroll", dialogLogic->GetHighlightIndex(), 1);

            dialogLogic->MoveHightlightedChoiceDown();
            TestEqual("equal 0", dialogLogic->GetHighlightIndex(), 0);
        });
        It("should return decreasing index and wrap around on zero to maximum index when moving highlighted choice up", [this]()
        {
            dialogLogic->InitializeObject(5);

            TestEqual("starts at 0", dialogLogic->GetHighlightIndex(), 0);

            dialogLogic->MoveHightlightedChoiceUp();
            TestEqual("remain zero after the first scroll up", dialogLogic->GetHighlightIndex(), 0);

            dialogLogic->MoveHightlightedChoiceUp();
            TestEqual("wrap around to 4 after second scroll", dialogLogic->GetHighlightIndex(), 4);

            dialogLogic->MoveHightlightedChoiceUp();
            TestEqual("wrap around to 4 after second scroll", dialogLogic->GetHighlightIndex(), 3);
        });
    });
}

#endif