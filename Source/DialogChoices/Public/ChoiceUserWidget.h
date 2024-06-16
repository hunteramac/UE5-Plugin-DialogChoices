// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectDialogLogic.h"

#include "ChoiceUserWidget.generated.h"


/**
 * 
 */
UCLASS()
class DIALOGCHOICES_API UChoiceUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite)
	UObjectDialogLogic* UILogic;
};
