#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ChoiceUIGameInstanceSubsystem.generated.h"

DECLARE_DELEGATE_OneParam(FCommonMessagingResultDelegate, int /* Result */);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShowChoicesDelegateRelay);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShowOutcomeDelegateRelay);

/**
 *
 */
UCLASS()
class DIALOGCHOICES_API UChoiceUIGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UChoiceUIGameInstanceSubsystem() { }

	UFUNCTION(BlueprintCallable)
	void UIUserChoice(int Choice);

	virtual void ShowConfirmation(TArray<FText> Actions, FCommonMessagingResultDelegate ResultCallback = FCommonMessagingResultDelegate());

	UPROPERTY(BlueprintReadWrite)
	bool testAccessible;

	//Display Actions to Choose Handling
	UPROPERTY(BlueprintReadOnly)
	TArray<FText> DisplayActions;

	UPROPERTY(BlueprintAssignable)
	FShowChoicesDelegateRelay OnSubsystemShowChoice;

	UFUNCTION(BlueprintCallable)
	void SubsystemShowChoice();


	// Display Outcome Handling
	UPROPERTY(BlueprintReadWrite)
	FText Outcome;

	UPROPERTY(BlueprintAssignable)
	FShowOutcomeDelegateRelay OnSubsystemShowOutcome;

	UFUNCTION(BlueprintCallable)
	void SubsystemShowOutcome();

	UFUNCTION(BlueprintCallable)
	void SetInactionDelays(bool state);

	UPROPERTY(BlueprintReadOnly);
	bool InactionContinueDelay;

private:
	FCommonMessagingResultDelegate OnResultCallback;
};
