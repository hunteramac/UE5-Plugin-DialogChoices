#include "ChoiceUIGameInstanceSubsystem.h"

//Should be called by UI when a button is pressed by user
//If choice is -1, async desconstructs -> Enables termination by system instead of waiting on user input
void UChoiceUIGameInstanceSubsystem::UIUserChoice(int Choice) {
	OnResultCallback.Execute(Choice);
}

void UChoiceUIGameInstanceSubsystem::ShowConfirmation(TArray<FText> Actions, FCommonMessagingResultDelegate ResultCallback) {
	//Store actions as a BP var that UI can read from the subsystem
	DisplayActions = Actions;

	//store callback
	OnResultCallback = ResultCallback;
}

void UChoiceUIGameInstanceSubsystem::SubsystemShowChoice() {
	OnSubsystemShowChoice.Broadcast();
}