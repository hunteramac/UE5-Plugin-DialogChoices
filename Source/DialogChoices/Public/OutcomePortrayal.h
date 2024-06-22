// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OutcomePortrayal.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGCHOICES_API UOutcomePortrayal : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void ShowOutcome(FText outcome);
};
