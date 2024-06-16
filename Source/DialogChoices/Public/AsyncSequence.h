#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"

#include "MovieSceneSequencePlayer.h"
#include "LevelSequencePlayer.h"
#include "LevelSequence.h"

#include "UObject/ObjectPtr.h"

#include "AsyncSequence.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSequenceMCDelegate);

/**
 *
 */
UCLASS()
class DIALOGCHOICES_API UAsyncSequence : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UAsyncSequence* PlayLevelSequence(
		UObject* InWorldContextObject,
		ULevelSequence* Sequence
	);

	virtual void Activate() override;
public:
	UPROPERTY(BlueprintAssignable)
	FSequenceMCDelegate Completion;

private:
	UFUNCTION()
	void HandleSequenceCompletion();

	UPROPERTY(Transient)
	TObjectPtr<UObject> WorldContextObject;

	UPROPERTY()
	ULevelSequence* Sequence;

	UPROPERTY()
	ALevelSequenceActor* OutActor;
};
