// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectDialogLogic.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGCHOICES_API UObjectDialogLogic : public UObject
{
	GENERATED_BODY()
public:
	UObjectDialogLogic();
	~UObjectDialogLogic();

	UFUNCTION(BlueprintCallable)
	int GetHighlightIndex();

	UFUNCTION(BlueprintCallable)
	void MoveHightlightedChoiceUp();

	UFUNCTION(BlueprintCallable)
	void MoveHightlightedChoiceDown();

	int NumChoices;

private:
	int currentHightlightedChoice;
	
};
