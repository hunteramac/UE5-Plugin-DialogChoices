#if WITH_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "ObjectDialogLogic.h"

BEGIN_DEFINE_SPEC(FExampleSpec, "Example",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);
    bool myBool;
// Variables and functions defined here will end up being member of 
// the FExampleSpec class and will be accessible in the tests

END_DEFINE_SPEC(FExampleSpec);

void FExampleSpec::Define()
{
    Describe("GetHighlightIndex()", [this]()
        {
            It("Should equal 0 to start", [this]()
                {
                    UObjectDialogLogic* MyDialogLogic = NewObject<UObjectDialogLogic>();
                    TestEqual("Hightlighted choice starts at 0", MyDialogLogic->GetHighlightIndex(), 0);
                });
        });

    Describe("MoveHightlightedChoiceDown()", [this]()
        {
            It("Should indicate highlight choice", [this]()
                {
                    //arrange
                    UObjectDialogLogic* MyDialogLogic = NewObject<UObjectDialogLogic>();
                    MyDialogLogic->NumChoices = 2;

                    TestEqual("0 to start", MyDialogLogic->GetHighlightIndex(), 0);
                    MyDialogLogic->MoveHightlightedChoiceDown();
                    TestEqual("1 after moving down once", MyDialogLogic->GetHighlightIndex(),1);
                    TestEqual("0 after moving down twice (wrap around)", MyDialogLogic->GetHighlightIndex(), 1);
                });
        });

    Describe("MoveHightlightedChoiceUp()", [this]()
        {
            It("Should indicate highlight choice", [this]()
                {
                    UObjectDialogLogic* MyDialogLogic = NewObject<UObjectDialogLogic>();

                    MyDialogLogic->NumChoices =2;
                    MyDialogLogic->MoveHightlightedChoiceUp();

                    TestEqual("CurrentHightlightedChoice", MyDialogLogic->GetHighlightIndex(), 1);
                });
        });
}

#endif