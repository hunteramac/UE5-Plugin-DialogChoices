#include "AsyncChoice.h"

#include "Kismet/GameplayStatics.h"

#include "Engine/GameInstance.h"
#include "ChoiceUIGameInstanceSubsystem.h"

UAsyncChoice::UAsyncChoice(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UAsyncChoice* UAsyncChoice::WaitForChoice(UObject* InWorldContextObject, TArray<FText> Actions)
{
	UAsyncChoice* Choices = NewObject<UAsyncChoice>();
	Choices->WorldContextObject = InWorldContextObject;
	Choices->Actions = Actions;

	return Choices;
}

void UAsyncChoice::Activate()
{
	//get world context
	UWorld* World = WorldContextObject->GetWorld();

	//use context to get game instance
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(World);

	//use game instance to get our communication subsystem
	if (UChoiceUIGameInstanceSubsystem* MySubsystem = GameInstance->GetSubsystem<UChoiceUIGameInstanceSubsystem>()) {
		//setup callback function for UI
		FCommonMessagingResultDelegate ResultCallback = FCommonMessagingResultDelegate::CreateUObject(this, &UAsyncChoice::HandleConfirmationResult);

		//Pass UI, choices to be displayed(list of player actions), and the callback to have node return choice made
		MySubsystem->ShowConfirmation(Actions, ResultCallback);
		return;
	}

	//something went wrong
	HandleConfirmationResult(0);
	return;
}

void UAsyncChoice::HandleConfirmationResult(int ChoiceMade)
{
	//Only return a player choice if positive, negative signals manually termination by game instead
	if (ChoiceMade >= 0) {
		OnResult.Broadcast(ChoiceMade);
	}


	SetReadyToDestroy();
}