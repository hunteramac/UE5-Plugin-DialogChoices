#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"

#include "UObject/ObjectPtr.h"
#include "AsyncChoice.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCommonMessagingResultMCDelegate, int, choice);

/**
 *
 */
UCLASS()
class DIALOGCHOICES_API UAsyncChoice : public UBlueprintAsyncActionBase
{
	//GENERATED_BODY()
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UAsyncChoice* WaitForChoice(
		UObject* InWorldContextObject, TArray<FText> Actions
	);

	virtual void Activate() override;
public:
	UPROPERTY(BlueprintAssignable)
	FCommonMessagingResultMCDelegate OnResult;
private:
	void HandleConfirmationResult(int ChoiceMade);

	UPROPERTY(Transient)
	TObjectPtr<UObject> WorldContextObject;

	UPROPERTY()
	TArray<FText> Actions;
};
